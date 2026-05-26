#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <graphics.h>
#include "button.hpp"

using namespace std;

class Menu: public Scene{
    private:
    string text;
    string image;
    public:
    Button b1;
    Button b2;
    Button b3;
    Button b4;
    Menu();
    Menu(string i);
    void updateScene(Scene *s);
    void displayText();
};

#endif