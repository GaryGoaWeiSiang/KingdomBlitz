#ifndef POINTSYSTEM_HPP
#define POINTSYSTEM_HPP
#include <iostream>
#include <graphics.h>

using namespace std;

class PointSystem: public GameManager{
    private:
    int point;
    public:
    int getPoint();
    void addPoint(int p);
    void clearPoint();
};

#endif