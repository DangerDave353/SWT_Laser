#pragma once
#include "State.h"
#include "StateBereit.h"
#include "StateLaserAn.h"
#include "StateMove.h"

class StateLaserAus : 
	public State
{

private:
	int KoordinateX, KoordinateY;
	bool LaserZustand;
public:
	StateLaserAus();
	StateLaserAus(bool laserZustand);
	StateLaserAus(int x, int y);
	bool StateLaserAus::NextState(bool laserZustand);
	bool StateLaserAus::NextState(int x, int y);

	~StateLaserAus();
};

