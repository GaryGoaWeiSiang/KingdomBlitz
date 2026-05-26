#include <iostream>
#include <graphics.h>
#include "System.hpp"
#include "GameManager.hpp"
#include "LevelSystem.hpp"

using namespace std;

LevelSystem::LevelSystem(int max): maxExp(max){}

int LevelSystem::getLevel(){
    return level;
}
int LevelSystem::getExp(){
    return experience;
}
void LevelSystem::addLevel(int l){
    level+=l;
}
void LevelSystem::addExp(int exp){
    experience+=exp;
    while(experience>=maxExp){
        addLevel();
        experience-=maxExp;
        maxExp+=100;
    }
}
void LevelSystem::setMaxExp(int max){
    maxExp = max;
}
void LevelSystem::clearLevel(){
    experience = 0;
    level = 0;
}
int LevelSystem::getMaxExp(){
    return maxExp;
}
int* LevelSystem::getExpPointer(){
    return &experience;
}