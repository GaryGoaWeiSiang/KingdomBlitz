#ifndef BAR_HPP
#define BAR_HPP
#include <iostream>
#include <graphics.h>
using namespace std;

class Bar:public UI{
    private:
        int value = 100;
        int *currentValue;
        int barHeight=30, barWidth=200;
        int colour;
    public:
        Bar(int px=0, int py=0, int bh=30, int bw=200, int c=WHITE);
        void display();
        void updateBar();
        void setValue(int v);
        void setCurrentValue(int *cv);
};

#endif