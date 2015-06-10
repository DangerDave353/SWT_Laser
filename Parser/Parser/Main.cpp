// Main.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"

using namespace std;


string test;
char Pfad[200] = ("C:\\Users\Steffen\Documents\Visual Studio 2013\Projects\Parser\OPCodes.txt");
 
int _tmain(int argc, _TCHAR* argv[])
{

	cout << "Main" << endl;

	Parser p = Parser::Parser(Pfad);

	test = p.LeseZeile(1);

	cin >> test;
	
	return 0;

}

