#ifndef SPAWNSYSTEM_HPP
#define SPAWNSYSTEM_HPP
#include <iostream>
#include <graphics.h>
#include <random>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class SpawnSystem: public GameManager{
    private:
    int radius;
    int spawnX;
    int spawnY;
    int numSpawn=0;
    int maxSpawn=50;
    public:
    void spawnEnemies(int *playerX,int *playerY, int *x,int *y);
    void setMax(int max);
    int getMax();
};

#endif