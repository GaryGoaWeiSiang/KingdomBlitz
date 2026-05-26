#include <iostream>
#include <graphics.h>
#include "System.hpp"
#include "GameManager.hpp"
#include "PointSystem.hpp"

using namespace std;

int PointSystem::getPoint(){
    return point;
}
void PointSystem::addPoint(int p){
    point += p;
}
void PointSystem::clearPoint(){
    point = 0;
}
