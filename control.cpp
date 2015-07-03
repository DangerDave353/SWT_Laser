#include "control.h"


Control::Control( Ui::MainWindow *ui)
{
    GUI=ui;
letzterZustand=nullptr;
aktuellerZustand=nullptr;
naechsterZustand=nullptr;

}

void Control::naechstenBefehl()
{

}

void Control::ZustandAktualisieren()
{
letzterZustand=aktuellerZustand;
aktuellerZustand=naechsterZustand;

}

void Control::StartControl()
{

aktuellerZustand=new StateBereit(nullptr,GUI);
getKomandoAnzahl();
naechsterZustand=aktuellerZustand->ON();

}


void Control::getKomandoAnzahl()
{
int X=10;
    //Befehle vom Parser holen
    GUI->GuiSetProgressBar(X);


}



State *Control::getAktuellerZustand() const
{
    return aktuellerZustand;
}

void Control::setAktuellerZustand(State *value)

{
    aktuellerZustand = value;
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
