#include "stdafx.h"
#include "Parser.h"
#include "Befehl.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

string Pfad;
string Zeile;
int aktuelleZeile=1;

Befehl befehl;

Parser::Parser()
{
}

Parser::Parser(string Pfad)
{
	//Contructor
	::Pfad = Pfad; //übergebener Pfad wird global gespeichert
	befehl = Befehl::Befehl();

}

Befehl* Parser::getBefehlsobjekt()
{
	return &befehl;
}

string Parser::naechsteZeile()
{
	//ließt die nächste Zeile aus dem Textdokument aus
	fstream OPCodes;
	OPCodes.open(Pfad, ios::in);	//öffnen des Lesestreams

	
	
	for (int i = 0; i < aktuelleZeile; i++)
	{
		getline(OPCodes, Zeile); //Springen zur richtigen Zeile und auslesen
	}
	if( !OPCodes.eof() )
	{
		cout << Zeile << endl;	//ausgabe der Zeile
		aktuelleZeile++;
	}
	else
	{
		cout << "EOF" << endl; //ausgabe für EOF
	}
	//Test \/
	if (!OPCodes.eof())
	{
		interpretiere(Zeile);
	}
	//Test /\

	OPCodes.close();

	return("a");
}

void Parser::interpretiere(string Zeile)
{
	string ErstesZeichen;
	string Kriterium;
	int Case;
	/*
	Cases:
		-1 - Kommentar oder Leerzeile 
		0 - Fehler
		1 - Laser
		2 - Move
	*/

	if (Zeile != "")
	{
		ErstesZeichen = Zeile.at(0);
	}
	else
	{
		ErstesZeichen = "";
	}

	// Befehl Herausfinden
	if (ErstesZeichen == "#" || ErstesZeichen == "\0")	//Kommentarabfrage
	{
		Case = -1; 
	}
	else if (Zeile.find("LASER") != string::npos)
	{
		Case = 1;
	}
	else if (Zeile.find("MOVE") != string::npos)
	{
		Case = 2;
	}
	else 
	{
		Case = 0;
	}

	switch (Case)
	{
	default:
		cout << "Undefinierter Case" << endl;
		break;
	case 0:
		cout << "Fehler" << endl;

		befehl.setBefehlNr(0);
		
		break;
	case -1:
		cout << "Kommentar oder Leer" << endl;
		naechsteZeile();
		break;
	case 1:
		cout << "Laser" << endl;

		befehl.setBefehlNr(1);

		//on oder off unterscheidung
		if (Zeile.find("ON") != string::npos)
		{
			//on setzen
			cout << "on" << endl;

			befehl.setLaser(true);

		}
		else if (Zeile.find("OFF") != string::npos)
		{
			//off setzen
			cout << "off" << endl;

			befehl.setLaser(false);

		}
		else
		{
			//fehler ausgeben
			cout << "fehler in on/off bestimmung" << endl;
		}

		break;
	case 2:
		cout << "Move" << endl;

		befehl.setBefehlNr(2);

		int posXanfang;
		int posXende;
		int posYanfang;
		int posYende;
		int x,y;
		
		//ermittlung X anfang
		for (int i = 0; i<Zeile.length();i++)
		{
			char h = Zeile[i];
			if (isdigit(h))
			{
				posXanfang = i;
				break;
			}
		}
		//ermittlung X ende
		for (int i = posXanfang; i<Zeile.length(); i++)
		{
			char h = Zeile[i];
			if (!isdigit(h))
			{
				posXende = i-1;
				break;
			}
		}
		//ermittlung Y anfang
		for (int i = posXende; i<Zeile.length(); i++)
		{
			char h = Zeile[i];
			if (isdigit(h))
			{
				posYanfang = i;
				break;
			}
		}
		//ermittlung Y ende
		for (int i = posYanfang; i<Zeile.length(); i++)
		{
			char h = Zeile[i];
			if (!isdigit(h))
			{
				posYende = i - 1;
				break;
			}

		//cout <<  << endl;
		// HIER WEITER
		break;

	}

}

Parser::~Parser()
{

}
