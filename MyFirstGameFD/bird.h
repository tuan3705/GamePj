#pragma once
#define _BIRD__H
#include "graphics.h"
#include<bits/stdc++.h>
using namespace std;
class Bird{
public:
    char *TTBirdUp = "Picture/yellowbird-upflap.png";
    char *TTBirdMid = "Picture/yellowbird-midflap.png";
    char *TTBirdDown = "Picture/yellowbird-downflap.png";
    int x;
    int y;
    int dy;
    int dd=5;
    int du=1;
    double a=0;
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
        SDL_Texture* birdUp = graphics.loadTexture(TTBirdUp);
        SDL_Texture* birdMid = graphics.loadTexture(TTBirdMid);
        SDL_Texture* birdDown = graphics.loadTexture(TTBirdDown);
      //  graphics.renderTexture(birdUp,doge.x,doge.y,0,0);
      //  graphics.presentScene();
        graphics.renderTexture(birdMid,bird.x,bird.y,0,0);
      //  graphics.presentScene();
      //  graphics.renderTexture(birdDown,doge.x,doge.y,0,0);
      //  graphics.presentScene();
    }
    bool gameOver() {
    return   y < 0 || y >= 500-BIRD_HEIGHT;
    }

};
