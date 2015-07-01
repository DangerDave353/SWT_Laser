#ifndef STATELASERAUS_H
#define STATELASERAUS_H

#include"state.h"
#include <iostream>
class StateLaserAus : public State
{
private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;
    State* nexteState=nullptr;
    State* currentState=nullptr;
    State* lastState=nullptr;
public:
    StateLaserAus(State *state ,Ui::Main *ui);
    State *Move(int x, int y);
    State *Bereit();
    State *ON();
    State *OFF();

};

#endif // STATELASERAUS_H
