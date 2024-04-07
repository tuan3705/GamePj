#include<bits/stdc++.h>
#include "gameloop.h"
using namespace std;
int main(int argc, char *argv[])
{
   srand(time(0));
   Graphics graphics;
   graphics.init();
   playGame(graphics);
   return 1;
}

