#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <graphics.h>
#include "animation.hpp"
#include "input.hpp"
#include "cursor.hpp"
#include "UI.hpp"
#include "LevelSystem.hpp"
#include "Entities.hpp"
#include "bullet.hpp"

class Player: public Entities{
    private:
    int hp;
    int damage;
    bool Dead;
    int currentLevel;
    static void* imageBuffer;
    static bool imageLoaded;
    protected:
    Animation a;
    public:
    Bullet b[50];
    LevelSystem l;
    Input i;
    Cursor cu;
    Player();
    void loadImage();
    void display();
    void move();
    void shoot(int index);
    bool isCollide(Entities *e);
    bool isDead();
    void countLevel();
    void powerUp();
    int getDamage();
    int getHp();
    void decreaseHp(int dh);
    void reset();
    int* getHpPointer();
    //void resolveCollision(Entities *w,int dx, int dy);
    void resolveCollision(Entities *w);
};

#endif