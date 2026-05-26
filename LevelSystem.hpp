#ifndef LEVELSYSTEM_HPP
#define LEVELSYSTEM_HPP
#include <iostream>
#include <graphics.h>

using namespace std;

class LevelSystem: public GameManager{
    private:
    int level=0;
    int experience=0;
    int maxExp;
    public:
    LevelSystem(int max=200);
    int getLevel();
    int getExp();
    void addLevel(int l=1);
    void addExp(int exp);
    void setMaxExp(int max);
    void clearLevel();
    int getMaxExp();
    int* getExpPointer();
};

#endif