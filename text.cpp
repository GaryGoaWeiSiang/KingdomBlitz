#include <iostream>
#include <graphics.h>
#include "UI.hpp"
#include "text.hpp"
using namespace std;

Text::Text(string s,int x, int y): UI(x,y), text(s){}
void Text::display(){
    bgiout<<text;
    outstreamxy(positionX,positionY);
    delay(duration);
    cleardevice();
}
void Text::setText(string t){
    text = t;
}

