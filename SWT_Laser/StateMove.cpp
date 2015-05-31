#include "stdafx.h"
#include "StateMove.h"
#include <iostream>

using namespace std;

extern State *currentState;
extern State *lastState;
extern State *nextState;


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
		cout << "next State = Bereit(move)";
		*nextState = StateBereit(x, y);
	}
}
bool NextState(bool laserZustand) 
{
	if (laserZustand)
	{
		cout << "next State = MOVE(laser)";
		*nextState = StateMove(currentState->getX(), currentState->getY());
		
		return true;
	}
	else
	{
		cout << "next State = Laser Aus";
		*nextState = StateLaserAus();
		
		return true;
	}
	return false;
}
bool NextState(int x, int y) 
{
	cout << "next State = MOVE(move)";
	*nextState = StateMove(x,y);
	
	return true;
}

StateMove::~StateMove()
{
}


