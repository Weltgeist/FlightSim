#include "Plane.h"

Plane::Plane()
{
    state_=GROUND;
    copy=new Input(); //(19853456575) - height, verspeed, AOA
    heightActual=0;
    verSpeedActual=0;
    powerActual=0;
}

Plane::~Plane()
{
    //dtor
}

void Plane::handleInput(Input *input){

switch(state_)
{
case GROUND:
    if(input->height>0){
        state_=FLIGHT;
        cout<<"state:FLIGHT"<<endl;
        sendParam(input);
    }
    else if(input->verSpeed>0&&input->AOA>0){
        state_=FLIGHT;
        cout<<"state:FLIGHT"<<endl;
        sendParam(input);
    }
    break;

case FLIGHT:
    if(heightActual==input->height){
        state_=CRUISE;
        cout<<"state:CRUISE"<<endl;
    }
    if(abs(input->AOA)>15){
        state_=FALL;
        cout<<"state:FALL"<<endl;
    }
    if(input->height!=copy->height){
        state_=FLIGHT;
        cout<<"state:FLIGHT"<<endl;
        sendParam(input);
    }
    break;
case FALL:
    if(heightActual<=0){
        state_=GROUND;
        cout<<"state:GROUND"<<endl;
    }
    if(abs(input->AOA)<=15){
        state_=FLIGHT;
        cout<<"state:FLIGHT"<<endl;
    }
    break;

case CRUISE:
    if(input->height!=copy->height){
        state_=FLIGHT;
        cout<<"state:FLIGHT"<<endl;
        sendParam(input);
    }
    break;


}


}
void Plane::update(){

switch(state_)
{
case GROUND:
    break;

case FLIGHT:
    heightActual+=verSpeedActual;
    cout<<heightActual<<endl;
    break;
case FALL:
    verSpeedActual=-200;
    heightActual+=verSpeedActual;
    cout<<heightActual<<endl;
    break;

case CRUISE:
    break;
}

}

void Plane::sendParam(Input * input){
verSpeedActual=input->verSpeed;
copy->height=input->height;

}
