#include <iostream>
#include <graphics.h>
#include <chrono>
#include "System.hpp"
#include "GameManager.hpp"
#include "TimerSystem.hpp"

using namespace std;
using namespace std::chrono;

void TimerSystem::startTime(){
    if (!running){
    running = true;
    starttime = high_resolution_clock::now();
    }
}

void TimerSystem::stopTime(){
    auto now = high_resolution_clock::now();
    elapsed += duration_cast<seconds>(now - starttime);
    running = false;
}

int TimerSystem::getSecond(){
    if(running){
        auto now = high_resolution_clock::now();
        totalSecond = (elapsed + duration_cast<seconds>(now-starttime)).count();
        second = totalSecond%60;
        return second;
    }
    else{
        totalSecond = elapsed.count();
        second = totalSecond%60;
        return second;
    }
}

int TimerSystem::getMinute(){
    minute = totalSecond/60;
    return minute;
}

void TimerSystem::clearTimer(){
    elapsed = seconds(0);
    running = false;
    starttime = high_resolution_clock::now();
    totalSecond = 0;
}