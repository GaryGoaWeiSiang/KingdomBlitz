#include <iostream>
#include <graphics.h>
#include "System.hpp"
#include "Scene.hpp"
#include "Menu.hpp"

using namespace std;

Menu::Menu():Scene(),b1(getmaxwidth()/2-90,(getmaxheight()/2)+50,50,100,(string)"Start"),b2(getmaxwidth()/2+50,(getmaxheight()/2)+50,50,100,(string)"Quit"),b3(0,0),b4(0,0){}
Menu::Menu(string i): Scene(i),b1(getmaxwidth()/2-90,(getmaxheight()/2)+50,50,100,(string)"Start"),b2(getmaxwidth()/2+50,(getmaxheight()/2)+50,50,100,(string)"Quit"),b3(0,0),b4(0,0){}
void Menu::updateScene(Scene *s){
    s->loadBackground();
    s->setCurrentScene(true);
    setCurrentScene(false);
}
void Menu::displayText(){}
