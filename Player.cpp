#include <iostream>
#include <graphics.h>
#include "Entities.hpp"
#include "CollisionSystem.hpp"
#include "Player.hpp"
#include "animation.hpp"
#include "input.hpp"
#include "cursor.hpp"
#include "LevelSystem.hpp"
#include "bullet.hpp"

using namespace std;

void* Player::imageBuffer=nullptr;
bool Player::imageLoaded=false;

Player::Player(): Entities(getmaxwidth()/2,getmaxheight()/2,15,35){
    cu.setCenter(pointX(), pointY());
    currentLevel = l.getLevel();
    damage = 5;
    Dead = false;
    hp = 100;
}

void Player::loadImage() {
    if (!imageLoaded) {
        imageBuffer = malloc(imagesize(0, 0, getWidth(), getHeight()));
        readimagefile("player.jpg", 0, 0, getWidth(), getHeight());
        getimage(0, 0,getWidth(), getHeight(), imageBuffer);
        cleardevice();
        imageLoaded = true;
    }
}
void Player::display() {
    if (imageBuffer) {
        putimage(getX(), getY(), imageBuffer, COPY_PUT);
    }
}

void Player::move(){
        i.getKey();
        if(i.isKey('w')){
            a.walk(pointX(),pointY(),'w');
        }
        if(i.isKey('a')){
            a.walk(pointX(),pointY(),'a');
        }
        if(i.isKey('s')){
            a.walk(pointX(),pointY(),'s');
        }
        if(i.isKey('d')){
            a.walk(pointX(),pointY(),'d');
        }
    c.update(pointX(), pointY());
}
void Player::shoot(int index){
    b[index].setBullet(getX(),getY());
    b[index].a.setAngle(cu.getAngle());
    b[index].a.setSpeed(100);
    b[index].setActive(true);
}
    

bool Player::isCollide(Entities *e){return c.isHit(e->getX(),e->getY(),e->getWidth(),e->getHeight());}
bool Player::isDead(){
    if (hp<=0) {
        return Dead=true;
    }
    else {
        return Dead=false;
    }
}
void Player::countLevel(){
    l.clearLevel();
}
void Player::powerUp(){
    if(currentLevel!=l.getLevel()){
        currentLevel = l.getLevel();
        hp = 100;
        damage += 5;
    }
}

int Player::getDamage(){
    return damage;
}

int Player::getHp(){
    return hp;
}

void Player::decreaseHp(int dh){
    hp -= dh;
}

void Player::reset(){
    hp = 100;
    damage = 5;
    for(int i=0;i<50;i++){
        b[i].setActive(false);
    }
}

int* Player::getHpPointer(){
    return &hp;
}

void Player::resolveCollision(Entities *w) {
    int px = getX();
    int py = getY();
    int pw = getWidth();
    int ph = getHeight();

    int wx = w->getX();
    int wy = w->getY();
    int ww = w->getWidth();
    int wh = w->getHeight();

    int pxCenter = px + pw / 2;
    int pyCenter = py + ph / 2;
    int wxCenter = wx + ww / 2;
    int wyCenter = wy + wh / 2;

    int dx = (px + pw / 2) - (wx + ww / 2);
    int dy = (py + ph / 2) - (wy + wh / 2);

    int combinedHalfWidths = pw / 2 + ww / 2;
    int combinedHalfHeights = ph / 2 + wh / 2;

    int overlapX = combinedHalfWidths - abs(dx);
    int overlapY = combinedHalfHeights - abs(dy);

    if (overlapX > 0 && overlapY > 0) {
        // Collision detected
        if (overlapX < overlapY) {
            if (dx > 0)
                *pointX() += overlapX;
            else
                *pointX() -= overlapX;
        } else {
            if (dy > 0)
                *pointY() += overlapY;
            else
                *pointY() -= overlapY;
        }
    }
    c.update(pointX(), pointY());
}