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
void renderBase(Graphics& graphics1)
{
     graphics1.init();

     SDL_Texture* background1 = graphics1.loadTexture("Picture/background.png");
     graphics1.prepareScene(background1);

     SDL_Texture* land1 = graphics1.loadTexture("Picture/land.png");
     graphics1.renderTexture(land1, 0, 500,0,0);

     SDL_Texture* message1 = graphics1.loadTexture("Picture/message.png");
     graphics1.renderTexture(message1, (SCREEN_WIDTH-MESSAGE_WIDTH)/2,(SCREEN_HEIGHT-MESSAGE_HEIGHT-LAND_HEIGHT)/2,0,0);

     SDL_Texture* birdf = graphics1.loadTexture("Picture/redbird-midflap.png");
     graphics1.renderTexture(birdf, SCREEN_WIDTH/4, SCREEN_HEIGHT/2, 0, 0);
	 graphics1.presentScene();
	 waitUntilKeyPressed();
}
void playGame()
{
         Graphics graphics;
         renderBase(graphics);
         Bird bird;
         bird.x=SCREEN_WIDTH/4;
         bird.y=SCREEN_HEIGHT/2;
    	 bool quit=false;
	     SDL_Event event;
	     ScrollingBackground base;
	     base.setTexture(graphics.loadTexture("Picture/land.png"));
	     SDL_Texture* background = graphics.loadTexture("Picture/background.png");
	     SDL_Texture* TTgameOver = graphics.loadTexture("Picture/TTgameOver.png");
	  while(!quit)
        {
            if(bird.gameOver()){
            graphics.renderTexture(TTgameOver,(SCREEN_WIDTH-TTgameOver_WIDTH)/2,(500-TTgameOver_HEIGHT)/2,0,0);
            graphics.presentScene();
            waitUntilKeyPressed();
           // void playGame();
            };
            graphics.prepareScene();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }
         graphics.prepareScene(background);
         base.scroll(2);
         graphics.renderScrolling(base,500);
       //  SDL_Texture* land = graphics.loadTexture("Picture/land.png");
       //  graphics.renderTexture(land, 0, 500,0,0);
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_SPACE] || event.type == SDL_MOUSEBUTTONDOWN) bird.turnUp();
        else bird.turnDown();
//       if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP ) bird.turnUp();
//       else bird.turnDown();
        bird.move();
        bird.render(bird,graphics);
        graphics.presentScene();

        SDL_Delay(10);
        }
        graphics.quit();

}

