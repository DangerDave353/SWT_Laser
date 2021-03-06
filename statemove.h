#ifndef STATEMOVE_H
#define STATEMOVE_H
#include "state.h"


class StateMove : public State
{
private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;



public:
StateMove();

    StateMove(int x, int y, State *state,MainWindow *w);


    State *Move(int x, int y);
    State *Bereit();
    State *ON();
    State *OFF();

    int getKoordinateX() const;
    void setKoordinateX(int value);
    int getKoordinateY() const;
    void setKoordinateY(int value);
    bool getLaserZustand() const;
    void setLaserZustand(bool value);
};

#endif // STATEMOVE_H
