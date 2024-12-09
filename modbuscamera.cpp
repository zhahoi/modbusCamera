#include "modbuscamera.h"
#include "ui_modbuscamera.h"

bool modbusCamera::g_captureSignal = false;
bool modbusCamera::g_isExitThread = false;  // 控制线程退出
modbusCamera* modbusCamera::instance = nullptr;  // 初始化静态实例指针
int modbusCamera::send_index = 0;
int modbusCamera::count_ok = 0;

modbusCamera::modbusCamera(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::modbusCamera)
    , client(new QModbusTcpClient(this))
    , timer(new QTimer(this))
    , threadHandle(nullptr)
    , devHandle(nullptr)
{
    ui->setupUi(this);
    instance = this;   // 将当前类实例保存为静态实例

    // 确保连接信号与槽
    connect(this, &modbusCamera::updateTextEdit, ui->textEdit, &QTextEdit::append);
    connect(this, &modbusCamera::sendRegistorsDataSignal, this, &modbusCamera::onSendRegistorsDataSlot);  // 连接信号与槽
    connect(this, &modbusCamera::displayImage, this, &modbusCamera::updateImageDisplay);
    connect(this, &modbusCamera::displayDetectResult, this, &modbusCamera::updateDetectResultDisplay);
    connect(this, &modbusCamera::displayDetectImage, this, &modbusCamera::updateDetectImageDisplay);

    // 初始化寄存器
    connect(timer, &QTimer::timeout, this, &modbusCamera::readRegistersData);

    // 启动定时器，每间隔100ms读取一次寄存器
    timer->start(100);

    // 在构造函数中加载相机列表
    loadCameraList();
}

modbusCamera::~modbusCamera()
{
    // 停止相机采集和释放资源
    g_isExitThread = true;
    if (threadHandle != nullptr)
    {
        WaitForSingleObject(threadHandle, INFINITE);
        CloseHandle(threadHandle);
        threadHandle = nullptr;
    }
    if (devHandle != nullptr)
    {
        IMV_StopGrabbing(devHandle);
        IMV_Close(devHandle);
        IMV_DestroyHandle(devHandle);
        devHandle = nullptr;
    }

    // 删除UI资源
    delete ui;
}

// 枚举设备并加载到 ComboBox
void modbusCamera::loadCameraList()
{
    int ret = IMV_OK;
    ret = IMV_EnumDevices(&m_deviceInfoList, interfaceTypeAll);
    if (IMV_OK != ret)
    {
        ui->textEdit->append("Enumeration devices failed! ErrorCode[%d]\n");
        return;
    }

    // 清空现有的列表
    ui->comboBox->clear();

    // 将所有设备添加到 ComboBox
    for (unsigned int i = 0; i < m_deviceInfoList.nDevNum; ++i)
    {
        ui->comboBox->addItem(m_deviceInfoList.pDevInfo[i].cameraKey);  // 将相机名称添加到下拉列表中
    }
}

void modbusCamera::onSendRegistorsDataSlot()
{
    sendRegistorsData();  // 在主线程中执行 sendRegistorsData
}


void modbusCamera::readRegistersData()
{
    if (client->state() != QModbusDevice::ConnectedState)
    {
        ui->textEdit->append(QString("modbus is not connected"));
        return;
    }

    QModbusDataUnit readDataUnit;
    readDataUnit.setRegisterType(QModbusDataUnit::HoldingRegisters);
    readDataUnit.setStartAddress(OREGS_READ_ADDR_START);
    readDataUnit.setValueCount(OREGS_READ_LEN);

    QModbusReply* reply = client->sendReadRequest(readDataUnit, SLAVE_ID);

    if(reply)
    {
         if(!reply->isFinished())
         {
            connect(reply, &QModbusReply::finished, this, &modbusCamera::replyRegistersData); //异步处理槽函数
            return;
         }
         reply->deleteLater(); // 针对广播消息
    }
}

