#include "control.h"




Control::Control(MainWindow *w)
{

window=w;
letzterZustand=nullptr;
aktuellerZustand=nullptr;
naechsterZustand=nullptr;
window->setC(this);
}

void Control::naechstenBefehl()
{

}

void Control::ZustandAktualisieren()
{
letzterZustand=aktuellerZustand;
aktuellerZustand=naechsterZustand;

}

void Control::StartControl(string pfad)
{

parser = Parser(pfad);
BefehlsObjekt= parser.getBefehlsObjekt();
aktuellerZustand=new StateBereit(nullptr,window);
getKomandoAnzahl();
ControlBefehlsAusfuehrung();

}

void Control::ControlBefehlsAusfuehrung()
{
    /*
    Die Cases sind Global mit der gleichen Nummer versehen, deshalb hier nochmal -1 obwohl er hier nicht benutzt wird

    Cases:
        -2	- Kommentar oder Leerzeile
        -1	- EoF
        0	- Fehler
        1	- Laser
        2	- Move
    */

    parser.naechsteZeile(); // wird einmal ausgeführt um bei zeile 1 zu starten
    do
    {
        switch(BefehlsObjekt->getBefehlNr())
        {
        case '-2':break; //Kommentare und leere Zeilen werden ignoriert

        case '0': break;  //Fehler werden momentan noch ignoriert
                        //Können aber in späteren Versionen abgefangen werden


        case '1':       //Laser wird An oder Aus geschaltet
            if(BefehlsObjekt->getLaser())
            {
                naechsterZustand = aktuellerZustand->ON();
                ZustandAktualisieren();
            }
            else
            {
                naechsterZustand =aktuellerZustand->OFF();
                ZustandAktualisieren();
                naechsterZustand=aktuellerZustand->Bereit();
                ZustandAktualisieren();
            }
            break;

        case '2':       //Ein Move befehl wurd gelesen, wenn der Laser An ist bleibt der Zustandsautomat im StateMove
                        //ist der Laser Aus folgt der StateBereit

            naechsterZustand =aktuellerZustand->Move(BefehlsObjekt->getX(),BefehlsObjekt->getY());
            ZustandAktualisieren();
            if(BefehlsObjekt->getLaser()==false)
            {
                naechsterZustand=aktuellerZustand->Bereit();
                ZustandAktualisieren();
            }
            break;
        default:break;
        }


        parser.naechsteZeile();
    }while(BefehlsObjekt->getBefehlNr()==-1);
}

void Control::BefehlsObjektUebergeben()
{

}


void Control::getKomandoAnzahl()
{

window->GuiSetProgressBar(parser.getAnzahlBefehle());

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

