#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include "state.h"
#include "main.h"


class Control
{
private:
    State* aktuellerZustand;
    State* letzterZustand;
    State* naechsterZustand;
    int AnzahlBefehle;
     Ui::Main *ui;

public:
    Control();
    void naechstenBefehl();
    void ZustandAktualisieren();
    int getKomandoAnzahl();
    void StartControl();

State *getAktuellerZustand() const;
void setAktuellerZustand(State *value);
State *getLetzterZustand() const;
void setLetzterZustand(State *value);
State *getNaechsterZustand() const;
void setNaechsterZustand(State *value);
void setUi(Ui::Main *value);
};

#endif // CONTROL_H