void modbusCamera::sendRegistorsData()
{
    if (client->state() != QModbusDevice::ConnectedState)
    {
        // 使用信号通知主线程更新 UI
        ui->textEdit->append(QString("Modbus is not connected"));
        return;
    }

    QModbusDataUnit writeDataUnit;

    writeDataUnit.setRegisterType(QModbusDataUnit::HoldingRegisters);
    writeDataUnit.setStartAddress(OREGS_WRITE_ADDR_START);
    writeDataUnit.setValueCount(OREGS_WRITE_LEN);

    QVector<quint16> values;
    values.append(send_index);
    writeDataUnit.setValues(values);

    QModbusReply* reply = client->sendWriteRequest(writeDataUnit, SLAVE_ID);

    if (reply)
    {
        // 连接 reply 的 finished 信号到 onModbusReplyFinished 槽
        reply->deleteLater();
    }
    else
    {
        // 如果没有成功创建 reply，更新 UI 显示错误信息
        emit updateTextEdit("Failed to send Modbus write request.");
    }
}

void modbusCamera::replyRegistersData()
{
    QModbusReply* reply = (QModbusReply*)(sender());
    if (reply)
    {
        QModbusDataUnit unit = reply->result();  // 提取reply数据
        reply->deleteLater(); // 释放内存

        if(unit.valueCount() > 0)
        {
            QVector<quint16> data = unit.values();
            // 将外部触发信号修改为true
            if (data[1] == 1)
            {
                g_captureSignal = true;
                ui->textEdit->append("Trigger capture signal received!");
            }
            else
            {
                g_captureSignal = false;
                count_ok = 0;  // 将count_ok置0,为检测做准备
            }

            QString s;
            Q_FOREACH(quint16 i, data)
            {
                s.append(QString::number(i)).append(" "); // 把所有值放到一个字符串中
            }
            ui->textEdit->append(s);
        }
    }
}

unsigned __stdcall modbusCamera::frameGrabbingProc(void* pUserData)
{
    int ret = IMV_OK;
    IMV_HANDLE devHandle = (IMV_HANDLE)pUserData;
    IMV_Frame frame;

    if (NULL == devHandle)
    {
        emit instance->updateTextEdit("Invalid device handle.");
        return 0;
    }

    while (!g_isExitThread)
    {
        ret = IMV_GetFrame(devHandle, &frame, 100);
        if (IMV_OK != ret)
        {
            qDebug() << "Get frame failed! ErrorCode[" << ret << "]";
            continue;
        }

        cv::Mat image;
        instance->frameToCVImage(frame, image);

        // 如果没发送检测信号，只将相机拍照的结果显示在UI上
        if (!g_captureSignal)
        {
            // 将OpenCV图像转化为QImage，并通过信号传递给主线程
            QImage qImage = instance->cvMatToQImage(image);
            qDebug() << "Emitting displayImage signal...";
            emit instance->displayImage(qImage);   // 发送信号，通知主线程更新UI
        }
        else  // 接收到检测信号
        {
            // 进行检测(0:表示未检测到字符(初始状态),1:表示检测到两行字符并且验证OK，2:表示检测到两行字符并且验证NG，或未检测到两行字符(一行或多于两行））
            int ret_code = instance->ocrDet.getDetectResult(image);
            // 将OpenCV图像转化为QImage，并通过信号传递给主线程
            QImage qImage = instance->cvMatToQImage(image);
            qDebug() << "Emitting displayImage signal...";
            emit instance->displayImage(qImage);   // 发送信号，通知主线程更新UI
            emit instance->displayDetectResult(ret_code);  // 发送检测结果

            // 根据ret_code判断展示是否向PLC输出结果
            send_index = ret_code;
            if (send_index == 1)
            {
                count_ok += 1; // 用于统计当前样品瓶检测时,检测出OK的次数
            }

            emit instance->updateTextEdit("count_ok: " + QString::number(count_ok) + " send_index: " + QString::number(send_index));
            // 用于判断是否发送结果到PLC(当只检测到NG图像时，更新图像发信号，当第一次检测到OK图像时,更新图像发信号
            if (((count_ok == 0) && (send_index == 2)) || ((count_ok == 1) && (send_index == 1)))
            {
                emit instance->displayDetectImage(qImage);  // 发送检测OK/NG结果
                emit instance->sendRegistorsDataSignal();   // 发送信号，通知主线程执行
            }

            // 将信号置为false
            g_captureSignal = false;
        }

        ret = IMV_ReleaseFrame(devHandle, &frame);
        if (IMV_OK != ret)
        {
            emit instance->updateTextEdit("Release frame failed!");
        }

        QThread::msleep(10);
    }
    return 0;
}


