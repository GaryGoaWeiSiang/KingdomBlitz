#ifndef CURSOR_HPP
#define CURSOR_HPP
#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

class Cursor: public UI{
    private:
        double angle, radius=50;
        int centerX, centerY;
        int mouseX, mouseY;
        int coordinate[8] = {0};
    public:
        Cursor(int x=getmaxwidth()/2,int y=getmaxheight()/2);
        Cursor(int *x,int *y);
        void setCenter(int *x ,int *y);
        void display();
        void getMouse();
        void calculateAngle();
        double getAngle();
};

#endif