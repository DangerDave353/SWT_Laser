#include "mainwindow.h"
#include <QApplication>
#include "control.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //MainWindow *W=&w;
    w.show();
    Control C = Control(&w);


    return a.exec();

}
