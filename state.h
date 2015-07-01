#ifndef STATE_H
#define STATE_H

#include "control.h"
#include "main.h"

class State
{    
protected:
    int KoordinateX, KoordinateY;
    bool LaserZustand;
    State* nextState;
    State* currentState;
    State* lastState;
    Ui::Main* GUI;

public:

    State();
    State(bool laserZustand, int x, int y, Ui::Main *ui);
    virtual int getX();
    virtual int getY();
    virtual void setX(int x);
    virtual void setY(int y);
    virtual bool getLaser();
    virtual void setLaser(bool zustand);

    virtual State *Move(int x, int y);
    virtual State *Bereit();
    virtual State *ON();
    virtual State *OFF();

};



#endif // STATE_H
