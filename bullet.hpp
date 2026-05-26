#ifndef BULLET_HPP
#define BULLET_HPP
#include <iostream>
#include <graphics.h>
#include "Entities.hpp"
#include "animation.hpp"

using namespace std;

class Bullet: public Entities{
    private:
    int speed;
    int maxBullet=50;
    int l[4]={0,0,100,100};
    bool active=false;
    public:
    Animation a;
    Bullet();
    bool isActive();
    void setBullet(int a,int b);
    void setActive(bool state);
    void render();
    int* getBulletX();
    int* getBulletY();
    void shoot();
    bool isCollide(Entities *e);
};

#endif