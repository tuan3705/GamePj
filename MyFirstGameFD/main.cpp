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
     SDL_Texture* shiba = graphics.loadTexture("Picture/shiba.png");
     graphics.renderTexture(shiba, 150, 200);
     SDL_Texture* land = graphics.loadTexture("Picture/land.png");
     graphics.renderTexture(land, 0, 600);
	 graphics.presentScene();
//	 int x,y;
//	 SDL_Event event;
//	 while (true) {
//        SDL_GetMouseState(&x, &y);
//       cerr << x << ", " << y << endl;
//        SDL_PollEvent(&event);
//        switch (event.type) {
//            case SDL_QUIT:
//                 exit(0);
//                 break;
//            case SDL_MOUSEBUTTONDOWN:
//                 cerr << "Down at (" << x << ", " << y << ")\n";
//                 break;
//            case SDL_MOUSEBUTTONUP:
//                 cerr << "Up at (" << x << ", " << y << ")\n";
//                 break;
//        }
//        SDL_Delay(100);
//    }

     waitUntilKeyPressed();
     graphics.quit();


}
