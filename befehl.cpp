#include "befehl.h"

Befehl::Befehl()
{

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

string Befehl::getFehler()
{
    return(Fehler);
}

void Befehl::setFehler(string fehler)
{
    Fehler = fehler;
}
