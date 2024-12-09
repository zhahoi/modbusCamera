/********************************************************************************
** Form generated from reading UI file 'modbuscamera.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUSCAMERA_H
#define UI_MODBUSCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modbusCamera
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QPushButton *connect_modbus;
    QPushButton *disconnect_modbus;
    QGroupBox *groupBox;
    QHBoxLayout *hboxLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *ip_label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *ip;
    QSpacerItem *horizontalSpacer;
    QLabel *port_label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *port;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout1;
    QLabel *image_label;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox_5;
    QVBoxLayout *vboxLayout2;
    QLabel *det_image_label;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *vboxLayout3;
    QLabel *light_label;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *modbusCamera)
    {
        if (modbusCamera->objectName().isEmpty())
            modbusCamera->setObjectName(QString::fromUtf8("modbusCamera"));
        modbusCamera->resize(1226, 728);
        centralwidget = new QWidget(modbusCamera);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_8->addWidget(label);


        mainLayout->addLayout(verticalLayout_8);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        vboxLayout = new QVBoxLayout(groupBox_2);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        connect_modbus = new QPushButton(groupBox_2);
        connect_modbus->setObjectName(QString::fromUtf8("connect_modbus"));

        horizontalLayout_2->addWidget(connect_modbus);

        disconnect_modbus = new QPushButton(groupBox_2);
        disconnect_modbus->setObjectName(QString::fromUtf8("disconnect_modbus"));

        horizontalLayout_2->addWidget(disconnect_modbus);


        vboxLayout->addLayout(horizontalLayout_2);


        mainLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        hboxLayout = new QHBoxLayout(groupBox);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ip_label = new QLabel(groupBox);
        ip_label->setObjectName(QString::fromUtf8("ip_label"));

        horizontalLayout->addWidget(ip_label);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        ip = new QLineEdit(groupBox);
        ip->setObjectName(QString::fromUtf8("ip"));

        horizontalLayout->addWidget(ip);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        port_label = new QLabel(groupBox);
        port_label->setObjectName(QString::fromUtf8("port_label"));

        horizontalLayout->addWidget(port_label);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        port = new QLineEdit(groupBox);
        port->setObjectName(QString::fromUtf8("port"));

        horizontalLayout->addWidget(port);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        hboxLayout->addLayout(horizontalLayout);


        mainLayout->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout1 = new QVBoxLayout(groupBox_3);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        image_label = new QLabel(groupBox_3);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(image_label->sizePolicy().hasHeightForWidth());
        image_label->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(image_label);

        horizontalSpacer_5 = new QSpacerItem(800, 5, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        vboxLayout1->addItem(horizontalSpacer_5);


        horizontalLayout_3->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        vboxLayout2 = new QVBoxLayout(groupBox_5);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        det_image_label = new QLabel(groupBox_5);
        det_image_label->setObjectName(QString::fromUtf8("det_image_label"));
        sizePolicy1.setHeightForWidth(det_image_label->sizePolicy().hasHeightForWidth());
        det_image_label->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(det_image_label);

        horizontalSpacer_6 = new QSpacerItem(800, 5, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        vboxLayout2->addItem(horizontalSpacer_6);


        horizontalLayout_3->addWidget(groupBox_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        vboxLayout3 = new QVBoxLayout(groupBox_4);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        light_label = new QLabel(groupBox_4);
        light_label->setObjectName(QString::fromUtf8("light_label"));

        vboxLayout3->addWidget(light_label);


        horizontalLayout_4->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_4->addItem(verticalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout);


        mainLayout->addLayout(horizontalLayout_3);

        modbusCamera->setCentralWidget(centralwidget);
        menubar = new QMenuBar(modbusCamera);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1226, 26));
        modbusCamera->setMenuBar(menubar);
        statusbar = new QStatusBar(modbusCamera);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        modbusCamera->setStatusBar(statusbar);

        retranslateUi(modbusCamera);

        QMetaObject::connectSlotsByName(modbusCamera);
    } // setupUi

    void retranslateUi(QMainWindow *modbusCamera)
    {
        modbusCamera->setWindowTitle(QCoreApplication::translate("modbusCamera", "modbusCamera", nullptr));
        label->setText(QCoreApplication::translate("modbusCamera", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">\346\240\267\345\223\201\347\223\266\351\230\262\344\274\252\346\243\200\346\265\213\347\263\273\347\273\237</span></p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("modbusCamera", "\347\233\270\346\234\272\350\277\236\346\216\245", nullptr));
        connect_modbus->setText(QCoreApplication::translate("modbusCamera", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
        disconnect_modbus->setText(QCoreApplication::translate("modbusCamera", "\345\201\234\346\255\242\346\243\200\346\265\213", nullptr));
        groupBox->setTitle(QCoreApplication::translate("modbusCamera", "Modbus\350\256\276\347\275\256", nullptr));
        ip_label->setText(QCoreApplication::translate("modbusCamera", "IP:", nullptr));
        ip->setText(QCoreApplication::translate("modbusCamera", "127.0.0.1", nullptr));
        ip->setPlaceholderText(QCoreApplication::translate("modbusCamera", "127.0.0.1", nullptr));
        port_label->setText(QCoreApplication::translate("modbusCamera", "Port:", nullptr));
        port->setText(QCoreApplication::translate("modbusCamera", "502", nullptr));
        port->setPlaceholderText(QCoreApplication::translate("modbusCamera", "502", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("modbusCamera", "\345\256\236\346\227\266\345\233\276\345\203\217", nullptr));
        image_label->setText(QCoreApplication::translate("modbusCamera", "image", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("modbusCamera", "\346\243\200\346\265\213\345\233\276\345\203\217", nullptr));
        det_image_label->setText(QCoreApplication::translate("modbusCamera", "det_image", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("modbusCamera", "\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
        light_label->setText(QCoreApplication::translate("modbusCamera", "detect_result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modbusCamera: public Ui_modbusCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSCAMERA_H
