#include "stdafx.h"
#include "Parser.h"
#include "Befehl.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <algorithm>

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

void Parser::naechsteZeile()
{
	//ließt die nächste Zeile aus dem Textdokument aus
	fstream OPCodes;
	OPCodes.open(Pfad, ios::in);	//öffnen des Lesestreams

	//Umwandlung von lowercase in uppercase
	for (int i = 0; i < Zeile.length(); i++)
	{
		Zeile[i] = toupper(Zeile[i]);
	}
	
	for (int i = 0; i < aktuelleZeile; i++)
	{
		getline(OPCodes, Zeile); //Springen zur richtigen Zeile und auslesen
	}
	if( !OPCodes.eof() )
	{
		//test
		//cout << Zeile << endl;	//ausgabe der Zeile
		aktuelleZeile++;
	}
	else
	{	
		//test
		//cout << "EOF" << endl; //ausgabe für EOF
	}
	
	if (!OPCodes.eof())
	{
		interpretiere(Zeile);
	}
	else
	{	
		//bei Ende (Case 2 vorweggenommen)
		befehl.setBefehlNr(-2);
	}
	

	OPCodes.close();

}

void Parser::interpretiere(string Zeile)
{
	string ErstesZeichen;
	string Kriterium;
	int Case;
	/*
	Cases:
		-2	- Kommentar oder Leerzeile 
		-1	- EoF
		0	- Fehler
		1	- Laser
		2	- Move
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
		Case = -2; 
	}
	else if (Zeile.find("LASER") != string::npos)	//Laser
	{
		Case = 1;
	}
	else if (Zeile.find("MOVE") != string::npos)	//Move
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
		//test
		//cout << "Undefinierter Case" << endl;
		break;
	case 0:
		cout << "Fehler" << endl;

		befehl.setBefehlNr(0);
		
		break;
	case -2:
		//test
		//cout << "Kommentar oder Leer" << endl;
		
		naechsteZeile();
		
		break;
	case 1:

		//test
		//cout << "Laser" << endl;

		befehl.setBefehlNr(1);

		//on oder off unterscheidung
		if (Zeile.find("ON") != string::npos)
		{
			//on setzen
			
			//test
			//cout << "on" << endl;

			befehl.setLaser(true);

		}
		else if (Zeile.find("OFF") != string::npos)
		{
			//off setzen
			
			//test
			//cout << "off" << endl;

			befehl.setLaser(false);

		}
		else
		{
			//fehler ausgeben
			//cout << "fehler in on/off bestimmung" << endl;
		}

		break;
	case 2:
		//test
		//cout << "Move" << endl;

		befehl.setBefehlNr(2);

		int posXanfang;
		int posXende;
		int posYanfang;
		int posYende;
		int Xlaenge;
		int Ylaenge;
		int x,y;
		string strX;
		string strY;
		
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
		for (int i = posXende+1; i<Zeile.length(); i++)
		{
			char h = Zeile[i];
			if (isdigit(h))
			{
				posYanfang = i;
				break;
			}
		}
		//ermittlung Y ende
		for (int i = posYanfang; i <= Zeile.length(); i++)
		{
			char h = Zeile[i];
			if (!isdigit(h))
			{
				posYende = i - 1;
				break;
			}
		}
		
		//debug ausgabe
		//cout << posXanfang << posXende << posYanfang << posYende << endl;

		//X zusammensetzen
		
		Xlaenge = (posXende + 1) - posXanfang;

		strX = Zeile.substr(posXanfang, Xlaenge);
		
		Ylaenge = (posYende + 1) - posYanfang;

		strY = Zeile.substr(posYanfang, Ylaenge);

		//test
		//cout << "String: " << "X: " << strX << " " << "Y: " << strY << endl;

		x = stoi(strX);

		y = stoi(strY);

		//test
		//cout << "Int: " << "X: " << x << " " << "Y: " << y << endl;

		befehl.setX(x);
		befehl.setY(y);

		break;

	}

}

int Parser::getAnzahlBefehle()
{
	int Anzahl = 0;

	fstream OPCodes;
	OPCodes.open(Pfad, ios::in);	//öffnen des Lesestreams
	string HilfsZeile;
	string ErstesZeichen;

	while (!OPCodes.eof())
	{
		getline(OPCodes, HilfsZeile);

		if (HilfsZeile != "")
		{
			ErstesZeichen = HilfsZeile.at(0);
		}
		else
		{
			ErstesZeichen = "";
		}

		// Herausfinden ob Leer oder Kommentar
		if (!(ErstesZeichen == "#" || ErstesZeichen == "\0"))	//Kommentarabfrage
		{
			Anzahl++;
		}
	}

	OPCodes.close();
	return(Anzahl);

}

Parser::~Parser()
{

}
