#include <iostream>
#include <graphics.h>
#include "System.hpp"
#include "Scene.hpp"

using namespace std;

Scene::Scene(string i):imageBuffer(nullptr),imageLoaded(false){image = i;}
void Scene::createWindow(){
    run();
    loadBackground();
    currentScene = true;
}

void Scene::loadBackground(){
    if (!imageLoaded) {
        imageBuffer = malloc(imagesize(0, 0, windowWidth, windowHeight));
        readimagefile(image.c_str(), 0, 0, windowWidth, windowHeight);
        getimage(0, 0,windowWidth, windowHeight, imageBuffer);
        imageLoaded = true;
        cleardevice(); // Clear temp image load area
    }
}

void Scene::displayBackground(){
    if (imageBuffer) {
        putimage(0, 0, imageBuffer, COPY_PUT);
    }
}

void Scene::setCurrentScene(bool cs){
    currentScene = cs;
}

bool Scene::isCurrentScene(){
    return currentScene;
}