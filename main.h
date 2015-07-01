#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include "control.h"

namespace Ui {
class Main;
}

class Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main(QWidget *parent = 0);
    ~Main();
    void Zeichnen(int x,int y);
    void Bewegen(int x,int y);
    void LaserAn();
    void LaserAus();
    Ui::Main *getUi() const;

    void setUi(Ui::Main *value);

private:
    Ui::Main *ui;
    Control* C;
private slots:
    int Auswahl();
    void Start();

};

#endif // MAIN_H
