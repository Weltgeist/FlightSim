#include <iostream>
#include "include/Input.h"
#include "include/Plane.h"
#include <unistd.h>

using namespace std;


int main()
{
        //1-Created Variables
    Input inp;
    Plane plane;
        //2-Initialize inputs
    inp.height=40000; //kms
    inp.AOA=8;//degrees
    inp.verSpeed=50;//kms/h
        //3-Pass Inputs

    for(int i=0;i<1000;i++){
    if(i%100==0){
    cout<<"Give me a height:"<<endl;
    cin>>inp.height;
    cout<<"Give me a AOA:"<<endl;
    cin>>inp.AOA;
    cout<<"Give me a VS:"<<endl;
    cin>>inp.verSpeed;
    }
    plane.handleInput(&inp);
        //4-Update internal state
    plane.update();
    usleep(5000);
        }

    return 0;
}
