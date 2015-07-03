#include "statelaseraus.h"



StateLaserAus::StateLaserAus()
{

}

StateLaserAus::StateLaserAus(State *state,Ui::MainWindow *ui)
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
        LaserZustand=false;
        KoordinateX=state->getKoordinateX();
        KoordinateY=state->getKoordinateY();
    }
}

State *StateLaserAus::Move(int x, int y)
{

return new StateMove(x,y,this,GUI);
}

State *StateLaserAus::Bereit()
{

return new StateBereit(this,GUI);
}

State *StateLaserAus::ON()
{

return new StateLaserAn(this,GUI);
}

State *StateLaserAus::OFF()
{

return new StateLaserAus(this,GUI);
}

int StateLaserAus::getKoordinateX() const
{
    return KoordinateX;
}

void StateLaserAus::setKoordinateX(int value)
{
    KoordinateX = value;
}

int StateLaserAus::getKoordinateY() const
{
    return KoordinateY;
}

void StateLaserAus::setKoordinateY(int value)
{
    KoordinateY = value;
}

bool StateLaserAus::getLaserZustand() const
{
    return LaserZustand;
}

void StateLaserAus::setLaserZustand(bool value)
{
    LaserZustand = value;
}