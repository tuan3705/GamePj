#include "gameloop.h"
#include<bits/stdc++.h>
using namespace std;
const int TARGET_FPS = 60;
Uint32 frameStart, frameTime;
bool checkCollide(Bird bird , PIPE pipe)
{
    if (( bird.getX() <= pipe.getX() + 52 && bird.getX() + 34 >= pipe.getX() && bird.getY() <= pipe.getY_Un() + 320 && bird.getY() + 24 >= pipe.getY_Un()))
      return true;
    if ( bird.getX() <= pipe.getX() + 52 && bird.getX() + 34 >= pipe.getX() && bird.getY() <= pipe.getY_Up() + 320 && bird.getY() + 24 >= pipe.getY_Up())
       return true;
    return false;
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN) )
            return;
        SDL_Delay(100);
    }

}
void renderBase(Graphics& graphics1,Bird bird)
{
     //graphics1.init();

     SDL_Texture* background1 = graphics1.loadTexture("Picture/background-day.png");
     graphics1.prepareScene(background1);

     SDL_Texture* land1 = graphics1.loadTexture("Picture/land.png");
     graphics1.renderTextureEx(land1, 0, 500,0);

     SDL_Texture* message1 = graphics1.loadTexture("Picture/message.png");
     graphics1.renderTextureEx(message1, (SCREEN_WIDTH-MESSAGE_WIDTH)/2,(SCREEN_HEIGHT-MESSAGE_HEIGHT-LAND_HEIGHT)/2,0);

     SDL_Texture* birdf;
     if(bird.numberBird() == 0) birdf = graphics1.loadTexture("Picture/yellowbird-midflap.png");
     else if(bird.numberBird() ==  1) birdf = graphics1.loadTexture("Picture/redbird-midflap.png");
     else birdf = graphics1.loadTexture("Picture/bluebird-midflap.png");
     graphics1.renderTextureEx(birdf, SCREEN_WIDTH/7, SCREEN_HEIGHT/2, 0);
	 graphics1.presentScene();
     ScrollingBackground base;
     ScrollingBackground bgrr;
     bgrr.setTexture(graphics1.loadTexture("Picture/background-day.png"));
     base.setTexture(graphics1.loadTexture("Picture/land.png"));
    // SDL_Texture* TTgameOver = graphics1.loadTexture("Picture/TTgameOver.png");
	  waitUntilKeyPressed();
}
void playGame(Graphics &graphics)
{
         //Graphics graphics;
         Bird bird;
         renderBase(graphics,bird);
         bird.loadBird(graphics);
         vector < PIPE > pipe;
         for(int i = 0; i <= 3; i++)
         {
             PIPE pipe1;
             pipe1.loadTexturePipe(graphics);
             pipe1.setPosX(700 + 220*i);
             pipe1.setPosY(rand()%141);
             pipe.push_back(pipe1);
         }
    	 bool quit=false;
	     SDL_Event event;
	     ScrollingBackground base;
	     ScrollingBackground bgrr;
	     bgrr.setTexture(graphics.loadTexture("Picture/background-day.png"));
	     base.setTexture(graphics.loadTexture("Picture/land.png"));
	     SDL_Texture* TTgameOver = graphics.loadTexture("Picture/TTgameOver.png");
	  while(!quit)
        {
            if(checkCollide(bird,pipe[0]))
            {
                graphics.renderTextureEx(TTgameOver, (350-TTgameOver_WIDTH)/2, (500-TTgameOver_HEIGHT)/2, 0);
                graphics.presentScene();
                SDL_Delay(2000);
                playGame(graphics);
            }
            graphics.prepareScene();
            frameStart = SDL_GetTicks();
            while(SDL_PollEvent(&event)!=0){
              if (event.type == SDL_QUIT) quit = true;
              const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
              if (currentKeyStates[SDL_SCANCODE_SPACE] || event.type == SDL_MOUSEBUTTONDOWN) { bird.turnUp();}
               else { bird.turnDown();}
            }
         bird.move();
         bgrr.scroll(2);
         graphics.renderScrolling(bgrr,0);
         for(int i = 0;i < pipe.size(); i++)
         {
             pipe[i].scroll(2);
             pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Up(), graphics, 1);
             pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Un(), graphics, 2);
         }
         if(pipe[0].checkPipeOut())
         {
             pipe.erase(pipe.begin()+0);
             PIPE pipe1;
             pipe1.loadTexturePipe(graphics);
             pipe1.setPosX(pipe[2].getX()+220);
             pipe1.setPosY(rand()%141);
             pipe.push_back(pipe1);

         }
         base.scroll(2);
         graphics.renderScrolling(base,500);
        bird.render(bird,graphics);
        graphics.presentScene();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < 1000 / TARGET_FPS){
            SDL_Delay((1000 / TARGET_FPS) - frameTime);
        }
        }
        graphics.quit();

}

