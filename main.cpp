#include "mainwindow.h"
#include <QApplication>
#include "control.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w = MainWindow::MainWindow();
    w.show();
    Control C = Control(w.getUi());

    C.StartControl();

    return a.exec();

}
