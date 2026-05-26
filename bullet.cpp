#include <iostream>
#include <graphics.h>
#include "animation.hpp"
#include "Entities.hpp"
#include "CollisionSystem.hpp"
#include "bullet.hpp"

using namespace std;

Bullet::Bullet(){
    setDimension(10,5);
    c.update(&l[2],&l[3]);
}
void Bullet::setBullet(int a, int b){l[0] = a; l[1] = b;}
void Bullet::shoot(){
    a.calcShoot(l);
    c.update(&l[2],&l[3]);
    if(*(getBulletX())<=0||*(getBulletX())>=getmaxwidth()||*(getBulletY())<=0||*(getBulletY())>=getmaxheight()){
        active = false;
    }
}
void Bullet::render(){
    a.shoot(l);
}
void Bullet::setActive(bool state) { active = state; }
bool Bullet::isCollide(Entities *e){
    return c.isHit(e->getX(),e->getY(),e->getWidth(),e->getHeight());
}
bool Bullet::isActive(){return active;}
int* Bullet::getBulletX(){return &l[2];}
int* Bullet::getBulletY(){return &l[3];}
