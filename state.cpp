#include "state.h"



State::State()
{

}

State::State(bool laserZustand, int x, int y, State *state)
{

}

State *State::Move(int x, int y)
{
return nullptr;
}

State *State::Bereit()
{
return nullptr;
}

State *State::ON()
{
return nullptr;
}

State *State::OFF()
{
return nullptr;
}

int State::getKoordinateY() const
{
    return KoordinateY;
}

void State::setKoordinateY(int value)
{
    KoordinateY = value;
}

int State::getKoordinateX() const
{
    return KoordinateX;
}

void State::setKoordinateX(int value)
{
    KoordinateX = value;
}

bool State::getLaserZustand() const
{
    return LaserZustand;
}

void State::setLaserZustand(bool value)
{
    LaserZustand = value;
}
