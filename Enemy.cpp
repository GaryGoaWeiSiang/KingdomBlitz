#include <iostream>
#include <graphics.h>

#include "Entities.hpp"
#include "CollisionSystem.hpp"
#include "SpawnSystem.hpp"
#include "Enemy.hpp"
#include "animation.hpp"
#include "bullet.hpp"

using namespace std;

Enemy::Enemy(int *x,int *y, int exp, int point,int health, int dmg,int w,int h,bool boss,const string &img):Entities(0,0,w,h),imagePath(img),imageBuffer(nullptr),imageLoaded(false){
    if(!boss){
    s.spawnEnemies(x,y,pointX(),pointY());}
    else{
        *(pointX())=getmaxwidth()/2-50;
        *(pointY())=getmaxheight()/2-50;
    }
    c.update(pointX(),pointY());
    targetX = x;
    targetY = y;
    dropExp = exp;
    pointGain = point;
    hp = health;
    damage = dmg;
    Dead = false;
    for(int i = 0; i < 50; ++i){
    b[i].setActive(false);
    b[i].setBullet(-100, -100);
    }
}


void Enemy::loadImage() {
    if (!imageLoaded) {
        imageBuffer = malloc(imagesize(0, 0, getWidth(), getHeight()));
        readimagefile(imagePath.c_str(), 0, 0, getWidth(), getHeight());
        getimage(0, 0,getWidth(), getHeight(), imageBuffer);
        imageLoaded = true;
        cleardevice(); // Clear temp image load area
    }
}

void Enemy::display() {
    if (imageBuffer) {
        putimage(getX(), getY(), imageBuffer, COPY_PUT);
    }
}

//void Enemy::display(){readimagefile("Mushroom.jpg",getX(),getY(),getX()+getWidth(),getY()+getHeight());}

void Enemy::calcAngle(){angle = atan2((*targetY+17-getY()),(*targetX+8-getX()));}

void Enemy::move(){
    calcAngle();
    a.walk(pointX(),pointY(),angle);
    display();
}

void Enemy::shoot(int index){
    b[index].a.setAngle(angle);
    b[index].a.setSpeed(25);
    b[index].setBullet(getX(),getY());
    b[index].setActive(true);
}
    

bool Enemy::isCollide(Entities *e){return c.isHit(e->getX(),e->getY(),e->getWidth(),e->getHeight());}

bool Enemy::isDead(){
    return (hp<=0);
}

int Enemy::getPointGain(){
    return pointGain;
}

int Enemy::getDropExp(){
    return dropExp;
}

void Enemy::decreaseHp(int dh){
    hp -= dh;
    Dead = isDead();
}

void Enemy::resetHp(){
    hp = 100;
}

int* Enemy::getHp(){
    return &hp;
}

int Enemy::getDamage(){
    return damage;
}
