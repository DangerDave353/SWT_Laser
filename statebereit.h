#ifndef STATEBEREIT_H
#define STATEBEREIT_H


#include"state.h"
#include <iostream>

class StateBereit : public State
{
private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;
    State* nexteState=nullptr;
    State* currentState=nullptr;
    State* lastState=nullptr;
public:
    StateBereit(State *state, Ui::Main *ui);
    State *Move(int x, int y);
    State *Bereit();
    State *ON();
    State *OFF();


};

#endif // STATEBEREIT_H
