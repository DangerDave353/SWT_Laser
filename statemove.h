#ifndef STATEMOVE_H
#define STATEMOVE_H
#include "state.h"
#include "statebereit.h"
#include "statelaseran.h"
#include "statelaseraus.h"


class StateMove : public State
{
private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;



public:
StateMove();

    StateMove(int x, int y, State *state,Ui::MainWindow *ui);


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
