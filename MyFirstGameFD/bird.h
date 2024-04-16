#pragma once
#define _BIRD__H
#include "graphics.h"
#include<bits/stdc++.h>
using namespace std;
class Bird{
private:
    SDL_Texture* birdFlapUp;
    SDL_Texture* birdFlapMid;
    SDL_Texture* birdFlapDown;
    vector< string > TTBirdUp = { "Picture/yellowbird-upflap.png", "Picture/redbird-upflap.png", "Picture/bluebird-upflap.png"};
    vector< string > TTBirdMid ={ "Picture/yellowbird-midflap.png", "Picture/redbird-midflap.png", "Picture/bluebird-midflap.png"};
    vector< string > TTBirdDown ={ "Picture/yellowbird-downflap.png", "Picture/redbird-downflap.png", "Picture/bluebird-downflap.png"};
    int x = SCREEN_WIDTH/7;
    int y = SCREEN_HEIGHT/2;
    int randomBird = rand()%3;
    int Gravity = 1;
    bool isFlap;
    int angle=0;
    int dy;
    double dd=3;
    int du=8;
    int indexAnimation=0;
public:
    void Flap(){
       isFlap = true;
    }
    void notFlap(){
       isFlap = false;
    }
    bool birdState(){
        return isFlap;
    }
    int numberBird()
    {
        return randomBird;
    }
    void loadBird(Graphics& graphics)
    {
        birdFlapUp = graphics.loadTexture(TTBirdUp[randomBird].c_str());
        birdFlapMid = graphics.loadTexture(TTBirdMid[randomBird].c_str());
        birdFlapDown = graphics.loadTexture(TTBirdDown[randomBird].c_str());
    }
    void UpdateIndexAnimation(){
        indexAnimation+=1;
    }
    int GetIndexAnimation(){
        return indexAnimation%48;
    }
    int getX() {return x;}
    int getY() {return y;}
    void move(){
        y+=dy;
        if(y<=0) y=0;
        if(y>=500-BIRD_HEIGHT) y=500-BIRD_HEIGHT;
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
     if(GetIndexAnimation()<17)
         graphics.renderTextureEx(birdFlapUp,bird.x,bird.y,angle);
     else if(GetIndexAnimation()<33)
         graphics.renderTextureEx(birdFlapMid,bird.x,bird.y,angle);
     else  graphics.renderTextureEx(birdFlapDown,bird.x,bird.y,angle);
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
    angle=ag;
}
bool gameOver() {
    return false;
    return   y >= 500-BIRD_HEIGHT;
    }

};
