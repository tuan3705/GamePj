//#include <bits/stdc++.h>
//#include "def.h"
//#include "graphics.h"
//#include "doge.h"
//using namespace std;
//
//
//void waitUntilKeyPressed()
//{
//    SDL_Event e;
//    while (true) {
//        if ( SDL_PollEvent(&e) != 0 &&
//             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
//            return;
//        SDL_Delay(100);
//    }
//
//}
//int main(int argc, char* argv[])
//{
//
//     Graphics graphics;
//     graphics.init();
//
//     SDL_Texture* background = graphics.loadTexture("Picture/background-night.png");
//     graphics.prepareScene(background);
//   //  SDL_Texture* shiba = graphics.loadTexture("Picture/shiba.png");
//   //  graphics.renderTexture(shiba,SCREEN_WIDTH/4,SCREEN_HEIGHT/2,0,0);
//     SDL_Texture* land = graphics.loadTexture("Picture/land.png");
//     graphics.renderTexture(land, 0, 500,0,0);
//     SDL_Texture* message = graphics.loadTexture("Picture/message.png");
//
//     graphics.renderTexture(message, (SCREEN_WIDTH-MESSAGE_WIDTH)/2,(SCREEN_HEIGHT-MESSAGE_HEIGHT-LAND_HEIGHT)/2,0,0);
//	 Doge doge;
//	 doge.x=SCREEN_WIDTH/4;
//	 doge.y=SCREEN_HEIGHT/2;
//	 render(doge,graphics);
//	 graphics.presentScene();
//	 waitUntilKeyPressed();
//	 bool quit=false;
//	 SDL_Event event;
//	 while(!quit && !gameOver(doge))
//        {
//            graphics.prepareScene();
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_QUIT) quit = true;
//        }
//         SDL_Texture* background = graphics.loadTexture("Picture/background.png");
//         graphics.prepareScene(background);
//         SDL_Texture* land = graphics.loadTexture("Picture/land.png");
//         graphics.renderTexture(land, 0, 500,0,0);
//	     graphics.presentScene();
//        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
//        if (currentKeyStates[SDL_SCANCODE_SPACE]) doge.turnUp();
//        else doge.turnDown();
//        doge.move();
//        render(doge,graphics);
//        graphics.presentScene();
//        SDL_Delay(100);
//
//        }
//
//	// SDL_Texture* message = graphics.loadTexture("Picture/message.png");
//	// graphics.renderTexture(message, (SCREEN_WIDTH-225)/2,(SCREEN_HEIGHT-204)/2,0,0);
//	// graphics.presentScene();
//
////    bool quit = false;
////    SDL_Event event;
////    while (!quit) {
////        //Handle events on queue
////        while (SDL_PollEvent(&event)) {
////            if (event.type == SDL_QUIT) quit = true;
////        }
////
////        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
////
////        if (currentKeyStates[SDL_SCANCODE_SPACE] ) cerr << "SPACE";
////        if (currentKeyStates[SDL_SCANCODE_DOWN] ) cerr << " Down";
////        if (currentKeyStates[SDL_SCANCODE_LEFT] ) cerr << " Left";
////        if (currentKeyStates[SDL_SCANCODE_RIGHT] ) cerr << " Right";
////
////        cerr << ".\n";
////
////        SDL_Delay(10);
////    }
//
//
////	 int x,y;
////	 SDL_Event event;
////	 while (true) {
////        SDL_GetMouseState(&x, &y);
////       cerr << x << ", " << y << endl;
////        SDL_PollEvent(&event);
////        switch (event.type) {
////            case SDL_QUIT:
////                 exit(0);
////                 break;
////            case SDL_MOUSEBUTTONDOWN:
////                 cerr << "Down at (" << x << ", " << y << ")\n";
////                 break;
////            case SDL_MOUSEBUTTONUP:
////                 cerr << "Up at (" << x << ", " << y << ")\n";
////                 break;
////        }
////        SDL_Delay(100);
////    }
//
//
//     //waitUntilKeyPressed();
//     graphics.quit();
//     return 0;
//
//}
#include<bits/stdc++.h>
#include "gameloop.h"
using namespace std;
int main(int argc, char *argv[])
{
   playGame();
   return 1;
}

