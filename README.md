# modbusCamera

使用Modbus TCP信号控制华睿工业相机采图，进行防伪检测和检测结果返回PLC。（QT框架+NCNN推理+Modbus通信）



# 起

需求是写代码的第一生产力，该仓库的创建是基于一个预研的项目。项目的具体需求是：检测客户使用样品上的条码是否符合生产厂家喷码时设定的规则，如果检测出样品条码不符合既定规则，则返回NG信号，如果检测出样品上的条码符合规则，则返回OK信号。后续再根据检测出的信号，对样品做出相应处理。（样品防伪检测）

设想的实现步骤为：在下位机(PLC)和上位机(工业相机)之间通过Modbus TCP建立通信，通过读特定寄存器地址上的数值来判定是否让工业相机进行采图和防伪检测，同时通过写特定寄存器地址上的数值来让PLC知道样品的真伪。

本仓库完成以下功能：

1. 与下位机（PLC)建立Modbus TCP通信，不间断地读取特定寄存器地址上的数值，通过该数值判断是否让工业相机进行拍照检测动作；（借助QT的Modbus库，建立TCP通信，使用"Modbus Slave"软件模拟PLC发送和接收信号）
2. 工业相机根据拍照信号，获取当前待检测样品图像；（熟悉华睿工业相机的sdk，进行二次开发，完成图像的采集）
3. 对待检测样品上的条码进行识别，通过设定规则判断识别的条码是否符合规范；(通过PaddleOCR4 进行条码字符识别，设定字符判定规则判定检测字符的真伪)
4. 将检测结果通过写特定寄存器地址上数值的方式，将检测结果传送给下位机(PLC)，完成整个检测流程；（在QT中使用Modbus TCP库写寄存器）
5. 设计一个可视化UI界面，通过按钮操作进行是否检测判定，同时可视化检测结果；(使用QT Create搭建整个项目，QT Designer绘制UI界面)



# 承

本仓库测试使用的软硬件：

- 硬件

  -华睿工业相机（型号:CE27743AAK00165) 

- 软件和库

  -Modbus Slave (用于模拟PLC，手头上没有)

  -Qt5.14.2 (MSVC 2017 64bit)

  -opencv-3.4.10 

  -ncnn-20240820-full-source

本仓库最核心的设计算法逻辑为[modbuscamera.h](https://github.com/zhahoi/modbusCamera/blob/main/modbuscamera.h)和[modbuscamera.cpp](https://github.com/zhahoi/modbusCamera/blob/main/modbuscamera.cpp)，其他的.cpp和.h均为OCR识别和检测规则判定代码。



# 转

本仓库设计的UI界面如下：

[![pA4shgs.jpg](https://s21.ax1x.com/2024/11/27/pA4shgs.jpg)](https://imgse.com/i/pA4shgs)

当Modbus Slave中未设置拍照信号时，UI界面不会显示当前相机拍照的结果。

[![pA4s4vn.jpg](https://s21.ax1x.com/2024/11/27/pA4s4vn.jpg)](https://imgse.com/i/pA4s4vn)

当Modbus Slave中设置拍照信号时，UI界面会显示当前相机拍摄的图像，同时给出检测结果。Modbus Slave100位上的数字为返回给PLC的信号，数字为0表示未检测到字符，检测结果框内的⚪为黑白。

[![pA4sIuq.jpg](https://s21.ax1x.com/2024/11/27/pA4sIuq.jpg)](https://imgse.com/i/pA4sIuq)

Modbus Slave100位上的数字为1，则表示当前防伪检测OK，检测结果框内的⚪会变绿。

[![pA4sTbV.jpg](https://s21.ax1x.com/2024/11/27/pA4sTbV.jpg)](https://imgse.com/i/pA4sTbV)

Modbus Slave100位上的数字为2，则表示当前防伪检测NG，检测结果框内的⚪会变红。

[![pA4soD0.jpg](https://s21.ax1x.com/2024/11/27/pA4soD0.jpg)](https://imgse.com/i/pA4soD0)

注：按“停止检测”按钮之后再按“开始检测”按钮，可以继续检测流程。



# 合

本仓库的代码花费了我近一个月的时间，包括学习ModBus通信，如何使用QT和设计QT界面，如何对华睿工业相机SDK进行二次开发，如何使用ncnn框架部署Paddle OCR4字符检测算法和设定检测规则等，期间踩了很多很多的坑，也受益良多。十分感谢chatgpt，如果没有gpt以我现在的水平可能一年的时间也没办法把该仓库的demo弄出来。

编写本仓库代码时也参考了一些github仓库，十分感谢他们开源的代码给我的实现带来了很多灵感，这里列出：

-[Defect-detection](https://github.com/fengzi666666/Defect-detection)

-[ncnn_paddleocrv4](https://github.com/XdpAreKid/ncnn_paddleocrv4)

以上。
