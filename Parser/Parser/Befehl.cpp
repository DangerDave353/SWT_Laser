#include "stdafx.h"
#include "Befehl.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Befehlsnummern:
	-1 - Ender der Datei
	0 - Fehler
	1 - Laser
	2 - Move
*/

int BefehlNr;
int X;
int Y;
bool Laser;

int Befehl::getBefehlNr()
{
	return(BefehlNr);
}
void Befehl::setBefehlNr(int BefehlNr)
{
	::BefehlNr = BefehlNr;
}

int Befehl::getX()
{
	return(X);
}
void Befehl::setX(int X)
{
	::X = X;
}

int Befehl::getY()
{
	return(Y);
}
void Befehl::setY(int Y)
{
	::Y = Y;
}

bool Befehl::getLaser()
{
	return(Laser);
}
void Befehl::setLaser(bool Laser)
{
	::Laser = Laser;
}

Befehl::Befehl()
{
}


Befehl::~Befehl()
{
}
