#include<bits/stdc++.h>
#include "game.h"
using namespace std;
int main(int argc, char *argv[])
{
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
   return 0;
}

