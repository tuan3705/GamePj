#pragma once
#define _GAME__H
#include<bits/stdc++.h>
#include "def.h"
#include "bird.h"
#include "background.h"
#include "pipe.h"
using namespace std;
class Game{
private:
    int isSound;
    bool Play;
    bool quit;
    bool die;
    int score;
    PIPE tPipe;
    Bird bird;
    Graphics graphics;
    ScrollingBackground land;
    ScrollingBackground bgrr;
    vector < PIPE > pipe;
    vector < SDL_Texture* > largeNum;
    SDL_Texture* replay;
    SDL_Texture* message;
    SDL_Texture* TTgameOver;
    SDL_Texture* Sound;
    SDL_Texture* NotSound;
    Mix_Chunk *sFlap;
    Mix_Chunk *sDead;
    Mix_Chunk *sPoint;

public:
    bool isQuit();
    bool isPlay();
    bool checkCollide(PIPE pipe1);
    void update();
    void initG();
    void clearG();
    void updateSound();
    void renderSound();
    bool updateScore(PIPE pipe1);
    void renderScore(int sc);
    void prepare();
    void playGame();
    void resetGame();

};
