#include "stdafx.h"
#include "StateLaserAus.h"
#include <iostream>

using namespace std;

extern State *currentState;
extern State *lastState;
extern State *nextState;

StateLaserAus::StateLaserAus()
{

	delete lastState;
	lastState = currentState;
	currentState = this;
	cout << "current State = Laser Aus";
	currentState->setX(lastState->getX());
	currentState->setY(lastState->getY());
	cout << "next State = Bereit";
	nextState = new StateBereit(this->KoordinateX, this->KoordinateY);

}
bool NextState(bool laserZustand) 
{
	return false;
}
bool NextState(int x, int y) 
{
	return false;
}

StateLaserAus::~StateLaserAus()
{
}
