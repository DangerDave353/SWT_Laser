#pragma once
#include "State.h"
#include "StateBereit.h"
#include "StateLaserAn.h"
#include "StateLaserAus.h"


class StateMove :
	public State
{

private:
	int KoordinateX, KoordinateY;
	bool LaserZustand;
public:
	StateMove();
	StateMove(bool laserZustand);
	StateMove(int x, int y);
	bool StateMove::NextState(bool laserZustand);
	bool StateMove::NextState(int x, int y);
	~StateMove();
};

