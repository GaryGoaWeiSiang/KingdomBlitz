#ifndef INPUT_HPP
#define INPUT_HPP
#include <iostream>
#include <graphics.h>

using namespace std;

class Input: public System{
    private: 
    char key;
    public: 
    char getKey();
    void clearKey();
    bool isKeyPressed();
    bool isKey(char k);
};


#endif