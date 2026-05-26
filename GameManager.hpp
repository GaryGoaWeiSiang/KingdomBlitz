#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include <iostream>
#include <graphics.h>
#include "System.hpp"

using namespace std;

class GameManager: public System{
    private:
    bool gameRun;
    public:
    void isGameRun(bool gr);
};

#endif