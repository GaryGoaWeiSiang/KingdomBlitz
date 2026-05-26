#ifndef SCENE_HPP
#define SCENE_HPP
#include <iostream>
#include <graphics.h>

using namespace std;

class Scene:public System{
    private:
    int windowHeight = getmaxheight() ,windowWidth = getmaxwidth();
    void* imageBuffer;
    bool imageLoaded;
    string image;
    bool currentScene;
    public:
    Scene(string i="kingdom.jpg");
    void createWindow();
    void displayBackground();
    void loadBackground();
    virtual void updateScene(Scene *s)=0;
    bool isCurrentScene();
    void setCurrentScene(bool cs);
};

#endif