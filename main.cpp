#include "main.h"
#include "ui_main.h"
#include "control.h"
Main::Main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main)
{
    ui->setupUi(this);
    connect(ui->cmd_Auswahl,SIGNAL(clicked(bool)),SLOT(Auswahl()));
    connect(ui->cmd_Start,SIGNAL(clicked(bool)),SLOT(Start()));
}

Main::~Main()
{
    delete ui;
}

void Main::Zeichnen(int x, int y)
{

}

void Main::Bewegen(int x, int y)
{

}



void Main::LaserAn()
{

   ui->cmd_Laser->setStyleSheet("background-color:green;");
}

void Main::LaserAus()
{
   ui->cmd_Laser->setStyleSheet("background-color:red;");
}
Ui::Main *Main::getUi() const
{
    return ui;
}
void Main::setUi(Ui::Main *value)
{
    ui = value;
}



int Main::Auswahl()
{
    return 0;
}


int main(int argc, char **argv) {
    QApplication a(argc, argv);
    Main w;
    w.show();
Control* C = new Control();

    return a.exec();
}

void Main::Start()
{
    int Anzahl=C->getKomandoAnzahl();
    ui->progressBar->setMaximum(Anzahl);
    C->setUi(ui);
    C->StartControl();
    C->naechstenBefehl();
}
