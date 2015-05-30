#include "stdafx.h"
#include "State.h"


State::State()
{
	KoordinateX = 0;
	KoordinateY = 0;
	LaserZustand = false;
}

State::State(bool laserZustand)
{

}

State::State(int x, int y)
{

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
	KoordinateX = x;
}

void State::setY(int y)
{
	KoordinateY = y;
}

void State::setLaser(bool zustand)
{
	LaserZustand = zustand;
}

bool State::getLaser()
{
	return LaserZustand;
}

State::~State()
{
}
