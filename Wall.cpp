#include <iostream>
#include <graphics.h>
#include "Entities.hpp"
#include "Wall.hpp"
#include "CollisionSystem.hpp"

using namespace std;

Wall::Wall(int x, int y,int w,int h): Entities(x,y,w,h){c.createHitbox(x,y,w,h);}
bool Wall::isCollide(Entities* e){return c.isHit(e->getX(),e->getY());}