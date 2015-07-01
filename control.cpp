#include "control.h"
#include "state.h"
#include "statebereit.h"
#include "main.h"

using namespace std;




void Control::setUi(Ui::Main *value)
{
    ui = value;
}
Control::Control()
{

    aktuellerZustand = nullptr;
    letzterZustand= nullptr;
naechsterZustand=nullptr;
aktuellerZustand = new StateBereit(aktuellerZustand,ui );

}

void Control::naechstenBefehl()
{
    //nächsten Befehl vom Parser holen
}

void Control::ZustandAktualisieren()
{
    letzterZustand=aktuellerZustand;
    aktuellerZustand=naechsterZustand;
}

int Control::getKomandoAnzahl()
{
    //Anzahl der Komandos von Parser abfragen, für den progressBar
    AnzahlBefehle=10;
    return AnzahlBefehle;
}

void Control::StartControl()
{
    naechsterZustand=aktuellerZustand->ON();
    ZustandAktualisieren();

    naechsterZustand=aktuellerZustand->Move(10,10);
    ZustandAktualisieren();
}



State *Control::getNaechsterZustand() const
{
    return naechsterZustand;
}

void Control::setNaechsterZustand(State *value)
{
    naechsterZustand = value;
}

State *Control::getLetzterZustand() const
{
    return letzterZustand;
}

void Control::setLetzterZustand(State *value)
{
    letzterZustand = value;
}

State *Control::getAktuellerZustand() const
{
    return aktuellerZustand;
}

void Control::setAktuellerZustand(State *value)
{
    aktuellerZustand = value;
}






