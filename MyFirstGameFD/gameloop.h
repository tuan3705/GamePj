#pragma once
#define _GAMELOOP__H
#include "bird.h"
#include "background.h"
#include "pipe.h"
void waitUntilKeyPressed();
void renderBase();
void playGame(Graphics& graphics);
bool checkCollide(Bird bird, PIPE pipe);