void modbusCamera::on_connect_modbus_clicked()
{
    // 确保用户已经选择了相机
    if (ui->comboBox->currentIndex() == -1) {
        QMessageBox::critical(this, "No Camera Selected", "Please select a camera before connecting.");
        return;  // 如果没有选择相机，弹出警告并返回
    }

    QString ip = ui->ip->text();
    QString port = ui->port->text();

    ui->textEdit->append("IP: " + ip + ", Port: " + port);

    // 在尝试连接之前，先重置连接状态
    client->disconnectDevice();  // 确保先断开任何现有的连接

    // 设置连接参数
    client->setConnectionParameter(QModbusDevice::NetworkAddressParameter, ip);  // IP
    client->setConnectionParameter(QModbusDevice::NetworkPortParameter, port);    // 端口
    client->setTimeout(500);
    client->setNumberOfRetries(3);

    // 启动定时器来检查连接状态
    QTimer* timer = new QTimer(this);
    timer->setSingleShot(true);  // 确保只检查一次
    connect(timer, &QTimer::timeout, this, &modbusCamera::on_connectionTimeout);
    timer->start(100);  // 定时检查，每100ms检查一次

    // 连接设备
    bool connected = client->connectDevice();

    if (!connected)
    {
        ui->textEdit->append("Connection failed immediately. Please confirm IP and port.");
        qDebug() << "Modbus Client state immediately after connect attempt:" << client->state();
        QMessageBox::critical(this, "Connection Failed", "Connection failed immediately. Please confirm IP and port are correct.");
        return;
    }

    // 断开之前的连接，防止重复连接
    disconnect(client, &QModbusDevice::stateChanged, this, &modbusCamera::on_modbus_stateChanged);
    disconnect(client, &QModbusClient::errorOccurred, this, &modbusCamera::on_modbus_errorOccurred);

    // 连接成功后，等待异步信号处理
    connect(client, &QModbusDevice::stateChanged, this, &modbusCamera::on_modbus_stateChanged);
    connect(client, &QModbusClient::errorOccurred, this, &modbusCamera::on_modbus_errorOccurred);
}



void modbusCamera::on_modbus_stateChanged(QModbusDevice::State state)
{
    // 打印当前连接状态
    qDebug() << "Modbus Client state changed:" << state;

    if (state == QModbusDevice::ConnectedState)
    {
        ui->textEdit->append("Connection successful");

        // 释放之前的资源，重新初始化相机
        if (devHandle != nullptr)
        {
            IMV_StopGrabbing(devHandle);
            IMV_Close(devHandle);
            IMV_DestroyHandle(devHandle);
            devHandle = nullptr;
        }

        // 初始化相机
        int ret = IMV_OK;
        ret = IMV_EnumDevices(&m_deviceInfoList, interfaceTypeAll);
        if (IMV_OK != ret)
        {
            ui->textEdit->append("Enumeration devices failed! ErrorCode[%d]\n");
            return;
        }

        // 创建句柄
        ret = IMV_CreateHandle(&devHandle, modeByIndex, (void*)&cameraIndex);
        if (IMV_OK != ret)
        {
            ui->textEdit->append("Create devHandle failed!");
            QMessageBox::critical(this, "Create devHandle Failed", "Unable to create the devHandle.");
            return;
        }

        // 打开相机
        ret = IMV_Open(devHandle);
        if (IMV_OK != ret)
        {
            ui->textEdit->append("Failed to open camera.");
            QMessageBox::critical(this, "Camera Open Failed", "Unable to open the camera.");
            return;
        }

        // 开始拉流
        ret = IMV_StartGrabbing(devHandle);
        if (IMV_OK != ret)
        {
            ui->textEdit->append("Failed to start image grabbing.");
            QMessageBox::critical(this, "Image Grabbing Failed", "Unable to start grabbing images.");
            return;
        }

        // 确保线程能够重新启动
        if (threadHandle != nullptr)
        {
            g_isExitThread = true;   // 确保上个线程退出
            WaitForSingleObject(threadHandle, INFINITE);   // 等待线程结束
            CloseHandle(threadHandle);  // 关闭线程句柄
            threadHandle = nullptr;   // 清空线程句柄
        }

        // 创建新的线程
        threadHandle = (HANDLE)_beginthreadex(NULL, 0, frameGrabbingProc, (void*)devHandle, CREATE_SUSPENDED, NULL);
        if (!threadHandle)
        {
            ui->textEdit->append("Failed to create getFrame thread!");
            return;
        }

        // 启动线程
        ResumeThread(threadHandle);
        g_isExitThread = false;   // 重置线程退出标志
        ui->textEdit->append("Image capture started.");

        // 确保定时器重新启动并正确连接信号和槽
        if (timer == nullptr)
        {
            timer = new QTimer(this);
        }

        // 确保定时器的信号和槽连接
        disconnect(timer, &QTimer::timeout, this, &modbusCamera::readRegistersData); // 防止重复连接
        connect(timer, &QTimer::timeout, this, &modbusCamera::readRegistersData); // 正确连接槽

        // 启动定时器，100ms 间隔
        timer->start(100);

        ui->textEdit->append("Timer started.");

        // 将connect按钮失效
        ui->connect_modbus->setEnabled(false);
        ui->disconnect_modbus->setEnabled(true);
    }
    else if (state == QModbusDevice::UnconnectedState)
    {
        ui->textEdit->append("Connection failed or disconnected.");
        qDebug() << "Modbus Client state: Unconnected";
    }
}

