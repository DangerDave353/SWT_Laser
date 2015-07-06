#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Befehl.h"
#include <ctype.h>
#include <algorithm>

class Parser
{
private:
    string Pfad;
    string Zeile;
    int aktuelleZeile=1;

    Befehl befehl;

public:
    Parser();
    Parser(string pfad);

        void naechsteZeile();
        void interpretiere(string Zeile);
        Befehl* getBefehlsObjekt();
        int getAnzahlBefehle();

        ~Parser();
};

#endif // PARSER_H
