#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <iostream>
#include <graphics.h>
#include <cmath>
#include "UI.hpp"
using namespace std;

class Button:public UI{
    private:
        int height,width;
        int mouseX=0,mouseY=0;
        bool isClicked=false;
        string name="";
    public:
        Button(int x, int y,int h=50, int w=100,string n="");
        void setButton(int x, int y, int h=50, int w=100, string n="");
        void display();
        bool isButtonPressed();
};

#endif