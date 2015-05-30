#pragma once



class State
{

private:
	int KoordinateX, KoordinateY;
	bool LaserZustand;
public:	
 State *currentState;
	 State *lastState;
	 State *nextState;
	State();
	State(bool laserZustand);
	State(int x, int y);
	virtual int State::getX();
	virtual int State::getY();
	virtual void State::setX(int x);
	virtual void State::setY(int y);
	virtual bool State::getLaser();
	virtual void State::setLaser(bool zustand);
	virtual bool NextState(bool laserZustand) = 0;
	virtual bool NextState(int x, int y) = 0;
	~State();
};

