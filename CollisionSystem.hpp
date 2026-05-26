#ifndef COLLISIONSYSTEM_HPP
#define COLLISIONSYSTEM_HPP
#include <iostream>
#include <graphics.h>
#include "GameManager.hpp"

class CollisionSystem: public GameManager{
    private:
    int positionX,positionY;
    int width,height;
    bool Hit;
    public:
    void createHitbox(int x, int y,int w, int h);
    void update(int *x, int *y);
    bool isHit(int x,int y,int w=0, int h=0);
};

#endif