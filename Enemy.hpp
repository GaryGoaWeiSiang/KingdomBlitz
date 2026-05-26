#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>
#include <graphics.h>
#include "animation.hpp"
#include "UI.hpp"
#include "Entities.hpp"
#include "bullet.hpp"
#include "SpawnSystem.hpp"

class Enemy: public Entities{
    private:
    int hp;
    int damage;
    int pointGain,dropExp;
    bool Dead;
    int currentLevel;
    int *targetX; int *targetY;
    double angle;
    void* imageBuffer;
    bool imageLoaded;
    string imagePath;
    protected:
    Animation a;
    public:
    SpawnSystem s;
    Bullet b[50];
    Enemy(int* x=NULL, int* y=NULL,int exp=100,int point=100,int health=100,int dmg=1, int w=20, int h=40,bool boss=false,const string &img="Mushroom.jpg");
    void loadImage();
    void display();
    void calcAngle();
    void move();
    void shoot(int index);
    bool isCollide(Entities *e);
    bool isDead();
    int getPointGain();
    int getDropExp();
    void decreaseHp(int dh);
    void resetHp();
    int* getHp();
    int getDamage();
};

#endif