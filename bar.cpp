#include <iostream>
#include <graphics.h>
#include "UI.hpp"
#include "bar.hpp"
using namespace std;

Bar::Bar(int px, int py, int bh, int bw, int c): UI(px,py), barHeight(bh), barWidth(bw), colour(c){}
void Bar::display(){
    setfillstyle(1,BLACK);
    bar3d(positionX,positionY,positionX+barWidth,positionY+barHeight,0,0);
    setfillstyle(11,colour);
    bar3d(positionX,positionY,positionX+barWidth,positionY+barHeight,1,0);
}
void Bar::updateBar(){
    setfillstyle(1,BLACK);
    bar3d(positionX,positionY,positionX+barWidth,positionY+barHeight,0,0);
    setfillstyle(11,colour);
    bar3d(positionX,positionY,positionX+(int)(barWidth*((double)*currentValue/value)),positionY+barHeight,1,1);
}
void Bar::setValue(int v){
    value= v;
}
void Bar::setCurrentValue(int *cv){
    currentValue = cv;
}