#pragma once
#include "State.h"
#include "StateLaserAn.h"
#include "StateLaserAus.h"
#include "StateMove.h"

class StateBereit :
	public State
{

private:
	int KoordinateX, KoordinateY;
	bool LaserZustand;
public:
	StateBereit();
	StateBereit(bool laserZustand);
	StateBereit(int x, int y);
	bool StateBereit::NextState(bool laserZustand);
	bool StateBereit::NextState(int x, int y);

	~StateBereit();
};

