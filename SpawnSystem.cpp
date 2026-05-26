#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <random>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#include <cmath>
#include "System.hpp"
#include "GameManager.hpp"
#include "SpawnSystem.hpp"


using namespace std;

void SpawnSystem::spawnEnemies(int *playerX,int *playerY, int *x,int *y){
        double angle = ((double)rand()/RAND_MAX) * 2.0 * M_PI;
        /*static std::mt19937 rng(std::random_device{}());
        static std::uniform_real_distribution<double> angle_dist(0, 2 * M_PI);
        double angle = angle_dist(rng);*/
        radius = 100 + rand()%600;
        *x = *playerX + radius*cos(angle);
        *y = *playerY + radius*sin(angle);
        
        int enemyWidth = 20;  // or whatever your enemy width is
        int enemyHeight = 40;
        *x = max(0, min(getmaxwidth() - enemyWidth, *x));
        *y = max(0, min(getmaxheight() - enemyHeight, *y));
}

void SpawnSystem::setMax(int max){
    maxSpawn = max;
}

int SpawnSystem::getMax(){
    return maxSpawn;
}
