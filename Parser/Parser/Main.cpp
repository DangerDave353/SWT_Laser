// Main.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
//includes
#include "parser.h"
#include "befehl.h"

using namespace std;


string test;
char Pfad[200] = ("C:/Users/Steffen/Documents/GitHub/SWT_Laser/Parser/OPCodes.txt");
bool running = true;

int _tmain(int argc, _TCHAR* argv[])
{

	cout << "Main" << endl;

	//erstellung Parser
	Parser p = Parser::Parser(Pfad);
	//einbinden Befehl
	Befehl b = *(p.getBefehlsobjekt());

	cout << "Anzahl der Befehle: " << p.getAnzahlBefehle() << endl;

	while (running)
	{
		p.naechsteZeile();
		
		cout << "----------- Main - Werte aus Befehl -----------" << endl;
		cout << "Nr	" << b.getBefehlNr() << endl;
		cout << "X	" << b.getX() << endl;
		cout << "Y	" << b.getY() << endl;
		cout << "Laser	" << b.getLaser() << endl;
		cout << "Fehler	" << b.getFehler() << endl;
		cout << "----------- Main - Werte aus Befehl -----------" << endl;
		
		cin >> test;
		if (test == "e")
		{
			running = false;
		}
	}
	//test = p.LeseZeile(1);

	//cin >> test ;
	

	return 0;

}

