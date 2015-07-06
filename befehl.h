#ifndef BEFEHL_H
#define BEFEHL_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Befehl
{
private:
    int BefehlNr;
    int X;
    int Y;
    bool Laser;

    string Fehler;
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
    string getFehler();
    void setFehler(string Fehler);
};

#endif // BEFEHL_H
