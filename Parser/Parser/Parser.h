#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Befehl.h"
#include <ctype.h>

using namespace std;


class Parser
{
public:
	Parser();
	Parser(string Pfad);
	
	void naechsteZeile();
	void interpretiere(string Zeile);
	Befehl* getBefehlsobjekt();
	int getAnzahlBefehle();

	~Parser();
};

