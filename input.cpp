#include <iostream>
#include <graphics.h>
#include "System.hpp"
#include "input.hpp"

using namespace std;

char Input::getKey(){
    if(kbhit()){
        return key=getch();
    }
    return '\0';
}

void Input::clearKey(){
    key = '\0';
}


bool Input::isKeyPressed(){
    return kbhit();
}
bool Input::isKey(char k){
    if (key==k){
        return true;
    }
    else{
        return false;
    }
}
