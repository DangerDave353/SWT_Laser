/*
Parser

Der Parser ist daf�r zust�ndig die einzelnen Befehle aus der OPCodes.txt zu lesen, danach zu interpretieren
und den entsprechenden Befehl in ein Objekt der �bergabeklasse Befehl zu schreiben.

Parser(string Pfad)
ist der Konstruktor, ihm muss der Pfad zur OPCodes.txt als string �bergeben werden.
Er erstellt das Objekt von Befehl.

Befehl* getBefehlsobjekt() 
�bergibt den Pointer auf das Befehlsobjekt.

int getAnzahlBefehle()
Liefert die Anzahl an m�glichen Befehlen als Integer Zahl zur�ck, 
hierbei werden nur leere Zeilen und Kommentare gefiltert.

void naechsteZeile()
Lie�t die n�chste Zeile der txt aus und ruft dann void interpretiere(string Zeile) auf.

void interpretiere(string Zeile)
Filtert aus dem �bergebenen String den jeweiligen Befehl herraus und Schreibt ihn in das Befehlsobjekt.

*/
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
	//Kontruktor
	::Pfad = Pfad; //�bergebener Pfad wird global gespeichert
	befehl = Befehl::Befehl(); //Befehlsobjekt wird erzeugt

}

Befehl* Parser::getBefehlsobjekt()
{
	return &befehl;
}

void Parser::naechsteZeile()
{
	fstream OPCodes;
	OPCodes.open(Pfad, ios::in);	//�ffnen des Lesestreams

	//Springen zur richtigen Zeile und auslesen
	for (int i = 0; i < aktuelleZeile; i++)
	{
		getline(OPCodes, Zeile); //Auslesen in die Variable Zeile
	}
	//--

	//Umwandlung von lowercase in uppercase
	for (int i = 0; i < Zeile.length(); i++)
	{
		Zeile[i] = toupper(Zeile[i]);
	}
	//--

	//aktuellenZeilen Counter erh�hen, falls das Ende der txt noch nicht erreicht wurde
	if( !OPCodes.eof() )
	{
		//cout << Zeile << endl;	//Debugausgabe
		aktuelleZeile++;
	}
	else
	{	
		//cout << "EOF" << endl; //Debugausgabe
	}
	//--

	//Unterscheidung ob zu interpr�tierender Text oder das Ende der Datei vorhanden ist
	if (!OPCodes.eof())
	{
		//Einsprung in die interpretiere Funktion
		interpretiere(Zeile);
	}
	else
	{	
		//bei Ende der Datei (Case -1 vorweggenommen)
		befehl.setBefehlNr(-1);
	}
	//--

	OPCodes.close();

}

