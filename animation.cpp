#include <graphics.h>
#include <cmath>
#include "UI.hpp"
#include "animation.hpp"
using namespace std;

void Animation::walk(int *x,int *y,double an){
    double sp = 5;
    *x += sp * cos(an);
    *y += sp * sin(an);
}

void Animation::walk(int *x, int *y, char key){
    positionX = *x; positionY =*y;
    int s = 10;
    switch (key){
        case 'w': *y-=s;break;//moverel(0,-5); break;
        case 'a': *x-=s;break;//moverel(-5,0); break;
        case 's': *y+=s;break;//moverel(0,5); break;
        case 'd': *x+=s;break;//moverel(5,0); break;
    }
}
void Animation::calcShoot(int l[]){
    l[0] += speed * cos(angle);
    l[1] += speed * sin(angle);
    l[2] = l[0] + radius * cos(angle);
    l[3] = l[1] + radius * sin(angle);
}

void Animation::shoot(int l[]){
    line(l[0],l[1],l[2],l[3]);
}
        
void Animation::hit(bool &h,int &c){
    if (h) {
        blinkCounter++;
    if ((blinkCounter / 10) % 2 == 0) {
        c = RED;
    } 
    else {
        c = WHITE;
    }

    if (blinkCounter > duration) {
        h = false;
        blinkCounter = 0;
        c = WHITE;
    }
    }
}
void Animation::death(bool &d, int &c){
    if(d) c = BLACK;
}

void Animation::setAngle(double an){
    angle = an;
}
void Animation::setSpeed(double sp){
    speed = sp;
}