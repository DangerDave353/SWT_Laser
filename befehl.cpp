/*
Es gibt ein Object der Klasse Befehl. Es dient zu übergabe der Befehle vom Parser zur Control.
Es beinhaltert nur Getter und Setter Methoden.

*/
#include "befehl.h"

Befehl::Befehl()
{
BefehlNr=1;
Fehler="";
X=0;
Y=0;
Laser=false;
}

int Befehl::getBefehlNr()
{
    return(BefehlNr);
}

void Befehl::setBefehlNr(int befehlNr)
{
    BefehlNr = befehlNr;
}

int Befehl::getX()
{
    return(X);
}

void Befehl::setX(int x)
{
    X = x;
}

int Befehl::getY()
{
    return(Y);
}

void Befehl::setY(int y)
{
    Y = y;
}

bool Befehl::getLaser()
{
    return(Laser);
}

void Befehl::setLaser(bool laser)
{
    Laser = laser;
}

std::string Befehl::getFehler()
{
    return(Fehler);
}

void Befehl::setFehler(std::string fehler)
{
    Fehler = fehler;
}