void Parser::interpretiere(string Zeile)
{
	string ErstesZeichen;
	string Kriterium;
	int Case;
	/*

	Die Cases sind Global mit der gleichen Nummer versehen, deshalb hier nochmal -1 obwohl er hier nicht benutzt wird

	Cases:
		-2	- Kommentar oder Leerzeile 
		-1	- EoF
		0	- Fehler
		1	- Laser
		2	- Move
	*/

	//Auslese des ersten Zeichens
	if (Zeile != "")
	{
		ErstesZeichen = Zeile.at(0); //Auslesen des ersten Zeichens falls nicht leer
	}
	else
	{
		ErstesZeichen = "";
	}
	//--

	//Herausfinden ob oder welcher g�ltige Befehl sich im String befindet
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
	else	//Ung�ltiger Befehl
	{
		Case = 0;
	}
	//--

	//Konditionen auslesen und in Das Befehlsobjekt schreiben
	switch (Case)
	{
	default:
		//cout << "Undefinierter Case" << endl; //Debugausgabe
		break;
	case 0:
		//cout << "Fehler" << endl;	//Debugausgabe
		befehl.setFehler("Ung�ltiger Befehl in Zeile: " + Zeile);

		befehl.setBefehlNr(0);

		break;
	case -2:
		//cout << "Kommentar oder Leer" << endl; //Debugausgabe

		naechsteZeile();
		
		break;
	case 1:

		//cout << "Laser" << endl;	//Debugausgabe

		befehl.setBefehlNr(1);

		//on oder off unterscheidung
		if (Zeile.find("ON") != string::npos)
		{
			//on setzen
			
			//cout << "on" << endl;	//Debugausgabe

			befehl.setLaser(true);

		}
		else if (Zeile.find("OFF") != string::npos)
		{
			//off setzen
			
			//cout << "off" << endl;	//Debugausgabe

			befehl.setLaser(false);

		}
		else
		{
			//fehler ausgeben
			//cout << "fehler in on/off bestimmung" << endl;	//Debugausgabe
			befehl.setFehler("Ung�ltiger Zustand (ON/OFF) in Zeile: " + Zeile);
			befehl.setBefehlNr(0);
		}
		//--
		break;
	case 2:
		//cout << "Move" << endl;	//Debugausgabe

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
		bool xAnfangExist = false;
		for (int i = 0; i<Zeile.length();i++)
		{
			char h = Zeile[i];
			if (isdigit(h))
			{
				posXanfang = i;
				xAnfangExist = true;
				break;
			}
		}
		if (!(xAnfangExist))
		{
			befehl.setFehler("Keine Koordinate gefunden in Zeile: " + Zeile);
			befehl.setBefehlNr(0);
			break;
		}
		//--

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
		//--

		//ermittlung Y anfang
		bool yAnfangExist = false;
		for (int i = posXende+1; i<Zeile.length(); i++)
		{
			char h = Zeile[i];
			if (isdigit(h))
			{
				posYanfang = i;
				yAnfangExist = true;
				break;
			}
		}
		if (!(yAnfangExist))
		{
			befehl.setFehler("Keine zweite Koordinate gefunden in Zeile: " + Zeile);
			befehl.setBefehlNr(0);
			break;
		}
		//--

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
		//--
		
		//cout << posXanfang << posXende << posYanfang << posYende << endl;	//Debugausgabe

		//Fehlerabfrage
		if ((posXanfang <= 0) || (posXanfang > Zeile.length()) ||
			(posXende <= 0) || (posXende > Zeile.length()) ||
			(posYanfang <= 0) || (posYanfang > Zeile.length()) ||
			(posYende <= 0) || (posYende > Zeile.length()) )
		{
			befehl.setFehler("Fehler in der Koordinatenfindung in Zeile: " + Zeile);
			befehl.setBefehlNr(0);
		}
		//--

		//X-String herauskopieren
		Xlaenge = (posXende + 1) - posXanfang;
		strX = Zeile.substr(posXanfang, Xlaenge);
		//--
		
		//Y-String herauskopieren
		Ylaenge = (posYende + 1) - posYanfang;
		strY = Zeile.substr(posYanfang, Ylaenge);
		//--
		
		//cout << "String: " << "X: " << strX << " " << "Y: " << strY << endl;	//Debugausgabe

		// X- und Y-Strings in Integer umwandeln
		x = stoi(strX);
		y = stoi(strY);
		//--
		
		//cout << "Int: " << "X: " << x << " " << "Y: " << y << endl;	//Debugausgabe

		//Schreiben der X- und Y-Werte in das Befehlsobjekt
		befehl.setX(x);
		befehl.setY(y);
		//--

		break;

	}

}

