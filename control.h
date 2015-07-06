#ifndef CONTROL_H
#define CONTROL_H
#include "mainwindow.h"
#include <iostream>
#include "state.h"
#include "statebereit.h"
#include "statelaseran.h"
#include "statelaseraus.h"
#include "statemove.h"
#include "parser.h"
#include "befehl.h"



class Control
{
private:
State *aktuellerZustand;
State *naechsterZustand;
State *letzterZustand;
MainWindow *window;
int AnzahlBefehle;
Parser parser;
Befehl *BefehlsObjekt;

public:
    Control(MainWindow *w);
    void naechstenBefehl();
    void ZustandAktualisieren();
    void getKomandoAnzahl();
    void StartControl(string pfad);
    void ControlBefehlsAusfuehrung();
Ui::MainWindow *GUI;
void BefehlsObjektUebergeben();

    Control *getControl() const;
    State *getLetzterZustand() const;
    void setLetzterZustand(State *value);
    State *getNaechsterZustand() const;
    void setNaechsterZustand(State *value);
    State *getAktuellerZustand() const;
    void setAktuellerZustand(State *value);

};
#endif // CONTROL_H