void modbusCamera::on_modbus_errorOccurred(QModbusDevice::Error error)
{
    // 连接失败时的错误处理
    ui->textEdit->append("Connection failed. Error: " + QString::number(error));
    qDebug() << "Modbus Client error occurred, state:" << client->state();
    QMessageBox::critical(this, "Connection Failed", "Connection failed with error: " + QString::number(error));
}

void modbusCamera::on_disconnect_modbus_clicked()
{
    g_isExitThread = true;

    // 停止相机抓取线程
    if (threadHandle != nullptr)
    {
        WaitForSingleObject(threadHandle, INFINITE);  // 等待线程结束
        CloseHandle(threadHandle);  // 关闭线程句柄
        threadHandle = nullptr;  // 清空线程句柄
    }

    // 停止图像采集
    if (devHandle != nullptr)
    {
        IMV_StopGrabbing(devHandle);
        IMV_Close(devHandle);
        IMV_DestroyHandle(devHandle);
        devHandle = NULL;
    }

    // 将打印信息清空
    client->disconnectDevice();
    ui->textEdit->clear();
    ui->image_label->clear();
    ui->light_label->clear();
    ui->det_image_label->clear();

    // 停止定时器读取寄存器数据
    if (timer != nullptr)
    {
        timer->stop();
    }
    disconnect(timer, &QTimer::timeout, this, &modbusCamera::readRegistersData);

    // 确保设备已断开连接
    client->disconnectDevice();  // 以防在某些情况下未正确断开

    // 将disconnect按钮失效
    ui->connect_modbus->setEnabled(true);
    ui->disconnect_modbus->setEnabled(true);

    // 将count_ok置0
    count_ok = 0;
}

void modbusCamera::on_comboBox_activated(int index)
{
    cameraIndex = index;
    ui->comboBox->setCurrentIndex(index);
}

void modbusCamera::on_connectionTimeout()
{
    if (client->state() != QModbusDevice::ConnectedState)
    {
        QMessageBox::critical(this, "Connection Timeout", "Failed to connect to the Modbus device. Please check the IP and port.");
    }
}

void modbusCamera::updateImageDisplay(const QImage& image)
{
    // 在主线程中更新 QLabel 上的图像
    if (QThread::currentThread() != QCoreApplication::instance()->thread())
    {
        QMetaObject::invokeMethod(this, [this, image]{
            // ui更新操作
            ui->image_label->setPixmap(QPixmap::fromImage(image).scaled(ui->image_label->size(), Qt::KeepAspectRatio));
        });
        return;
    }

    // 如果已经在主线程，直接更新
    ui->image_label->setPixmap(QPixmap::fromImage(image).scaled(ui->image_label->size(), Qt::KeepAspectRatio));
    ui->image_label->update();
}

