#include <QtGui/QApplication>
#include "mainwindow.h"
#include "x3dumlqt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    X3DUMLQT viewer;
    //viewer.show();
    return a.exec();
}
