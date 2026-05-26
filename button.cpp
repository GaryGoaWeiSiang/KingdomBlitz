#include <iostream>
#include <graphics.h>
#include <cmath>
#include "UI.hpp"
#include "button.hpp"
using namespace std;

Button::Button(int x,int y, int h, int w,string n): UI(x,y), height(h), width(w),name(n){}
void Button::display(){
    moveto(positionX,positionY);
    int Rectangle[10]={positionX,positionY,positionX+width,positionY,positionX+width,positionY+height,positionX,positionY+height};
    Rectangle[8]=Rectangle[0];
    Rectangle[9]=Rectangle[1];
    drawpoly(5,Rectangle);
    setfillstyle(11,WHITE);
    floodfill(positionX+5,positionY+5,WHITE);
    bgiout<<name;
    outstreamxy((positionX+positionX+width-45)/2,(positionY+positionY+height-15)/2,bgiout);
}
bool Button::isButtonPressed(){
    if(ismouseclick(WM_LBUTTONDOWN)){
        mouseX=mousex();
        mouseY=mousey();
    if (mouseX>=positionX&&mouseX<=(positionX+width)&&mouseY>=positionY&&mouseY<=(positionY+height))
        return true;}
    return false;
}

void Button::setButton(int x, int y, int h, int w, string n){
    positionX = x;
    positionY = y;
    height = h;
    width = w;
    name = n;
}