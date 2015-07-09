/*
Hier wird der Laser angeschaltet.
Von diesem Zustand kann nur in MOVE oder LaserAus gewechselt werden.
*/
#include "statelaseran.h"
#include "statebereit.h"
#include "statelaseraus.h"
#include "statemove.h"


StateLaserAn::StateLaserAn()
{

}

StateLaserAn::StateLaserAn(State *state, MainWindow *w)
{
    GUI=w;
    if(state==nullptr)
    {
        LaserZustand=false;
        KoordinateX=0;
        KoordinateY=0;
    }
    else
    {
        LaserZustand=true;
        KoordinateX=state->getKoordinateX();
        KoordinateY=state->getKoordinateY();
    }
    GUI->GuiLaserAN();

}



State *StateLaserAn::Move(int x, int y)
{

return new StateMove(x,y,this,GUI);
}

State *StateLaserAn::Bereit()
{

return this;
}

State *StateLaserAn::ON()
{

return this;
}

State *StateLaserAn::OFF()
{

return new StateLaserAus(this,GUI);
}

int StateLaserAn::getKoordinateX() const
{
    return KoordinateX;
}

void StateLaserAn::setKoordinateX(int value)
{
    KoordinateX = value;
}

int StateLaserAn::getKoordinateY() const
{
    return KoordinateY;
}

void StateLaserAn::setKoordinateY(int value)
{
    KoordinateY = value;
}

bool StateLaserAn::getLaserZustand() const
{
    return LaserZustand;
}

void StateLaserAn::setLaserZustand(bool value)
{
    LaserZustand = value;
}
