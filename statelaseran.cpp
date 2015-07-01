#include "statelaseran.h"
#include "state.h"
#include "statebereit.h"
#include "statelaseraus.h"
#include "statemove.h"
#include "control.h"
#include "main.h"
using namespace std;

StateLaserAn::StateLaserAn(State* state, Ui::Main *ui)
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
        LaserZustand=true;
        KoordinateX=state->getX();
        KoordinateY=state->getY();

    }
}

State* StateLaserAn::Move(int x, int y)
{
    cout<<"StateLaserAn->Move("<<x<<","<<y<<")"<<endl;
    return new StateMove(x,y,this,GUI);
}

State* StateLaserAn::Bereit()
{
    return new StateLaserAn(this,GUI);
}

State* StateLaserAn::ON()
{
return new StateLaserAn(this,GUI);
}

State* StateLaserAn::OFF()
{
    return new StateLaserAus(this,GUI);
}

