QT       += core gui serialbus network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# HuaRayCamera SDK
LIBS += -LDepends/x64/vs2013shared				-lMVSDKmd
LIBS += -LDepends/x64/vs2013shared				-lVideoRender
DESTDIR = Bin/x64
INCLUDEPATH += Include


# 配置OPENCV环境
INCLUDEPATH += C:/NCNN/opencv-3.4.10/opencv/build/include \
               C:/NCNN/opencv-3.4.10/opencv/build/include/opencv \
               C:/NCNN/opencv-3.4.10/opencv/build/include/opencv2

# 添加v15版 opencv 库文件，区分debug和release
LIBS += -LC:/NCNN/opencv-3.4.10/opencv/build/x64/vc15/lib/ -lopencv_world3410 \
        -LC:/NCNN/opencv-3.4.10/opencv/build/x64/vc15/lib/ -lopencv_world3410d

INCLUDEPATH += C:/NCNN/opencv-3.4.10/opencv/build/x64/vc15
DEPENDPATH += C:/NCNN/opencv-3.4.10/opencv/build/x64/vc15

# NCNN环境
LIBS += -LC:/NCNN/ncnn-20240820-full-source/build/install/lib -lncnn
INCLUDEPATH += C:/NCNN/ncnn-20240820-full-source/build/install/include/ncnn
DEPENDPATH += C:/NCNN/ncnn-20240820-full-source/build/install/include/ncnn

SOURCES += \
    clipper.cpp \
    crnnNet.cpp \
    dbNet.cpp \
    main.cpp \
    modbuscamera.cpp \
    ocrDetect.cpp

HEADERS += \
    baseOcr.h \
    baseStruct.h \
    boxSorter.h \
    clipper.hpp \
    crnnNet.h \
    dbNet.h \
    modbuscamera.h \
    ocrDetect.h \
    tools.h

FORMS += \
    modbuscamera.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc


