#include "stdafx.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Pfad;

Parser::Parser()
{
}

Parser::Parser(string Pfad)
{
	//fstream OPCodes(Pfad,ios::in);
	::Pfad = Pfad;
}


string Parser::LeseZeile(long ZeileNr)
{
	fstream OPCodes(Pfad, ios::in);
	cout << "readline" << endl;
	string Zeile;
	//OPCodes.getline(Zeile, 1);
	cout << Zeile;

	OPCodes.close();

	return("a");
}

Parser::~Parser()
{
}
