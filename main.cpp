#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include "Entities.hpp"
#include "System.hpp"
#include "GameManager.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "input.hpp"
#include "CollisionSystem.hpp"
#include "SpawnSystem.hpp"
#include "UI.hpp"
#include "cursor.hpp"
#include "TimerSystem.hpp"
#include "PointSystem.hpp"
#include "text.hpp"
#include "GameScene.hpp"
#include "Scene.hpp"
#include "bar.hpp"
#include "Menu.hpp"

using namespace std;

int main(){
    srand(time(0));
    int width = getmaxwidth();
    int height = getmaxheight(); 
    int page = 0;
    int spawnInterval = 100; 
    int shootInterval = 100;
    int shootInterval2 = 150;
    bool pause=false;
    int currentMinute;
    int frameCount;
    static int LevelUpFrame;
    int currentLevel;
    bool bossDead;
    bool bossSpawn;
    int _x=width/2;
    int _y=height/2;
    
    char c;
    GameScene g;
    Menu m;
    Menu m2("mountain.jpg");
    Menu m3;
    Menu m4("win.jpg");
    m.createWindow();
    while(true){
    if(m.isCurrentScene()){
    while(true){
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        m.displayBackground();

        bgiout<<"Kingdom"<<endl<<"\tBlitz";
        settextstyle(7,HORIZ_DIR,10);
        outstreamxy(width/2-250,height/2-250,bgiout);

        settextstyle(3,HORIZ_DIR,1);

        m.b1.display();
        m.b2.display();

        if(m.b1.isButtonPressed()){
            clearmouseclick(WM_LBUTTONDOWN);
            m.updateScene(&g);
            break;
        }
        if(m.b2.isButtonPressed()){
            clearmouseclick(WM_LBUTTONDOWN);
            m.Quit(true);
            return 0;
        }
        delay(20);
        page = 1 - page;
    }
    }

    if(g.isCurrentScene()){
    g.t.startTime();
    if(!pause){
    currentMinute = 0;
    frameCount = 0;
    LevelUpFrame = -1000;
    g.p.loadImage();
    currentLevel = g.p.l.getLevel();
    bossDead=false;
    bossSpawn=false;
    g.b.setButton(getmaxwidth()-50,10,30,30,(string)" | | ");
    g.b1.setValue(100);
    g.b1.setCurrentValue(g.p.getHpPointer());
    g.b2.setCurrentValue(g.p.l.getExpPointer());
    g.b3.setValue(50000);
    c=' ';
    g.t.clearTimer();
    g.point.clearPoint();
    g.p.reset();
    g.p.countLevel();
    g.t.startTime();
    *(g.p.pointX()) = _x;
    *(g.p.pointY()) = _y;}
    while(true){
        setactivepage(page);
        setvisualpage(1 - page);
        frameCount++;
        g.p.i.clearKey();
        if(g.p.i.isKeyPressed()){
        c = g.p.i.getKey();
    }
        cleardevice();
        if(currentMinute!=g.t.getMinute()){
            if(spawnInterval>70)
            spawnInterval-=3;
            currentMinute = g.t.getMinute();
        }
        g.b2.setValue(g.p.l.getMaxExp());
        if (frameCount % spawnInterval == 0) {
        if (g.e.size() < 20&&g.t.getMinute()>=3) {
            g.e.push_back(Enemy(g.p.pointX(), g.p.pointY(), 200, 20, 400, 1, 30, 30,false,"Mushroom.jpg"));
            g.e.back().loadImage();
            }
        if (g.e2.size() < 5&&g.t.getMinute()>=5){
            g.e2.push_back(Enemy(g.p.pointX(), g.p.pointY(), 250, 25, 300, 5, 20, 40,false,"ghost.jpg"));
            g.e2.back().loadImage();
        }
        if (g.e3.size() < 20&&g.t.getMinute()<5){
            g.e3.push_back(Enemy(g.p.pointX(), g.p.pointY(), 100, 10, 150, 1, 30, 30,false,"slime.jpg"));
            g.e3.back().loadImage();
        }
        }
        if(g.t.getMinute()>=10&&g.boss.size()<1){
            g.boss.push_back(Enemy(g.p.pointX(), g.p.pointY(), 1000, 1000, 50000, 10, 150, 150,true,"dragon.jpg"));
            g.boss.back().loadImage();
            g.b3.setCurrentValue(g.boss.back().getHp());
            bossDead = false;
            bossSpawn = true;
        }
        g.p.move();

        if (g.p.isCollide(&g.w1)) {g.p.resolveCollision(&g.w1);}
        if (g.p.isCollide(&g.w2)) {g.p.resolveCollision(&g.w2);}
        if (g.p.isCollide(&g.w3)) {g.p.resolveCollision(&g.w3);}
        if (g.p.isCollide(&g.w4)) {g.p.resolveCollision(&g.w4);}

        for(auto &boss:g.boss){
            if(!boss.isDead()){
                boss.display();
            if(frameCount%30==0){
                boss.move();
            }
            boss.calcAngle();
            if(rand()%shootInterval2 == 0){
                for(int i = 0; i < 50; ++i){
                if(!boss.b[i].isActive()){
                    boss.shoot(i);
                    break;}
                }
            }
            for(int i = 0; i < 50; ++i){
                if(boss.b[i].isActive()){
                    boss.b[i].shoot();
                    boss.b[i].render();
                    }
                }
            }
        }

        for(auto &enemy:g.e){
            if(!enemy.isDead())
            enemy.move();
        }

        for(auto &enemy2:g.e2){
            if(!enemy2.isDead()){
            enemy2.display();
            enemy2.calcAngle();
            if(frameCount-spawnInterval>30&&rand()%shootInterval == 0){
                for(int i = 0; i < 50; ++i){
                if(!enemy2.b[i].isActive()){
                    enemy2.shoot(i);
                    break;}
                }
            }
            for(int i = 0; i < 50; ++i){
                if(enemy2.b[i].isActive()){
                    enemy2.b[i].shoot();
                    enemy2.b[i].render();
                    }
                }
            }
        }

        for(auto &enemy3:g.e3){
            if(!enemy3.isDead())
            enemy3.move();
        }

        g.p.c.update(g.p.pointX(),g.p.pointY());

        g.p.cu.getMouse();
        g.p.cu.setCenter(g.p.pointX(),g.p.pointY());
        g.p.cu.calculateAngle();
        g.p.powerUp();

        for(auto &enemy:g.e){
        if (g.p.isCollide(&enemy)){
            g.p.decreaseHp(1);
            bgiout<<"HIT!!";
            outstreamxy(g.p.getX()+10,g.p.getY()-15,bgiout);
        }
        }
        for(auto &enemy2:g.e2){
        if (g.p.isCollide(&enemy2)){
            g.p.decreaseHp(1);
            bgiout<<"HIT!!";
            outstreamxy(g.p.getX()+10,g.p.getY()-15,bgiout);
        }
        }
        for(auto &enemy3:g.e3){
        if (g.p.isCollide(&enemy3)){
            g.p.decreaseHp(1);
            bgiout<<"HIT!!";
            outstreamxy(g.p.getX()+10,g.p.getY()-15,bgiout);
        }
        }
        for(auto &boss:g.boss){
        if (g.p.isCollide(&boss)){
        g.p.decreaseHp(1);
        bgiout<<"HIT!!";
        outstreamxy(g.p.getX()+10,g.p.getY()-15,bgiout);
        }
        }


        g.p.display();
        g.b1.updateBar();
        g.b2.updateBar();
        g.b.display();

        if(!g.boss.empty()&&!g.boss[0].isDead()){
        bgiout<<"Dragon"<<endl;
        outstreamxy(50,getmaxheight()-70,bgiout);
        g.b3.updateBar();
        }
        g.p.cu.display();
        //e.display();
        if(ismouseclick(WM_LBUTTONDOWN)){
            for (int i = 0; i < 50; ++i) {
            if (!g.p.b[i].isActive()) {
                g.p.shoot(i);
                //p.b[i].setActive(true);
                break;
                }
            }
            //if(ismouseclick(WM_LBUTTONUP))
                //clearmouseclick(WM_LBUTTONDOWN);
        }
        if(ismouseclick(WM_LBUTTONUP)){
            clearmouseclick(WM_LBUTTONDOWN);
            clearmouseclick(WM_LBUTTONUP);
        }

        for(auto &enemy2:g.e2){
        for(int i = 0; i < 50; ++i){
            if(enemy2.b[i].isActive()&&enemy2.b[i].isCollide(&g.p)){
                g.p.decreaseHp(enemy2.getDamage());
                enemy2.b[i].setActive(false);
                bgiout<<"HIT!!";
                outstreamxy(g.p.getX()+10,g.p.getY()-15,bgiout);
                break;
            }
        }
    }

        for(auto &boss:g.boss){
        for(int i = 0; i < 50; ++i){
            if(boss.b[i].isActive()&&boss.b[i].isCollide(&g.p)){
                g.p.decreaseHp(boss.getDamage());
                boss.b[i].setActive(false);
                bgiout<<"HIT!!";
                outstreamxy(g.p.getX()+10,g.p.getY()-15,bgiout);
                break;
            }
        }
    }

        for (int i = 0; i < 50; ++i) {
            if (g.p.b[i].isActive()) {
            g.p.b[i].shoot(); // Moves and draws the bullet
            g.p.b[i].render();
            for (auto &enemy : g.e) {
                if (g.p.b[i].isCollide(&enemy)) {
                bgiout<<"-"<<g.p.getDamage()<<" Hp";
                outstreamxy(enemy.getX()+10,enemy.getY()-20,bgiout);
                enemy.decreaseHp(g.p.getDamage());
                g.p.l.addExp(10);
                g.point.addPoint(10);
                g.p.b[i].setActive(false);
                break; // Stop after first collision
                }
            }
            for (auto &enemy2 : g.e2) {
                if (g.p.b[i].isCollide(&enemy2)) {
                bgiout<<"-"<<g.p.getDamage()<<" Hp";
                outstreamxy(enemy2.getX()+10,enemy2.getY()-20,bgiout);
                enemy2.decreaseHp(g.p.getDamage());
                g.p.l.addExp(10);
                g.point.addPoint(10);
                g.p.b[i].setActive(false);
                break; // Stop after first collision
                }
            }
            for (auto &enemy3 : g.e3) {
                if (g.p.b[i].isCollide(&enemy3)) {
                bgiout<<"-"<<g.p.getDamage()<<" Hp";
                outstreamxy(enemy3.getX()+10,enemy3.getY()-20,bgiout);
                enemy3.decreaseHp(g.p.getDamage());
                g.p.l.addExp(10);
                g.point.addPoint(10);
                g.p.b[i].setActive(false);
                break; // Stop after first collision
                }
            }
            for (auto &boss : g.boss) {
                if (g.p.b[i].isCollide(&boss)) {
                bgiout<<"-"<<g.p.getDamage()<<" Hp";
                outstreamxy(boss.getX()+10,boss.getY()-20,bgiout);
                boss.decreaseHp(g.p.getDamage());
                g.point.addPoint(1);
                g.p.b[i].setActive(false);
                break; // Stop after first collision
                }
            }
            }
        }
        if(currentLevel!=g.p.l.getLevel()){
                currentLevel=g.p.l.getLevel();
                LevelUpFrame = frameCount;
            }

            if(frameCount-LevelUpFrame<60){
                bgiout<<"Level Up!!";
                outstreamxy(g.p.getX()-20,g.p.getY()-30,bgiout);
            }

        for (auto it = g.e.begin(); it != g.e.end(); ) {
            if (it->isDead()) {
                g.p.l.addExp(it->getDropExp());     // Add EXP
                g.point.addPoint(it->getPointGain()); // Add points if you have such a function
                it = g.e.erase(it);               // Erase and move to next
            } 
            else {
                ++it;
                }
            }

        for (auto it2 = g.e2.begin(); it2 != g.e2.end(); ) {
            if (it2->isDead()) {
                g.p.l.addExp(it2->getDropExp());     // Add EXP
                g.point.addPoint(it2->getPointGain()); // Add points if you have such a function
                it2 = g.e2.erase(it2);               // Erase and move to next
            } 
            else {
                ++it2;
                }
            }
        for (auto it3 = g.e3.begin(); it3 != g.e3.end(); ) {
            if (it3->isDead()) {
                g.p.l.addExp(it3->getDropExp());     // Add EXP
                g.point.addPoint(it3->getPointGain()); // Add points if you have such a function
                it3 = g.e3.erase(it3);               // Erase and move to next
            } 
            else {
                ++it3;
                }
            }
        for (auto &boss : g.boss) {
            if (bossSpawn&&boss.isDead()) {
                g.p.l.addExp(boss.getDropExp());     // Add EXP
                g.point.addPoint(boss.getPointGain()); // Add points if you have such a function
                bossDead = true;
            } 
        }

        /*g.e.erase(remove_if(g.e.begin(), g.e.end(),
            [](Enemy &en){ return en.isDead(); }),
            g.e.end());*/
        bgiout<<"Level "<<g.p.l.getLevel()<<endl;
        outstreamxy(10,10,bgiout);
        bgiout<<"Time: "<<endl<<g.t.getMinute()<<"m "<<g.t.getSecond()<<"s"<<endl;
        outstreamxy(getmaxwidth()/2,10,bgiout);
        bgiout<<"Point: "<<g.point.getPoint();
        outstreamxy(getmaxwidth()-160,10,bgiout);
        bgiout<<"Player Hp: "<<g.p.getHp()<<endl;
        outstreamxy(200,200,bgiout);
        if(g.t.getMinute()==9&&g.t.getSecond()>50&&g.t.getMinute()<10){
            bgiout<<"Boss Incoming!!!"<<endl;
            outstreamxy(width/2,height/2,bgiout);
        }

        if(g.b.isButtonPressed()){
            clearmouseclick(WM_LBUTTONDOWN);
            g.t.stopTime();
            pause=true;
            g.updateScene(&m3);
            break;
        }

        if(g.p.isDead()||bossDead||c=='0'){
            g.t.stopTime();
            g.e.clear();
            g.e2.clear();
            g.e3.clear();
            g.boss.clear();
            bossSpawn=false;
            spawnInterval=100;
            pause = false;
            if(bossDead){
                g.updateScene(&m4);
            }
            else{
                g.updateScene(&m2);
            }
            bossDead = false;
            break;
        }

        delay(20);
        page = 1 - page;
    }
    clearmouseclick(WM_LBUTTONDOWN);
    if(m2.isCurrentScene()){
        setactivepage(1);
        setvisualpage(1);
        cleardevice();
        m2.loadBackground();
        m2.displayBackground();
        settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
        bgiout<<"Game Over!!"<<endl<<endl;
        bgiout<<"Level: "<<g.p.l.getLevel()<<endl;
        bgiout<<"Point: "<<g.point.getPoint()<<endl;
        bgiout<<"Time: "<<g.t.getMinute()<<"m "<<g.t.getSecond()<<"s"<<endl;
        outstreamxy(_x-50,_y-50,bgiout);
        settextstyle(3,HORIZ_DIR,1);
        m2.b1.setButton(getmaxwidth()/2-80,(getmaxheight()/2)+50,50,100,(string)"Restart");
        m2.b2.setButton(getmaxwidth()/2+40,(getmaxheight()/2)+50,50,100,(string)"Menu");
        m2.b3.setButton(getmaxwidth()/2-25,(getmaxheight()/2)+120,50,100,(string)"Quit");
        m2.b1.display();
        m2.b2.display();
        m2.b3.display();
        while(true){
    if(m2.b1.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        pause = false;
        m2.updateScene(&g);
        break;
    }
    if(m2.b2.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        pause = false;
        m2.updateScene(&m);
        break;
    }
    if(m2.b3.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        m2.Quit(true);
        return 0;}}

    }

    if(m4.isCurrentScene()){
        setactivepage(1);
        setvisualpage(1);
        cleardevice();
        m4.loadBackground();
        m4.displayBackground();
        settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
        bgiout<<"Level: "<<g.p.l.getLevel()<<endl;
        bgiout<<"Point: "<<g.point.getPoint()<<endl;
        bgiout<<"Time: "<<g.t.getMinute()<<"m "<<g.t.getSecond()<<"s"<<endl;
        outstreamxy(_x-50,_y-100,bgiout);
        settextstyle(3,HORIZ_DIR,1);
        m4.b1.setButton(getmaxwidth()/2-80,(getmaxheight()/2),50,100,(string)"Restart");
        m4.b2.setButton(getmaxwidth()/2+40,(getmaxheight()/2),50,100,(string)"Menu");
        m4.b3.setButton(getmaxwidth()/2-25,(getmaxheight()/2)+70,50,100,(string)"Quit");
        m4.b1.display();
        m4.b2.display();
        m4.b3.display();
        while(true){
    if(m4.b1.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        pause = false;
        m4.updateScene(&g);
        break;
    }
    if(m4.b2.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        pause = false;
        m4.updateScene(&m);
        break;
    }
    if(m4.b3.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        m4.Quit(true);
        return 0;}}

    }
    
    if(m3.isCurrentScene()){
        setactivepage(1);
        setvisualpage(1);
        cleardevice();
        settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
        bgiout<<"Pause"<<endl<<endl;
        outstreamxy(_x-50,_y-50,bgiout);
        settextstyle(3,HORIZ_DIR,1);
        m3.b1.setButton(getmaxwidth()/2-80,(getmaxheight()/2)+50,50,100,(string)"Continue");
        m3.b2.setButton(getmaxwidth()/2+40,(getmaxheight()/2)+50,50,100,(string)"Restart");
        m3.b3.setButton(getmaxwidth()/2-80,(getmaxheight()/2)+120,50,100,(string)"Menu");
        m3.b4.setButton(getmaxwidth()/2+40,(getmaxheight()/2)+120,50,100,(string)"Quit");
        m3.b1.display();
        m3.b2.display();
        m3.b3.display();
        m3.b4.display();
        while(m3.isCurrentScene()){
        if(m3.b1.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        m3.updateScene(&g);
        break;
        }
        if(m3.b2.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        m3.updateScene(&g);
        pause = false;
        break;
        }
        if(m3.b3.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        pause = false;
        m3.updateScene(&m);
        break;}
        if(m3.b4.isButtonPressed()){
        clearmouseclick(WM_LBUTTONDOWN);
        m3.Quit(true);
        return 0;
        }}
    }
    
}
//closegraph();
//return 0;
}
}