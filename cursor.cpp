#include <iostream>
#include <graphics.h>
#include <cmath>
#include "UI.hpp"
#include "cursor.hpp"
using namespace std;

Cursor::Cursor(int x, int y):UI(x,y){}

Cursor::Cursor(int *x, int *y):UI(*x,*y){}

void Cursor::display(){
    drawpoly(4,coordinate);
}

void Cursor::getMouse(){
    mouseX=mousex();
    mouseY=mousey();
}

void Cursor::setCenter(int *x, int *y){
    positionX = *x;
    positionY = *y;
}

void Cursor::calculateAngle(){
    angle = atan2((mouseY-positionY),(mouseX-positionX));
    int moveX = positionX + static_cast<int>(radius * cos(angle));
    int moveY = positionY + static_cast<int>(radius * sin(angle));
    // Rotate and translate each point
    int triLocal[6] = {
        10, 0,    // Tip (pointing right)
        -10, -15,  // Bottom left
        -10,  15   // Top left
    };
        for (int i = 0; i < 3; i++) {
            int lx = triLocal[2*i];
            int ly = triLocal[2*i+1];

            double rx = lx * cos(angle) - ly * sin(angle);
            double ry = lx * sin(angle) + ly * cos(angle);

            coordinate[2*i]   = static_cast<int>(rx) + moveX;
            coordinate[2*i+1] = static_cast<int>(ry) + moveY;
        }
        coordinate[6] = coordinate[0];
        coordinate[7] = coordinate[1];
}

double Cursor::getAngle(){return angle;}