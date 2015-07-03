#include "statebereit.h"


StateBereit::StateBereit()
{

}

StateBereit::StateBereit(State *state, Ui::MainWindow *ui)
{
GUI=ui;
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

return  new StateBereit(this, GUI);
}

State *StateBereit::ON()
{

return new StateLaserAn(this,GUI);
}

State *StateBereit::OFF()
{
return nextState;
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
