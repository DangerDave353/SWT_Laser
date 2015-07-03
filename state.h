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
 Ui::MainWindow *GUI;

public:

    State();
    State(bool laserZustand, int x, int y, State *state);


    virtual State* Move(int x, int y);
    virtual State* Bereit();
    virtual State* ON();
    virtual State* OFF();

    int getKoordinateY() const;
    void setKoordinateY(int value);
    int getKoordinateX() const;
    void setKoordinateX(int value);
    bool getLaserZustand() const;
    void setLaserZustand(bool value);
};



#endif // STATE_H
