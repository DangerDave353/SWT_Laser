/*
Der Zustand Bereit ist der Grundzustand, das Programm startet immer hier.
Der Laser ist in diesem Zustand immer Aus.
Von Bereit kann mit ON in LaserAn gewechselt werden.
Bei einem MOVE Befehl wird in den Zustand MOVE gewechselt, aber der Zustand spring dannach sofort wieder
in Bereit. Das entspricht einer Bewegung bei ausgeschaltetem Laser.
*/
#include "statebereit.h"
#include "statelaseran.h"
#include "statelaseraus.h"
#include "statemove.h"

StateBereit::StateBereit()
{

}

StateBereit::StateBereit(State *state, MainWindow *w)
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
    LaserZustand=state->getLaserZustand();
    KoordinateX=state->getKoordinateX();
    KoordinateY=state->getKoordinateY();
}

}

State *StateBereit::Move(int x, int y)
{

    return new StateMove(x,y,this,GUI);
}

State *StateBereit::Bereit()
{

return  this;
}

State *StateBereit::ON()
{

return new StateLaserAn(this,GUI);
}

State *StateBereit::OFF()
{
return this;
}

int StateBereit::getKoordinateX() const
{
    return KoordinateX;
}

void StateBereit::setKoordinateX(int value)
{
    KoordinateX = value;
}

int StateBereit::getKoordinateY() const
{
    return KoordinateY;
}

void StateBereit::setKoordinateY(int value)
{
    KoordinateY = value;
}

bool StateBereit::getLaserZustand() const
{
    return LaserZustand;
}

void StateBereit::setLaserZustand(bool value)
{
    LaserZustand = value;
}
