#pragma once
#define _BIRD__H
#include "graphics.h"
#include<bits/stdc++.h>
using namespace std;
class Bird{
public:
    SDL_Texture* birdFlap;
    char *TTBirdUp = "Picture/redbird-upflap.png";
    char *TTBirdMid = "Picture/redbird-midflap.png";
    char *TTBirdDown = "Picture/redbird-downflap.png";
    int x;
    int y;
    int dy;
    int dd=5;
    int du=1;
    int index=0;
    double a=0;
    void UpdateIndex(){
        index+=1;
    }
    int GetIndex(){
        return index%60;
    }
    void move(){
        y+=dy;
    }
    void turnUp()
    {
        dy=-dd;
        a=0;
    }
    void turnDown()
    {
        dy=du+a;
        a+=0.1;
    }
    void render(const Bird& bird,  Graphics& graphics)
    {
        UpdateIndex();
        switch (GetIndex()){
     case 1:
         birdFlap = graphics.loadTexture(TTBirdUp);
         break;
     case 21:
         birdFlap = graphics.loadTexture(TTBirdMid);
         break;
     case 41:
         birdFlap = graphics.loadTexture(TTBirdDown);
         break;
        }

        graphics.renderTexture(birdFlap,bird.x,bird.y,0,0);
    }
    bool gameOver() {
    return   y < 0 || y >= 500-BIRD_HEIGHT;
    }

};
