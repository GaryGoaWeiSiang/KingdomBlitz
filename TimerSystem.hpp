#ifndef TIMERSYSTEM_HPP
#define TIMERSYSTEM_HPP
#include <iostream>
#include <graphics.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class TimerSystem: public GameManager{
    private:
    high_resolution_clock::time_point starttime;
    duration<double> elapsed;
    bool running;
    int totalSecond;
    int minute;
    int second;
    public:
    void startTime();
    void stopTime();
    int getSecond();
    int getMinute();
    void clearTimer();
};

#endif
