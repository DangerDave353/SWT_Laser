#include "stdafx.h"
#include "StateBereit.h"
#include "StateLaserAn.h"
#include "StateLaserAus.h"
#include "StateMove.h"


StateLaserAus::StateLaserAus()
{

	delete lastState;
	lastState = currentState;
	currentState = this;

	currentState->KoordinateX = lastState->KoordinateX;
	currentState->KoordinateY = lastState->KoordinateY;
	nextState = new StateBereit(currentState->KoordinateX, currentState->KoordinateY);
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
