#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->cmd_Auswahl,SIGNAL(clicked(bool)),SLOT(Auswahl()));
    connect(ui->cmd_Start,SIGNAL(clicked(bool)),SLOT(Start()));
    setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}


void MainWindow::Start()
{
    cout<<"Start gedrückt"<<endl;

}

void MainWindow::Auswahl()
{
    cout<<"Auswahl gedrückt"<<endl;

}

void MainWindow::GuiLaserAN()
{
    ui->cmd_Laser->setStyleSheet("QPushButton {background-color: green}");
}

void MainWindow::GuiLaserAUS()
{
ui->cmd_Laser->setStyleSheet("QPushButton {background-color: red}");
}

void MainWindow::GuiMove(bool LaserZustand, int x, int y)
{
    NeuX=x;
    NeuY=y;
}

void MainWindow::GuiSetProgressBar(int max)
{
    ui->progressBar->setMaximum(max);
}



