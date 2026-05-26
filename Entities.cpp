#include <iostream>
#include <graphics.h>
#include "Entities.hpp"
#include "CollisionSystem.hpp"

using namespace std;

Entities::Entities(){}
Entities::Entities(int x, int y,int w,int h):positionX(x),positionY(y),width(w),height(h){
    c.createHitbox(x,y,w,h);
}
//bool Entities::isCollide(Entities *e)=0;
int Entities::getX(){
    return positionX;
}
int* Entities::pointX(){
    return &positionX;
}
int Entities::getY(){
    return positionY;
}
int* Entities::pointY(){
    return &positionY;
}
int Entities::getWidth(){
    return width;
}
int Entities::getHeight(){
    return height;
}
void Entities::setDimension(int w,int h){width=w;height=h;}