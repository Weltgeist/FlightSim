#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "constant.h"
#include "Input.h"

using namespace std;

class Plane
{
    private:

    State state_;
    Input* copy;
    int heightActual;//distance travel
    int verSpeedActual;
    int powerActual;




    public:
        Plane();
        virtual ~Plane();

    void handleInput(Input *input);
    void update();
    void sendParam(Input *input);




};

#endif // PLANE_H
