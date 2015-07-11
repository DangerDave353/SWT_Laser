/*
Die Klasse Control steuert alles, sie holt die Befehle aus dem Parser, wechselt die Zustände
der Statemaschine und gibt die anweisungen an die GUI(MainWindow).


*/
#include "control.h"
#include "statebereit.h"
#include "statelaseran.h"
#include "statelaseraus.h"
#include "statemove.h"



//Im Konstructor werden die Zustände auf NULL gesetzt und das MainWindow übergeben
//ebenfalls wird dem MainWindow das Control Objekt übergeben, damit die beiden sich gegeseitig kennen.
Control::Control(MainWindow *w)
{

window=w;
letzterZustand=nullptr;
aktuellerZustand=nullptr;
naechsterZustand=nullptr;
window->setC(this);
window->ResetProgressBar();
}

//Hier werden die Zustäde weiter gegeben nachdem naechsterZustand zugewiesen wurde
void Control::ZustandAktualisieren()
{
letzterZustand=aktuellerZustand;
aktuellerZustand=naechsterZustand;

}

//Dies ist der eigentliche Programm Start, dieser wird durch einen klick auf den "Start"-Knopf
//ausgelöst, gleichzeitig wird der Pfad aus deR TextBox geholt und übergeben.
//Mit diesem Pfad wird der Parser erzeugt und gestartet. Auch die übergabe der Anzalh aller Befehle
//aus der Datei an den ProgressBar erfolg hier.
void Control::StartControl(std::string pfad)
{

parser = Parser(pfad);
BefehlsObjekt= parser.getBefehlsObjekt();
aktuellerZustand=new StateBereit(nullptr,window);
getKomandoAnzahl();
if(BefehlsObjekt->getFehler()!="")
{
window->FehlerAusgabe(BefehlsObjekt->getFehler());
}
else
    ControlBefehlsAusfuehrung();
}

void Control::ControlBefehlsAusfuehrung()
{
    window->SetStartButton(false);
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
        case -2:break; //Kommentare und leere Zeilen werden ignoriert

        case 0: break;  //Fehler werden momentan noch ignoriert
                        //Können aber in späteren Versionen abgefangen werden


        case 1:       //Laser wird An oder Aus geschaltet
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
            window->GuiAddProgressBar();
            break;

        case 2:       //Ein Move befehl wurd gelesen, wenn der Laser An ist bleibt der Zustandsautomat im StateMove
                        //ist der Laser Aus folgt der StateBereit

            naechsterZustand =aktuellerZustand->Move(BefehlsObjekt->getX(),BefehlsObjekt->getY());
            ZustandAktualisieren();
            if(BefehlsObjekt->getLaser()==false)
            {
                naechsterZustand=aktuellerZustand->Bereit();
                ZustandAktualisieren();
            }
            window->GuiAddProgressBar();
            break;
        default:break;
        }


        parser.naechsteZeile();
    }while(BefehlsObjekt->getBefehlNr()!=-1);
    window->SetStartButton(true);
}



void Control::getKomandoAnzahl()
{

window->GuiSetProgressBar(parser.getAnzahlBefehle());
std::cout<<"Anzahl Befehle = "<<parser.getAnzahlBefehle()<<std::endl;
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

