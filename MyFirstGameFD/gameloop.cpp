#include "gameloop.h"
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
void renderBase()
{
     Graphics graphics;
     graphics.init();

     SDL_Texture* background = graphics.loadTexture("Picture/background.png");
     graphics.prepareScene(background);

     SDL_Texture* land = graphics.loadTexture("Picture/land.png");
     graphics.renderTexture(land, 0, 500,0,0);

     SDL_Texture* message = graphics.loadTexture("Picture/message.png");
     graphics.renderTexture(message, (SCREEN_WIDTH-MESSAGE_WIDTH)/2,(SCREEN_HEIGHT-MESSAGE_HEIGHT-LAND_HEIGHT)/2,0,0);

     SDL_Texture* birdf = graphics.loadTexture("Picture/redbird-midflap.png");
     graphics.renderTexture(birdf, SCREEN_WIDTH/4, SCREEN_HEIGHT/2, 0, 0);
	 graphics.presentScene();
	 waitUntilKeyPressed();
}
void playGame()
{
         Graphics graphics;
         Bird bird;
         bird.x=SCREEN_WIDTH/4;
         bird.y=SCREEN_HEIGHT/2;
    	 bool quit=false;
	     SDL_Event event;
	     ScrollingBackground base;
	     base.setTexture(graphics.loadTexture("Picture/land.png"));
	     SDL_Texture* background = graphics.loadTexture("Picture/background.png");
	  while(!quit && !bird.gameOver())
        {
            graphics.prepareScene();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }
         graphics.prepareScene(background);
         base.scroll(1);
         graphics.renderScrolling(base);
       //  SDL_Texture* land = graphics.loadTexture("Picture/land.png");
       //  graphics.renderTexture(land, 0, 500,0,0);
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        SDL_Event event;
        if (currentKeyStates[SDL_SCANCODE_SPACE] ) bird.turnUp();
        else bird.turnDown();
        bird.move();
        bird.render(bird,graphics);
        graphics.presentScene();
        SDL_Delay(10);
        }
        graphics.quit();

}

