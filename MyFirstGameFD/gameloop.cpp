#include "gameloop.h"
using namespace std;
const int TARGET_FPS = 60;
Uint32 frameStart, frameTime;
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
void renderBase(Graphics& graphics1)
{
     graphics1.init();

     SDL_Texture* background1 = graphics1.loadTexture("Picture/background-day.png");
     graphics1.prepareScene(background1);

     SDL_Texture* land1 = graphics1.loadTexture("Picture/land.png");
     graphics1.renderTextureEx(land1, 0, 500,0);

     SDL_Texture* message1 = graphics1.loadTexture("Picture/message.png");
     graphics1.renderTextureEx(message1, (SCREEN_WIDTH-MESSAGE_WIDTH)/2,(SCREEN_HEIGHT-MESSAGE_HEIGHT-LAND_HEIGHT)/2,0);

     SDL_Texture* birdf = graphics1.loadTexture("Picture/redbird-midflap.png");
     graphics1.renderTextureEx(birdf, SCREEN_WIDTH/4, SCREEN_HEIGHT/2, 0);
	 graphics1.presentScene();
     ScrollingBackground base;
     ScrollingBackground bgrr;
     bgrr.setTexture(graphics1.loadTexture("Picture/background-day.png"));
     base.setTexture(graphics1.loadTexture("Picture/land.png"));
     SDL_Texture* TTgameOver = graphics1.loadTexture("Picture/TTgameOver.png");
	  waitUntilKeyPressed();
}
void playGame()
{
         Graphics graphics;
         renderBase(graphics);
         Bird bird;
    	 bool quit=false;
	     SDL_Event event;
	     ScrollingBackground base;
	     ScrollingBackground bgrr;
	     bgrr.setTexture(graphics.loadTexture("Picture/background-day.png"));
	     base.setTexture(graphics.loadTexture("Picture/land.png"));
	     SDL_Texture* TTgameOver = graphics.loadTexture("Picture/TTgameOver.png");
	  while(!quit)
        {
            bird.notFlap();
            graphics.prepareScene();
            frameStart = SDL_GetTicks();
            if(SDL_PollEvent(&event)){
              if (event.type == SDL_QUIT) quit = true;
              const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
              if (currentKeyStates[SDL_SCANCODE_SPACE] || event.type == SDL_MOUSEBUTTONDOWN) {bird.Flap();}
            }
         bird.update();
         bird.move();
         bird.notFlap();
         bgrr.scroll(1);
         graphics.renderScrolling(bgrr,0);
         base.scroll(1);
         graphics.renderScrolling(base,500);
        bird.render(bird,graphics);
        graphics.presentScene();;
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < 1000 / TARGET_FPS){
            SDL_Delay((1000 / TARGET_FPS) - frameTime);
        }
        }
        graphics.quit();

}

