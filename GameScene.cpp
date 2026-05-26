#include <iostream>
#include <graphics.h>
#include "System.hpp"
#include "Scene.hpp"
#include "GameScene.hpp"
#include "Wall.hpp"
#include "button.hpp"

using namespace std;

GameScene::GameScene():Scene(),b1(10,30,30,200,GREEN),b2(10,60,10,170,BLUE),b3(50,getmaxheight()-40,30,500,GREEN),text((string)"",getmaxwidth()/2,10)
    ,w1(),w2(getmaxwidth()-10,0,10,getmaxheight()),w3(0,getmaxheight()-5,getmaxwidth(),5),w4(0,0,10,getmaxheight())
    ,b(getmaxwidth()/2-30,(getmaxheight()/2)+50,50,100,(string)"Quit"){}
GameScene::GameScene(char* i):Scene(i),b1(10,30,30,200,GREEN),b2(10,60,10,170,BLUE),b3(50,getmaxheight()-40,30,500,GREEN),text((string)"",getmaxwidth()/2,10)
    ,w1(),w2(getmaxwidth()-10,0,10,getmaxheight()),w3(0,getmaxheight()-5,getmaxwidth(),5),w4(0,0,10,getmaxheight())
    ,b(getmaxwidth()/2-30,(getmaxheight()/2)+50,50,100,(string)"Quit"){}
void GameScene::updateScene(Scene *s){
    s->setCurrentScene(true);
    setCurrentScene(false);
}
