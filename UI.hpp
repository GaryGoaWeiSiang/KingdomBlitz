#ifndef UI_HPP
#define UI_HPP
#include <graphics.h>
using namespace std;

class UI{
    protected:
        int positionX,positionY;
    public:
        UI();
        UI(int px,int py);
};

#endif