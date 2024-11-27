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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modbusCamera
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QPushButton *connect_modbus;
    QPushButton *disconnect_modbus;
    QComboBox *comboBox;
    QGroupBox *groupBox_3;
    QLabel *image_label;
    QGroupBox *groupBox;
    QLabel *ip_label;
    QLabel *port_label;
    QLineEdit *ip;
    QLineEdit *port;
    QGroupBox *groupBox_4;
    QLabel *light_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *modbusCamera)
    {
        if (modbusCamera->objectName().isEmpty())
            modbusCamera->setObjectName(QString::fromUtf8("modbusCamera"));
        modbusCamera->resize(952, 728);
        centralwidget = new QWidget(modbusCamera);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(710, 190, 231, 481));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(710, 20, 231, 161));
        connect_modbus = new QPushButton(groupBox_2);
        connect_modbus->setObjectName(QString::fromUtf8("connect_modbus"));
        connect_modbus->setGeometry(QRect(10, 70, 211, 31));
        disconnect_modbus = new QPushButton(groupBox_2);
        disconnect_modbus->setObjectName(QString::fromUtf8("disconnect_modbus"));
        disconnect_modbus->setGeometry(QRect(10, 120, 211, 31));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 20, 211, 31));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 691, 561));
        image_label = new QLabel(groupBox_3);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setGeometry(QRect(10, 30, 661, 511));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 610, 511, 61));
        ip_label = new QLabel(groupBox);
        ip_label->setObjectName(QString::fromUtf8("ip_label"));
        ip_label->setGeometry(QRect(10, 30, 51, 21));
        port_label = new QLabel(groupBox);
        port_label->setObjectName(QString::fromUtf8("port_label"));
        port_label->setGeometry(QRect(290, 30, 54, 21));
        ip = new QLineEdit(groupBox);
        ip->setObjectName(QString::fromUtf8("ip"));
        ip->setGeometry(QRect(60, 20, 141, 31));
        port = new QLineEdit(groupBox);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(340, 20, 141, 31));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(580, 580, 91, 91));
        light_label = new QLabel(groupBox_4);
        light_label->setObjectName(QString::fromUtf8("light_label"));
        light_label->setGeometry(QRect(10, 20, 71, 61));
        modbusCamera->setCentralWidget(centralwidget);
        menubar = new QMenuBar(modbusCamera);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 952, 26));
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
        groupBox_2->setTitle(QCoreApplication::translate("modbusCamera", "\347\233\270\346\234\272\350\277\236\346\216\245", nullptr));
        connect_modbus->setText(QCoreApplication::translate("modbusCamera", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
        disconnect_modbus->setText(QCoreApplication::translate("modbusCamera", "\345\201\234\346\255\242\346\243\200\346\265\213", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("modbusCamera", "\346\243\200\346\265\213\345\233\276\345\203\217", nullptr));
        image_label->setText(QCoreApplication::translate("modbusCamera", "image", nullptr));
        groupBox->setTitle(QCoreApplication::translate("modbusCamera", "Modbus\350\256\276\347\275\256", nullptr));
        ip_label->setText(QCoreApplication::translate("modbusCamera", "<html><head/><body><p align=\"center\">IP:</p></body></html>", nullptr));
        port_label->setText(QCoreApplication::translate("modbusCamera", "<html><head/><body><p align=\"center\">Port:</p></body></html>", nullptr));
        ip->setText(QCoreApplication::translate("modbusCamera", "127.0.0.1", nullptr));
        ip->setPlaceholderText(QString());
        port->setText(QCoreApplication::translate("modbusCamera", "502", nullptr));
        port->setPlaceholderText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("modbusCamera", "\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
        light_label->setText(QCoreApplication::translate("modbusCamera", "detect_result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modbusCamera: public Ui_modbusCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSCAMERA_H
