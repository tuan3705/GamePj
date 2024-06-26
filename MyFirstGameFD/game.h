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
    int isDay;
    int isSound;
    int mouseX;
    int mouseY;
    bool Play;
    bool quit;
    bool die;
    int score;
    int bestScore;
    PIPE tPipe;
    Bird bird;
    Graphics graphics;
    ScrollingBackground land;
    ScrollingBackground bgrr;
    ScrollingBackground bgrrN;
    vector < PIPE > pipe;
    vector < SDL_Texture* > largeNum;
    vector < SDL_Texture* > smallNum;
    vector < SDL_Texture* > medal;
    SDL_Texture* button;
    SDL_Texture* pause;
    SDL_Texture* pauseTab;
    SDL_Texture* resume;
    SDL_Texture* RightButton;
    SDL_Texture* LeftButton;
    SDL_Texture* replay;
    SDL_Texture* message;
    SDL_Texture* TTgameOver;
    SDL_Texture* Sound;
    SDL_Texture* NotSound;
    Mix_Music *sMusic;
    Mix_Chunk *sClick;
    Mix_Chunk *sFlap;
    Mix_Chunk *sDead;
    Mix_Chunk *sPoint;

public:
    bool isQuit();
    bool isPlay();
    bool checkCollide(PIPE pipe1);
    void initG();
    void clearG();
    void updateSound();
    void renderSound(int x,int y);
    bool updateScore(PIPE pipe1);
    void updateBestScore();
    void changeBackground();
    void renderLargeScore(int sc);
    void renderSmallScore(int sc,int posX);
    void renderMedal();
    void prepare();
    void playGame();
    void animation_dead();
    void pause_game();
    void updateG();
    void updateMusic();
    void resetGame();

};
