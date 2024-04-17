#pragma once
#define _GRAPHICS__H
#include "def.h"
#include<bits/stdc++.h>
using namespace std;
class ScrollingBackground {
public:
    SDL_Texture* texture;
    int scrollingOffset = 0;
    int width, height;
    void setTexture(SDL_Texture* _texture) {
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }
    void scroll(int distance) {
        scrollingOffset -= distance;
        if( scrollingOffset < 0 ) { scrollingOffset = width; }
    }
};
class Graphics {
private:
    SDL_Renderer *renderer;
    SDL_Window *window;
public:
    void logErrorAndExit(const char* msg, const char* error);
    void init();
    void prepareScene();
    void presentScene();
    SDL_Texture* loadTexture(const char *filename);
    void renderTextureEx(SDL_Texture *texture, int x, int y, int angle);
    void renderScrolling(const ScrollingBackground& bgr, int h);
    Mix_Chunk* loadSound(const char* path);
    void playSound(Mix_Chunk* gChunk);
    void quit();
};


