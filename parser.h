#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "befehl.h"
#include <ctype.h>
#include <algorithm>


class Parser
{
private:
    std::string Pfad;
    std::string Zeile;
    int aktuelleZeile=1;

    Befehl befehl;

public:
    Parser();
    Parser(std::string pfad);

    void naechsteZeile();                   // Aktualisiert this->befehl
    void interpretiere(std::string Zeile);  // Liest Befehl aus Zeile?/Text?
    Befehl* getBefehlsObjekt();
    int getAnzahlBefehle();
};

#endif // PARSER_H
