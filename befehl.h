#ifndef BEFEHL_H
#define BEFEHL_H
#include <iostream>
#include <fstream>
#include <string>



class Befehl
{
private:
    int BefehlNr;
    int X;
    int Y;
    bool Laser;

    std::string Fehler;
public:
    Befehl();

    int getBefehlNr();
    void setBefehlNr(int BefehlNr);
    int getX();
    void setX(int X);
    int getY();
    void setY(int Y);
    bool getLaser();
    void setLaser(bool Laser);
    std::string getFehler();
    void setFehler(std::string Fehler);
};

#endif // BEFEHL_H
