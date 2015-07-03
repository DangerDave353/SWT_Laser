#ifndef CONTROL_H
#define CONTROL_H
#include "mainwindow.h"
#include <iostream>
#include "state.h"
#include "statebereit.h"
#include "statelaseran.h"
#include "statelaseraus.h"
#include "statemove.h"



class Control
{
private:
State *aktuellerZustand;
State *naechsterZustand;
State *letzterZustand;

int AnzahlBefehle;


public:
    Control(Ui::MainWindow *ui);
    void naechstenBefehl();
    void ZustandAktualisieren();
    void getKomandoAnzahl();
    void StartControl();
Ui::MainWindow *GUI;

    Control *getControl() const;
    State *getLetzterZustand() const;
    void setLetzterZustand(State *value);
    State *getNaechsterZustand() const;
    void setNaechsterZustand(State *value);
    State *getAktuellerZustand() const;
    void setAktuellerZustand(State *value);

};
#endif // CONTROL_H
