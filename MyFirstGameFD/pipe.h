#pragma once
#define _PIPE__H
#include<bits/stdc++.h>
#include "graphics.h"
using namespace std;
class PIPE{
private:
   char* PIPEUP = "Picture/pipe_upper.png";
   char* PIPEUN = "Picture/pipe_under.png";
    SDL_Texture* pipeUp ;
    SDL_Texture* pipeUn ;
   SDL_Rect upper, under;
public:
    void loadTexturePipe(Graphics g);
    void renderPipe( int x, int y, Graphics g, int role);
    void scroll(int distance);
    void setPosX(int PosX);
    void setPosY(int PosY);
    void disY();
    void clearPipe();
    int getX();
    int getY_Un();
    int getY_Up();
    bool checkPipeOut();

};
