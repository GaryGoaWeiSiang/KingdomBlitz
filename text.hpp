#ifndef TEXT_HPP
#define TEXT_HPP
#include <iostream>
#include <graphics.h>
using namespace std;

class Text: public UI{
    private:
        string text;
        int duration=1000;
    public:
        Text(string s="",int x=0, int y=0);
        void display();
        void setText(string t);
};

#endif