#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP
#include <iostream>
#include <graphics.h>
#include <vector>
#include "Enemy.hpp"
#include "Player.hpp"
#include "TimerSystem.hpp"
#include "PointSystem.hpp"
#include "text.hpp"
#include "bar.hpp"
#include "Scene.hpp"
#include "Wall.hpp"
#include "button.hpp"

using namespace std;

class GameScene: public Scene{
    private:
    public:
    Player p;
    vector<Enemy> e;
    vector<Enemy> e2;
    vector<Enemy> e3;
    vector<Enemy> boss;
    Bar b1;
    Bar b2;
    Bar b3;
    TimerSystem t;
    PointSystem point;
    Wall w1;
    Wall w2;
    Wall w3;
    Wall w4;
    Text text;
    Button b;
    GameScene();
    GameScene(char* i);
    void updateScene(Scene *s);
};

#endif