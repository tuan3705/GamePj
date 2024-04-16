#include<bits/stdc++.h>
#include "gameloop.h"
#include "game.h"
using namespace std;
int main(int argc, char *argv[])
{
//   srand(time(0));
//   Graphics graphics;
//   graphics.init();
//   playGame(graphics);
   Game game;
   game.initG();
   while(!game.isQuit())
   {
       if(!game.isPlay()) {
            game.prepare();
       }
       if(game.isPlay())
       {
           game.playGame();
       }
   }
   game.clearG();
   return 1;
}

