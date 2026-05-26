#include <iostream>
#include <graphics.h>
#include "System.hpp"

using namespace std;

void System::run(){
    initwindow(getmaxwidth(),getmaxheight());
    isQuit = false;
}
void System::Quit(bool q){
    isQuit = q;
    if(isQuit){
        closegraph();
    }
}