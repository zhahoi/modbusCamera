#include "modbuscamera.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    modbusCamera w;
    w.show();
    return a.exec();
}
