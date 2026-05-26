#ifndef ENTITIES_HPP
#define ENTITIES_HPP
#include <iostream>
#include <graphics.h>
#include "CollisionSystem.hpp"

using namespace std;

class Entities{
    private:
    int width=20, height=50;
    bool collide;
    protected:
    int positionX=0,positionY=0;
    public:
    CollisionSystem c;
    Entities();
    Entities(int x, int y,int w,int h);
    virtual bool isCollide(Entities *e)=0;
    int getX();
    int* pointX();
    int getY();
    int* pointY();
    int getWidth();
    int getHeight();
    void setDimension(int w,int h);
};

#endif
