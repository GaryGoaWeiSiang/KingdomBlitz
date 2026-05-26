#include <iostream>
#include <graphics.h>
#include "System.hpp"
#include "GameManager.hpp"
#include "CollisionSystem.hpp"

using namespace std;

void CollisionSystem::createHitbox(int x, int y,int w, int h){
    positionX=x;
    positionY=y;
    width=w;
    height=h;
}
void CollisionSystem::update(int *x, int *y){
    positionX=*x;
    positionY=*y;
}
bool CollisionSystem::isHit(int x,int y, int w, int h){
    if((x+w>=positionX&&x<=positionX+width&&y+h>=positionY&&y<=positionY+height)){
        Hit = true;
    }
    else Hit = false;
    return Hit;
}