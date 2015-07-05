#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPen>

using namespace std;

static QPen pen(Qt::black,4,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);

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
     ui->progressBar->setValue(ui->progressBar->value()+1);
     AltX=0;
     AltY=0;
     NeuY=10;
     NeuX=10;
cout<<"vor dem Malen"<<endl;

     ui->graphicsView->scene()->addLine(1,1,1,10,pen);

cout<<"nach dem malen"<<endl;
}

void MainWindow::Auswahl()
{
    cout<<"Auswahl gedrückt"<<endl;
     ui->progressBar->setValue(ui->progressBar->value()-1);

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
    if(LaserZustand)
    {
        //GUI zeichnen
ui->graphicsView->scene()->addLine(AltX,AltY,NeuX,NeuY,pen);
    }
    AltX=NeuX;
    AltY=NeuY;
}

void MainWindow::GuiSetProgressBar(int max)
{
    ui->progressBar->setMaximum(max);
}

void MainWindow::GuiAddProgressBar()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
}