int Parser::getAnzahlBefehle()
{
	int Anzahl = 0;

	fstream OPCodes;
	OPCodes.open(Pfad, ios::in);	//�ffnen des Lesestreams
	string HilfsZeile;
	string ErstesZeichen;

	//Inkrementierung der Anzahl
	while (!OPCodes.eof()) //wiederholen bis EoF erreicht ist
	{
		getline(OPCodes, HilfsZeile);	//auslesen der Zeile

		//Umwandlung von lowercase in uppercase
		for (int i = 0; i < HilfsZeile.length(); i++)
		{
			HilfsZeile[i] = toupper(HilfsZeile[i]);
		}
		//--

		//Auslese des ersten Zeichens
		if (HilfsZeile != "")
		{
			ErstesZeichen = HilfsZeile.at(0); //Auslesen des ersten Zeichens falls nicht leer
		}
		else
		{
			ErstesZeichen = "";
		}
		//--

		int Case;

		//Herausfinden ob oder welcher g�ltige Befehl sich im String befindet
		if (ErstesZeichen == "#" || ErstesZeichen == "\0")	//Kommentarabfrage
		{
			Case = -2;
		}
		else if (HilfsZeile.find("LASER") != string::npos)	//Laser
		{
			Case = 1;
		}
		else if (HilfsZeile.find("MOVE") != string::npos)	//Move
		{
			Case = 2;
		}
		else	//Ung�ltiger Befehl
		{
			Case = 0;
		}
		//--

		//Konditionen auslesen und in Das Befehlsobjekt schreiben
		switch (Case)
		{
		default:
			//cout << "Undefinierter Case" << endl; //Debugausgabe
			break;
		case 0:
			//cout << "Fehler" << endl;	//Debugausgabe
			
			befehl.setFehler(befehl.getFehler() + "\nUng�ltiger Befehl in Zeile: " + HilfsZeile);
			befehl.setBefehlNr(0);
			
			break;
		case -2:
			//cout << "Kommentar oder Leer" << endl; //Debugausgabe


			break;
		case 1:

			//cout << "Laser" << endl;	//Debugausgabe

			//on oder off unterscheidung
			if (HilfsZeile.find("ON") != string::npos)
			{
				//on setzen

				//cout << "on" << endl;	//Debugausgabe
				Anzahl++;
				
			}
			else if (HilfsZeile.find("OFF") != string::npos)
			{
				//off setzen

				//cout << "off" << endl;	//Debugausgabe
				Anzahl++;

			}
			else
			{
				//fehler ausgeben
				//cout << "fehler in on/off bestimmung" << endl;	//Debugausgabe
				befehl.setFehler(befehl.getFehler() + "\nUng�ltiger Zustand (ON/OFF) in Zeile: " + HilfsZeile);
				befehl.setBefehlNr(0);
			}
			//--
			break;
		case 2:
			//cout << "Move" << endl;	//Debugausgabe

			
			int posXanfang;
			int posXende;
			int posYanfang;
			int posYende;
			int Xlaenge;
			int Ylaenge;
			int x, y;
			string strX;
			string strY;

			//ermittlung X anfang
			bool xAnfangExist = false;
			for (int i = 0; i<HilfsZeile.length(); i++)
			{
				char h = HilfsZeile[i];
				if (isdigit(h))
				{
					posXanfang = i;
					xAnfangExist = true;
					break;
				}
			}
			if (!(xAnfangExist))
			{
				befehl.setFehler(befehl.getFehler() + "\nKeine Koordinate gefunden in Zeile: " + HilfsZeile);
				befehl.setBefehlNr(0);
				break;
			}
			//--

			//ermittlung X ende
			for (int i = posXanfang; i<HilfsZeile.length(); i++)
			{
				char h = HilfsZeile[i];
				if (!isdigit(h))
				{
					posXende = i - 1;
					break;
				}
			}
			//--

			//ermittlung Y anfang
			bool yAnfangExist = false;
			for (int i = posXende + 1; i<HilfsZeile.length(); i++)
			{
				char h = HilfsZeile[i];
				if (isdigit(h))
				{
					posYanfang = i;
					yAnfangExist = true;
					break;
				}
			}
			if (!(yAnfangExist))
			{
				befehl.setFehler(befehl.getFehler() + "\nKeine zweite Koordinate gefunden in Zeile: " + HilfsZeile);
				befehl.setBefehlNr(0);
				break;
			}
			//--

			//ermittlung Y ende
			for (int i = posYanfang; i <= HilfsZeile.length(); i++)
			{
				char h = HilfsZeile[i];
				if (!isdigit(h))
				{
					posYende = i - 1;
					break;
				}
			}
			//--

			//cout << posXanfang << posXende << posYanfang << posYende << endl;	//Debugausgabe

			//Fehlerabfrage
			if ((posXanfang <= 0) || (posXanfang > HilfsZeile.length()) ||
				(posXende <= 0) || (posXende > HilfsZeile.length()) ||
				(posYanfang <= 0) || (posYanfang > HilfsZeile.length()) ||
				(posYende <= 0) || (posYende > HilfsZeile.length()))
			{
				befehl.setFehler(befehl.getFehler() + "\nFehler in der Koordinatenfindung in Zeile: " + HilfsZeile);
				befehl.setBefehlNr(0);
			}
			else
			{
				Anzahl++;
			}
			
			break;

		}

		
	}
	//--

	OPCodes.close();
	return(Anzahl);

}

Parser::~Parser()
{

}
