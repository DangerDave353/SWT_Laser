#ifndef STATELASERAUS_H
#define STATELASERAUS_H
#include "state.h"
#include "statebereit.h"
#include "statelaseran.h"
#include "statemove.h"

class StateLaserAus : public State
{
private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;



public:
StateLaserAus();

    StateLaserAus(State *state,MainWindow *w);


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

#endif // STATELASERAUS_H
