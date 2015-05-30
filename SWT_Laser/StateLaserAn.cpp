#include "stdafx.h"
#include "StateBereit.h"
#include "StateLaserAn.h"
#include "StateLaserAus.h"
#include "StateMove.h"
#include <iostream>

using namespace std;

extern State *currentState;
extern State *lastState;
extern State *nextState;

StateLaserAn::StateLaserAn()
{
	this->KoordinateX = lastState->getX();
	this->KoordinateY = lastState->getY();
	LaserZustand = true;
	
	delete lastState;
	lastState = currentState;
	currentState = this;
	cout << "current State = Laser An";
	//GUI Aufruf
}


bool NextState(bool laserZustand) 
{

	if (laserZustand)
	{
		cout << "next State = Laser An(laser)";
		*nextState = StateLaserAn();
		return true;
	}
	else
	{
		cout << "next State = Laser Aus(laser)";
		*nextState = StateLaserAus();
		return true;
	}
	return false;
}
bool NextState(int x, int y) 
{
	cout << "next State = Move(move)";
	*nextState = StateMove(x,y);
	return true;
}


StateLaserAn::~StateLaserAn()
{
}
