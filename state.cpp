#include "state.h"
/*
In State wird die Oberklasse für die einzelnen späteren Zustände definiert
Alle andern Zustände sind von dieser Klasse abgeleitet und beinhalten die selben
Methoden und Attribute
Die Methoden Move, Bereit, ON und OFF werden aufgerufen um in den nächsten Zustand zu wechseln, dabei geben
sie einen Pointer auf den erstellten Zustand zurück.
die restlichen Methoden sind Getter und Setter Methoden für die Attribute.
*/

State *State::Move(int x, int y)
{
return nullptr;
}

State *State::Bereit()
{
return nullptr;
}

State *State::ON()
{
return nullptr;
}

State *State::OFF()
{
return nullptr;
}

int State::getKoordinateY() const
{
    return KoordinateY;
}

void State::setKoordinateY(int value)
{
    KoordinateY = value;
}

int State::getKoordinateX() const
{
    return KoordinateX;
}

void State::setKoordinateX(int value)
{
    KoordinateX = value;
}

bool State::getLaserZustand() const
{
    return LaserZustand;
}

void State::setLaserZustand(bool value)
{
    LaserZustand = value;
}