void modbusCamera::updateDetectResultDisplay(int ret_code)
{
    QImage image;
    QString lightPath = NULL;

    // 表示没检测到字符
    if (ret_code == 0)
    {
        lightPath = ":/res/state_gray.jpg";
    }
    // 表示字符符合规则(OK)
    else if (ret_code == 1)
    {
        lightPath = ":/res/state_green.png";
    }
    // 表示字符不符合规则(NG)
    else
    {
        lightPath = ":/res/state_red.png";
    }
    // 载入图像
    image.load(lightPath);

    // 在主线程中更新 QLabel 上的图像
    if (QThread::currentThread() != QCoreApplication::instance()->thread())
    {
        QMetaObject::invokeMethod(this, [this, image]{
            // ui更新操作
            ui->light_label->setPixmap(QPixmap::fromImage(image).scaled(ui->light_label->size(), Qt::KeepAspectRatio));
        });
        return;
    }

    // 如果已经在主线程，直接更新
    ui->light_label->setPixmap(QPixmap::fromImage(image).scaled(ui->light_label->size(), Qt::KeepAspectRatio));
    ui->light_label->update();
}

void modbusCamera::updateDetectImageDisplay(const QImage& detectImage)
{
    // 在主线程中更新显示检测图像的 QLabel
    if (QThread::currentThread() != QCoreApplication::instance()->thread())
    {
        QMetaObject::invokeMethod(this, [this, detectImage]{
            // 更新 ui 上的检测图像标签
            ui->det_image_label->setPixmap(QPixmap::fromImage(detectImage).scaled(ui->det_image_label->size(), Qt::KeepAspectRatio));
        });
        return;
    }

    // 如果已经在主线程，直接更新
    ui->det_image_label->setPixmap(QPixmap::fromImage(detectImage).scaled(ui->det_image_label->size(), Qt::KeepAspectRatio));
    ui->det_image_label->update();
}


void modbusCamera::frameToCVImage(const IMV_Frame& pFrame, cv::Mat& image)
{
    // 获取图像信息
    unsigned int width = pFrame.frameInfo.width;
    unsigned int height = pFrame.frameInfo.height;
    IMV_EPixelType pixelFormat = pFrame.frameInfo.pixelFormat;

    // 确保图像数据有效
    if (pFrame.pData == NULL)
    {
        printf("Frame data is NULL\n");
        return;
    }

    // 将图像数据转换为OPENCV的cv::Mat格式
    cv::Mat gray_image;
    switch (pixelFormat)
    {
    case gvspPixelMono8: // 假设这是8位灰度图像
        gray_image = cv::Mat(height, width, CV_8UC1, pFrame.pData);
        cv::cvtColor(gray_image, image, cv::COLOR_GRAY2BGR);
        break;
    case gvspPixelBGR8:  // 假设这是BGR图像
        image = cv::Mat(height, width, CV_8UC3, pFrame.pData);
        break;
    default:
        printf("Unsupported pixel format: %d\n", pixelFormat);
        return;
    }
}

QImage modbusCamera::cvMatToQImage(const cv::Mat& inMat)
{
    switch (inMat.type())
    {
        // 8-bit, 4 channel
        case CV_8UC4: {
            QImage image(
                inMat.data,//图像数据
                inMat.cols,//图像宽度
                inMat.rows,//图像高度
                static_cast<int>(inMat.step),//图像矩阵元素类型
                QImage::Format_ARGB32//图像的像素格式
            );
            return image;
        }

        // 8-bit, 3 channel
        case CV_8UC3: {
            QImage image(inMat.data,
                inMat.cols,
                inMat.rows,
                static_cast<int>(inMat.step),
                QImage::Format_RGB888);
            return image.rgbSwapped(); //彩色图像为RGB三通道，交换R和B通道
        }

        // 8-bit, 1 channel
        case CV_8UC1: {
            static QVector<QRgb> sColorTable;
            // 我们只需要初始化一次颜色表
            if (sColorTable.isEmpty()) {
                for (int i = 0; i < 256; ++i) {
                    sColorTable.push_back(qRgb(i, i, i));
                }
            }
            QImage image(inMat.data,
                inMat.cols,
                inMat.rows,
                static_cast<int>(inMat.step),
                QImage::Format_Indexed8);
            image.setColorTable(sColorTable);
            return image;
        }
        default:
            break;
    }
    return QImage();
}
