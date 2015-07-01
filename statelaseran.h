#ifndef STATELASERAN_H
#define STATELASERAN_H

#include"state.h"
#include <iostream>

class StateLaserAn : public State
{


private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;
    State* nexteState=nullptr;
    State* currentState=nullptr;
    State* lastState=nullptr;
public:
    StateLaserAn(State *state,Ui::Main *ui);
    State *Move(int x, int y);
    State *Bereit();
    State *ON();
    State *OFF();

};

#endif // STATELASERAN_H
