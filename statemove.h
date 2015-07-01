#ifndef STATEMOVE_H
#define STATEMOVE_H

#include"state.h"
#include <iostream>

class StateMove : public State
{
private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;
    State* nexteState=nullptr;
    State* currentState=nullptr;
    State* lastState=nullptr;
public:
    StateMove(int x, int y, State *state, Ui::Main *ui);
    State *Move(int x, int y);
    State *Bereit();
    State *ON();
    State *OFF();

};

#endif // STATEMOVE_H
