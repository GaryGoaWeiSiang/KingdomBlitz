#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <iostream>
#include <graphics.h>

using namespace std;

class System{
    private:
    bool isQuit;
    public:
    void run();
    void Quit(bool q);
};

#endif