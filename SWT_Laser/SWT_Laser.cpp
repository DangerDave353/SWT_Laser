// SWT_Laser.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "State.h"
#include "StateBereit.h"
#include "StateLaserAn.h"
#include "StateLaserAus.h"
#include "StateMove.h"
#include <iostream>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	char x;
	State *currentState = NULL;
	State *lastState = NULL;
	State *nextState = NULL;
	currentState = new StateBereit(0,0);	//Initalisierung des Grundzustands
	
	currentState->NextState(true);				//aufrufen der nächsten Zustände
	cin >> x;
	currentState->NextState(3,5);
	cin >> x;
	currentState->NextState(4,7);
	cin >> x;
	currentState->NextState(true);
	cin >> x;
	currentState->NextState(8,6);
	cin >> x;
	currentState->NextState(false);
	cin >> x;
	currentState->NextState(4,3);
	cin >> x;
	currentState->NextState(7,3);





	cin >> x;
	
	
	
	
	return 0;
}

