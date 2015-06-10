#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Parser
{
public:
	Parser();
	Parser(string Pfad);

	string LeseZeile(long ZeileNr);
	
	~Parser();
};

