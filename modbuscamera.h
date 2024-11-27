#ifndef MODBUSCAMERA_H
#define MODBUSCAMERA_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QList>
#include <QThread>

#include <QMutex>
#include <QWaitCondition>

#include <QImage>
#include <QSize>
#include <QPixmap>

#include <QModbusTcpClient>
#include <QModbusDataUnit>
#include <QModbusReply>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <process.h>
#include <IMVAPI/IMVApi.h>

#include "ocrDetect.h"

#define OREGS_READ_ADDR_START  100
#define OREGS_READ_LEN         2
#define OREGS_WRITE_ADDR_START 100
#define OREGS_WRITE_LEN        1
#define SLAVE_ID               1


QT_BEGIN_NAMESPACE
namespace Ui { class modbusCamera; }
QT_END_NAMESPACE

class modbusCamera : public QMainWindow
{
    Q_OBJECT

public:
    modbusCamera(QWidget *parent = nullptr);
    ~modbusCamera();

    void sendRegistorsData();  // 发送寄存器数据

private:
    IMV_DeviceList m_deviceInfoList;  // 发现的相机列表 | List of cameras found
    IMV_HANDLE devHandle;
    HANDLE threadHandle;

    int cameraIndex = 0;

    // 用于线程控制的静态成员
    static bool g_isExitThread;  // 控制线程退出
    static modbusCamera* instance;  // 保存类的实例指针，用于在静态函数中访问 ui
    static bool g_captureSignal;  // 外部信号

    static int send_index;  // 静态成员变量
    static unsigned __stdcall frameGrabbingProc(void* pUserData);

signals:
    void updateTextEdit(const QString &message);
    void sendRegistorsDataSignal();  // 新增信号，通知主线程执行 sendRegistorsData
    void displayImage(const QImage& image);
    void displayDetectResult(int ret_code);

private slots:
    void on_connect_modbus_clicked();
    void on_disconnect_modbus_clicked();

    void readRegistersData();
    void replyRegistersData();

    void onSendRegistorsDataSlot();  // 槽函数，用于接收信号并执行 sendRegistorsData
    void updateImageDisplay(const QImage& image);
    void updateDetectResultDisplay(int ret_code);

    void on_modbus_stateChanged(QModbusDevice::State state);
    void on_modbus_errorOccurred(QModbusDevice::Error error);

    void on_connectionTimeout();

    void on_comboBox_activated(int index);  // 选择相机id

    void loadCameraList();

private:
    QImage cvMatToQImage(const cv::Mat& inMat);
    void frameToCVImage(const IMV_Frame& pFrame, cv::Mat& image);

private:
    Ui::modbusCamera *ui;
    QTimer* timer;  // 用于读取寄存器
    QModbusTcpClient *client;

    ocrDetect ocrDet;
};
#endif // MODBUSCAMERA_H
