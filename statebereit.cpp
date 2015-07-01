#include "statebereit.h"
#include "statelaseran.h"
#include "statelaseraus.h"
#include "statemove.h"
#include "control.h"
#include "main.h"


using namespace std;

StateBereit::StateBereit(State* state, Ui::Main *ui)
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
        KoordinateX=state->getX();
        KoordinateY=state->getY();
    }

GUI->LaserAN();

}

State* StateBereit::Move(int x, int y)
{
    cout<<"StateBereit->MOVE"<<endl;
    return new StateMove(x,y,this,GUI);
}

State* StateBereit::Bereit()
{
    return new StateBereit(this,GUI);
}

State* StateBereit::ON()
{

    return new StateLaserAn(this,GUI);

}

State* StateBereit::OFF()
{
    return new StateBereit(this,GUI);
}
