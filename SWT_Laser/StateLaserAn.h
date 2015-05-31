#pragma once
#include "State.h"
#include "StateBereit.h"
#include "StateLaserAus.h"
#include "StateMove.h"

class StateLaserAn :
	public State
{
private:
	int KoordinateX, KoordinateY;
	bool LaserZustand;
public:
	StateLaserAn();
	StateLaserAn(bool laserZustand);
	StateLaserAn(int x, int y);
	bool StateLaserAn::NextState(bool laserZustand);
	bool StateLaserAn::NextState(int x, int y);

	~StateLaserAn();
};

