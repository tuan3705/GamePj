#include <bits/stdc++.h>
#include "def.h"
#include "graphics.h"
using namespace std;


void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }

}
int main(int argc, char* argv[])
{
     Graphics graphics;
     graphics.init();

     SDL_Texture* background = graphics.loadTexture("Picture/background.png");
     graphics.prepareScene(background);
    // graphics.presentScene();
     SDL_Texture* shiba = graphics.loadTexture("Picture/shiba.png");
     graphics.renderTexture(shiba, 150, 200);
	 graphics.presentScene();
    // waitUntilKeyPressed();
     waitUntilKeyPressed();




     waitUntilKeyPressed();
     graphics.quit();
 //    quitSDL(window, renderer);

}
