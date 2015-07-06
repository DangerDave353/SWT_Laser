#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "control.h"
#include <iostream>
#include <QPen>
#include <QString>
#include <QLineEdit>

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
    if(LaserZustand)
    {
    cout<<"Linie von "<<AltX<<"/"<<AltY<<" nach "<<NeuX<<"/"<<NeuY<<" gezeichnet"<<endl;
//ui->graphicsView->scene()->addLine(AltX,AltY,NeuX,NeuY,pen);
    }
    AltX=NeuX;
    AltY=NeuY;
}

void MainWindow::GuiSetProgressBar(int max)
{
    ui->progressBar->setMaximum(max);
    ui->progressBar->setValue(0);

}

void MainWindow::GuiAddProgressBar()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
}
void MainWindow::setC(Control *value)
{
    C = value;
}

void MainWindow::Start()
{
    cout<<"Start gedrückt"<<endl;
 QString Pfad;
 Pfad=ui->Eingabe->text();
 cout<<"Pfad = "<<Pfad.toStdString()<<endl;
 C->StartControl(Pfad.toStdString());

}
