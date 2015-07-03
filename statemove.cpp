#include "statemove.h"



StateMove::StateMove()
{

}

StateMove::StateMove(int x, int y, State *state,Ui::MainWindow *ui)
{
Gui=ui;
    if(state==nullptr)
    {
        LaserZustand=false;
        KoordinateX=0;
        KoordinateY=0;
    }
    else
    {
        LaserZustand=state->getLaserZustand();
        KoordinateX=x;
        KoordinateY=y;
    }
}

State *StateMove::Move(int x, int y)
{

return new StateMove(x,y,this,GUI);
}

State *StateMove::Bereit()
{

return new StateBereit(this,GUI);
}

State *StateMove::ON()
{

return new StateLaserAn(this,GUI);
}

State *StateMove::OFF()
{

return new StateLaserAus(this,GUI);
}

int StateMove::getKoordinateX() const
{
    return KoordinateX;
}

void StateMove::setKoordinateX(int value)
{
    KoordinateX = value;
}

int StateMove::getKoordinateY() const
{
    return KoordinateY;
}

void StateMove::setKoordinateY(int value)
{
    KoordinateY = value;
}

bool StateMove::getLaserZustand() const
{
    return LaserZustand;
}

void StateMove::setLaserZustand(bool value)
{
    LaserZustand = value;
}
