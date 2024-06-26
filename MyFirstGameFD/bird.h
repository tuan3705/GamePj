#pragma once
#define _BIRD__H
#include "graphics.h"
#include<bits/stdc++.h>
using namespace std;
class Bird{
private:
    SDL_Texture* birdFlapUp[3];
    SDL_Texture* birdFlapMid[3];
    SDL_Texture* birdFlapDown[3];

    vector< string > TTBirdUp = { "Picture/yellowbird-upflap.png", "Picture/redbird-upflap.png", "Picture/bluebird-upflap.png"};
    vector< string > TTBirdMid = { "Picture/yellowbird-midflap.png", "Picture/redbird-midflap.png", "Picture/bluebird-midflap.png"};
    vector< string > TTBirdDown = { "Picture/yellowbird-downflap.png", "Picture/redbird-downflap.png", "Picture/bluebird-downflap.png"};

    int x = SCREEN_WIDTH/7;
    int y = SCREEN_HEIGHT/2;

    int typeBird = 0;
    int Gravity = 1;
    int angle = 0;
    int dy;
    double dd = 1;
    int du = 5;
    int indexAnimation = 0;
public:
    void updateTypeBird(int x)
    {
        typeBird += x;
        typeBird = (typeBird + 3) %3 ;
    }
    void loadBird(Graphics& graphics)
    {
        for(int i = 0; i < 3; i++){
            birdFlapUp[i] = graphics.loadTexture(TTBirdUp[i].c_str());
            birdFlapMid[i] = graphics.loadTexture(TTBirdMid[i].c_str());
            birdFlapDown[i] = graphics.loadTexture(TTBirdDown[i].c_str());
        }
    }
    void UpdateIndexAnimation(){
        indexAnimation += 1;
    }
    int GetIndexAnimation(){
        return indexAnimation % 48;
    }
    int getX() {return x;}
    int getY() {return y;}
    void move(){
        y += dy;
        if(y <= 0) y = 0;
        if(y >= 500 - BIRD_HEIGHT) y = 500 - BIRD_HEIGHT;
        if(dy > 0) angle += 5;
        if(angle > 45) angle = 45;
        if(dy > 0) { dy += 0.1*Gravity; Gravity++; }
        if(dy > 12) dy = 12;
    }
    void turnUp()
    {
        dy = -du;
        dd = 3;
        angle = -45;
        Gravity = 1;
    }
    void turnDown()
    {
        dy = (int)dd;
    }
    void render(const Bird& bird,  Graphics& graphics)
    {
        UpdateIndexAnimation();
     if(GetIndexAnimation() < 17)  graphics.renderTextureEx(birdFlapUp[typeBird], bird.x, bird.y, angle);
     else if(GetIndexAnimation() < 33) graphics.renderTextureEx(birdFlapMid[typeBird], bird.x, bird.y, angle);
     else  graphics.renderTextureEx(birdFlapDown[typeBird], bird.x, bird.y, angle);
    }
    void reset()
    {
        x = SCREEN_WIDTH/7;
        y = SCREEN_HEIGHT/2;
        angle = 0;

    }
    void disY()
    {
        y +=3;
    }
    void setAngle(int ag)
    {
        angle = ag;
    }
    void clearBird()
    {
        for(int i = 0;i < 3; i++)
        {
            SDL_DestroyTexture(birdFlapUp[i]);
            SDL_DestroyTexture(birdFlapMid[i]);
            SDL_DestroyTexture(birdFlapDown[i]);
        }
    }
};
