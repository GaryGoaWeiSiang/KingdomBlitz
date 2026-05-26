#ifndef WALL_HPP
#define WALL_HPP
#include <iostream>
#include <graphics.h>

using namespace std;

class Wall: public Entities{
    public:
    Wall(int x=0, int y=0,int w=getmaxwidth(),int h=5);
    bool isCollide(Entities* e);
};

#endif