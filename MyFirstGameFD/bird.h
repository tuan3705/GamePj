#pragma once
#define _BIRD__H
#include "graphics.h"
#include<bits/stdc++.h>
using namespace std;
class Bird{
private:
    SDL_Texture* birdFlap;
    char *TTBirdUp = "Picture/redbird-upflap.png";
    char *TTBirdMid = "Picture/redbird-midflap.png";
    char *TTBirdDown = "Picture/redbird-downflap.png";
    int x = SCREEN_WIDTH/4;
    int y = SCREEN_HEIGHT/2;
    bool isFlap;
    int angle=0;
    int dy;
    double dd=0.6;
    int du=15;
    int indexAnimation=0;
public:
    void Flap(){
        isFlap = true;
    }
    void notFlap(){
        isFlap = false;
    }
    bool GetFlap(){
        return isFlap;
    }
    void UpdateIndexAnimation(){
        indexAnimation+=1;
    }
    int GetIndexAnimation(){
        return indexAnimation%48;
    }
    void move(){
        y+=dy;
        if(y<=0) y=0;
        if(y>=500-BIRD_HEIGHT) y=500-BIRD_HEIGHT;
    }
    void turnUp()
    {
        dy=-du;
        dd=5;
        angle=-45;
    }
    void turnDown()
    {
        dy=dd;
        angle+=5;
        if(angle>45) angle=45;
    }
    void render(const Bird& bird,  Graphics& graphics)
    {
        UpdateIndexAnimation();
        switch (GetIndexAnimation()){
     case 1:
         birdFlap = graphics.loadTexture(TTBirdUp);
         break;
     case 17:
         birdFlap = graphics.loadTexture(TTBirdMid);
         break;
     case 33:
         birdFlap = graphics.loadTexture(TTBirdDown);
         break;
        }
        graphics.renderTextureEx(birdFlap,bird.x,bird.y,angle);
    }
    void update()
    {
        if(!isFlap) {
        dy=(int)dd;
        dd += 0.6;
        if(dd > 12) dd = 12;
        angle+=5;
        if(angle>45) angle=45;
        }
    }
bool gameOver() {
    return false;
    return   y >= 500-BIRD_HEIGHT;
    }

};
