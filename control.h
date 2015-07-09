#ifndef CONTROL_H
#define CONTROL_H
#include "mainwindow.h"
#include <iostream>
#include "state.h"
#include "parser.h"
#include "befehl.h"



class Control
{
private:
State *aktuellerZustand;    //pointer auf die Zustände
State *naechsterZustand;
State *letzterZustand;
MainWindow *window;         //pointer auf dui GUI
int AnzahlBefehle;
Parser parser;
Befehl *BefehlsObjekt;      //pointer auf das Befehlsobjekt


public:
    Control(MainWindow *w);
    void ZustandAktualisieren();
    void getKomandoAnzahl();
    void StartControl(std::string pfad);
    void ControlBefehlsAusfuehrung();


//Getter und Setter Methoden
    Control *getControl() const;
    State *getLetzterZustand() const;
    void setLetzterZustand(State *value);
    State *getNaechsterZustand() const;
    void setNaechsterZustand(State *value);
    State *getAktuellerZustand() const;
    void setAktuellerZustand(State *value);

};
#endif // CONTROL_H
