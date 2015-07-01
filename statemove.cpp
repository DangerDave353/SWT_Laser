#include "statemove.h"
#include "state.h"
#include "statebereit.h"
#include "statelaseraus.h"
#include "control.h"
#include "main.h"

using namespace std;

StateMove::StateMove(int x, int y, State* state,Ui::Main *ui)
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
        LaserZustand=state->getLaser();
        KoordinateX=x;
        KoordinateY=y;
    }

}

State* StateMove::Bereit()
{
return new StateMove(KoordinateX, KoordinateY,this,GUI);
}

State* StateMove::ON()
{
return new StateMove(KoordinateX, KoordinateY,this,GUI);
}

State* StateMove::OFF()
{
   return  new StateLaserAus(this, GUI);
}

State* StateMove::Move(int x,int y)
{
cout<<"LaserMOVE->MOVE"<<endl;
return new StateMove(x,y,this,GUI);
}


