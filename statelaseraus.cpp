#include "statelaseraus.h"
#include "state.h"
#include "statebereit.h"
#include "control.h"
#include "main.h"

using namespace std;

StateLaserAus::StateLaserAus(State* state, Ui::Main *ui)
{
    GUI=ui;
    if(state==nullptr)
    {
    LaserZustand=false;
    KoordinateX=0;
    KoordinateY=0;
    }
    else
    {
        LaserZustand=false;
        KoordinateX=state->getX();
        KoordinateY=state->getY();
    }
}

State* StateLaserAus::Move(int x, int y)
{
    cout<<"LaserAUS->MOVE"<<endl;
    return new StateLaserAus(this,GUI);
}

State* StateLaserAus::Bereit()
{
    return new StateLaserAus(this,GUI);
}

State* StateLaserAus::ON()
{
    return new StateLaserAus(this,GUI);
}

State* StateLaserAus::OFF()
{
return new StateLaserAus(this,GUI);
}

