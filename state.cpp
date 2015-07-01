#include "state.h"

State::State()
{
LaserZustand=0;
KoordinateX=0;
KoordinateY=0;
}

State::State(bool laserZustand, int x, int y,Ui::Main *ui)
{
    LaserZustand=laserZustand;
    KoordinateX=x;
    KoordinateY=y;
    GUI=ui;
}

int State::getX()
{
    return KoordinateX;
}

int State::getY()
{
    return KoordinateY;
}

void State::setX(int x)
{
    KoordinateX=x;
}

void State::setY(int y)
{
    KoordinateY=y;
}

bool State::getLaser()
{
    return LaserZustand;
}

void State::setLaser(bool zustand)
{
    LaserZustand=zustand;
}


State* State::Move(int x, int y)
{
return nullptr;
}

State* State::ON()
{
return nullptr;
}
State* State::OFF()
{
return nullptr;
}
State* State::Bereit()
{
return nullptr;
}
