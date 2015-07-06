#ifndef STATEBEREIT_H
#define STATEBEREIT_H
#include "state.h"
#include "statelaseran.h"
#include "statelaseraus.h"
#include "statemove.h"

class StateBereit : public State
{
private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;



public:
StateBereit();

    StateBereit(State *state,  MainWindow *w);


    State* Move(int x, int y);
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

#endif // STATEBEREIT_H
