#ifndef STATELASERAN_H
#define STATELASERAN_H
#include "state.h"
#include "statebereit.h"
#include "statelaseraus.h"
#include "statemove.h"

class StateLaserAn : public State
{
private:
    int KoordinateX, KoordinateY;
    bool LaserZustand;



public:
StateLaserAn();

    StateLaserAn(State *state,Ui::MainWindow *ui);


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

#endif // STATELASERAN_H
