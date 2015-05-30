#include "stdafx.h"
#include "StateBereit.h"
#include <iostream>

using namespace std;

extern State *currentState;
extern State *lastState;
extern State *nextState;

StateBereit::StateBereit()	//Initalisierungszustand
{
	KoordinateX = 0;
	KoordinateY = 0;
	LaserZustand = false;


}

StateBereit::StateBereit(bool laserZustand)
{
	LaserZustand = laserZustand;

	delete lastState;
	*lastState = *currentState;
	*currentState = *this;
	cout << "current State = Bereit(laser)";
	//GUI Aufruf
}
StateBereit::StateBereit(int x, int y)
{
	KoordinateX = x;
	KoordinateY = y;

	delete lastState;
	*lastState = *currentState;
	*currentState = *this;
	cout << "current State = Bereit(move)";
	//GUI Aufruf
}

bool NextState(bool laserZustand) 
{
	if (currentState->getLaser())
	{
		return false;
	}
	else
	{
		if (laserZustand)
		{
			cout << "next State = Laser An(laser)";
			*nextState = StateLaserAn();
			return true;
		}
		else
		{
			cout << "next State = Bereit(laser)";
			*nextState = StateBereit(currentState->getX(), currentState->getY());
			return true;
		}
	}
	return false;
}
bool NextState(int x, int y) 
{
	if (currentState->getLaser())
	{
		cout << "next State = Move(move)";
		nextState = new StateMove(x, y);
		return true;
	}
		return false;
}


StateBereit::~StateBereit()
{
}
