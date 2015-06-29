#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Befehl
{
public:
	Befehl();
	~Befehl();
	int getBefehlNr();
	void setBefehlNr(int BefehlNr);
	int getX();
	void setX(int X);
	int getY();
	void setY(int Y);
	bool getLaser();
	void setLaser(bool Laser);
	
};

