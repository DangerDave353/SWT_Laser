#include "stdafx.h"
#include "StateBereit.h"
#include "StateLaserAn.h"
#include "StateLaserAus.h"
#include "StateMove.h"
#include <iostream>

using namespace std;

StateMove::StateMove()
{
	KoordinateX = 0;
	KoordinateY = 0;
	LaserZustand = false;

}
StateMove::StateMove(bool laserZustand)
{
	LaserZustand = laserZustand;
	
	delete lastState;
	lastState = currentState;
	currentState = this;
//GUI Aufruf
	cout << "current State= MOVE(laser)";

}
StateMove::StateMove(int x, int y)
{
	KoordinateX = x;
	KoordinateY = y;
	delete lastState;
	lastState = currentState;
	currentState = this;
	//GUI
	cout << "current State= MOVE(move)";
	if (!LaserZustand)
	{
		nextState = new StateBereit(x, y);
	}
}
bool NextState(bool laserZustand) 
{
	if (laserZustand)
	{
		nextState = new StateMove(currentState->KoordinateX, currentState->KoordinateY);
		cout << "next State = MOVE(laser)";
		return true;
	}
	else
	{
		nextState = new StateLaserAus();
		cout << "next State = Laser Aus";
		return true;
	}
	return false;
}
bool NextState(int x, int y) 
{
	nextState = new StateMove(x,y);
	cout << "next State = MOVE(move)";
	return true;
}

StateMove::~StateMove()
{
}


