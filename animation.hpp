#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <graphics.h>
#include <cmath>
#include "UI.hpp"
using namespace std;

class Animation:public UI{
    private:
        int movementX,movementY;
        double angle=-100;
        int centerX=getmaxwidth()/2,centerY=getmaxheight()/2;
        double radius=10;
        int colour;
        int blinkCounter=0, duration=100;
        double speed = 0.1;
    public:
        void setAngle(double an);
        void setSpeed(double sp);
        void walk(int *x, int *y, double an);
        void walk(int *x, int *y, char key);
        void calcShoot(int l[]);
        void shoot(int l[]);
        void hit(bool &h,int &c);
        void death(bool &d, int &c);
};

#endif
