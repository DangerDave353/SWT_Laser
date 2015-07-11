#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "control.h"
#include <iostream>
#include <QPen>
#include <QString>
#include <QLineEdit>
#include <QTime>
#include <QFileDialog>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <fstream>

using namespace std;

static QPen pen(Qt::black,4,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);

void MainWindow::delay(double seconds)
{
    QTime dieTime=QTime::currentTime().addMSecs((int)(seconds * 1000));
    while(QTime::currentTime()<dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->cmd_Auswahl,SIGNAL(clicked(bool)),SLOT(Auswahl()));
    connect(ui->cmd_Start,SIGNAL(clicked(bool)),SLOT(Start()));
    setAutoFillBackground(true);

    ui->graphicsView->setScene(new QGraphicsScene());
    //ui->Eingabe->setText("/home/dm/Dokumente/SWT_Laser/OPCodes.txt");
    AltX=0;
    AltY=0;
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
    QString Pfad = QFileDialog::getOpenFileName(this, tr("Datei oeffnen..."),
                                                 QString(), tr("Text Dateien (*.txt);;Alle Dateien (*)"));
       // Datei laden
       if (!Pfad.isEmpty())
        ui->Eingabe->setText(Pfad);

}

void MainWindow::GuiLaserAN()
{
    ui->cmd_Laser->setStyleSheet("QPushButton {background-color: green}");

    delay(0.5);
}

void MainWindow::GuiLaserAUS()
{
ui->cmd_Laser->setStyleSheet("QPushButton {background-color: red}");

delay(0.5);
}

void MainWindow::GuiMove(bool LaserZustand, int x, int y)
{
    NeuX=x;
    NeuY=y;
    if(LaserZustand)
    {
    //cout<<"Linie von "<<AltX<<"/"<<AltY<<" nach "<<NeuX<<"/"<<NeuY<<" gezeichnet"<<endl;
    ui->graphicsView->scene()->addLine(AltX,AltY,NeuX,NeuY,pen);
    delay(0.5);
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


    AltX=0;
    AltY=0;
ui->graphicsView->scene()->clear();
ui->FehlerAusgabe->clear();
if(ui->Eingabe->text()!="")
    {
    QString Pfad;
    Pfad=ui->Eingabe->text();

    std::fstream OPCodes;
    OPCodes.open(Pfad.toStdString(), std::ios::in);
    if ( (OPCodes.rdstate() & std::ifstream::failbit ) != 0 )
        {
        ui->FehlerAusgabe->document()->setPlainText("Ihre ausgewählte Datei scheint nicht zu existieren");
        OPCodes.close();
        }
         else
        {
        OPCodes.close();
        C->StartControl(Pfad.toStdString());
        }
    }
    else
    {
        ui->FehlerAusgabe->document()->setPlainText("Sie haben noch keine Datei ausgewählt");
    }
}
void MainWindow::ResetProgressBar()
{
    ui->progressBar->setValue(0);
}
 void MainWindow::FehlerAusgabe(string Fehler)
 {
     ui->FehlerAusgabe->document()->setPlainText("Ihr Programm enthält folgende Fehler:"+QString(Fehler.c_str()));
 }
void MainWindow::SetStartButton(bool Enabled)
{
    if(Enabled)
    {ui->FehlerAusgabe->document()->setPlainText("Vorgang beendet");}
    else
    {ui->FehlerAusgabe->document()->setPlainText("Vorgang läuft");}

   ui->cmd_Start->setEnabled(Enabled);
}
