#ifndef STATE_H
#define STATE_H

#include "mainwindow.h"

class State
{
protected:
    int KoordinateX, KoordinateY;
    bool LaserZustand;
    State* nextState;
    State* currentState;
    State* lastState;
    MainWindow *GUI;

public:

    virtual State* Move(int x, int y);
    virtual State* Bereit();
    virtual State* ON();
    virtual State* OFF();

    virtual int getKoordinateY() const;
    virtual void setKoordinateY(int value);
    virtual int getKoordinateX() const;
    virtual void setKoordinateX(int value);
    virtual bool getLaserZustand() const;
    virtual void setLaserZustand(bool value);
};



#endif // STATE_H
