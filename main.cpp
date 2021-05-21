#include "mainwindow.h"

#include <QApplication>
#include <QSurfaceFormat>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setFixedSize(1920,1080);
    w.setWindowTitle("Billiard");
    w.show();
    return a.exec();
}
