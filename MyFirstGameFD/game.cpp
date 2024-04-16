#include "game.h"
#include<bits/stdc++.h>
using namespace std;
void Game::initG()
{
    graphics.init();
    tPipe.loadTexturePipe(graphics);
    for(int i = 0;i <= 3;i ++)
    {
        tPipe.setPosX(350 + 220*i);
        tPipe.setPosY(rand()%141);
        pipe.push_back(tPipe);
    }
    for(int i= 0;i <= 9;i ++)
    {
        string tmp1 = "Picture/BigNum/"+to_string(i)+".png";
        SDL_Texture* num = graphics.loadTexture(tmp1.c_str());
        largeNum.push_back(num);
    }
    Play = 0;
    isSound = 1;
    score = 0;
    die = 0;
    quit = false;
    Sound = graphics.loadTexture("Picture/soundon.png");
    NotSound = graphics.loadTexture("Picture/soundoff.png");
    replay = graphics.loadTexture("Picture/replay.png");
    message = graphics.loadTexture("Picture/message.png");
    TTgameOver = graphics.loadTexture("Picture/TTgameOVer.png");
    land.setTexture(graphics.loadTexture("Picture/land.png"));
    bgrr.setTexture(graphics.loadTexture("Picture/background-day.png"));
    sFlap = graphics.loadSound("sound/flap.mp3");
    sDead = graphics.loadSound("sound/dead.mp3");
    sPoint = graphics.loadSound("sound/point.wav");
    bird.loadBird(graphics);
}
bool Game::isPlay()
{
    return Play;
}
bool Game::isQuit()
{
    return quit;
}
void Game::clearG()
{
    graphics.quit();
}
bool Game::checkCollide(PIPE pipe1)
{
    if (( bird.getX() <= pipe1.getX() + 52 && bird.getX() + 29 >= pipe1.getX() && bird.getY() <= pipe1.getY_Un() + 320 && bird.getY() + 24 >= pipe1.getY_Un()))
      return true;
    if ( bird.getX() <= pipe1.getX() + 52 && bird.getX() + 29 >= pipe1.getX() && bird.getY() <= pipe1.getY_Up() + 320 && bird.getY() + 24 >= pipe1.getY_Up())
       return true;
    if(bird.getY() >= 475) return true;
    return false;
}
bool Game::updateScore(PIPE pipe1)
{
   return (bird.getX() == pipe1.getX());
}
void Game::renderScore(int sc)
{
    string s = to_string(sc);
    int width = 30;
    int Pos = (SCREEN_WIDTH - width*s.size())/2;
    for(int i = 0; i < s.size(); i++)
    {
        graphics.renderTextureEx(largeNum[s[i]-'0'],Pos,10,0);
        Pos += 30;
    }
}
void Game::updateSound()
{
    isSound++;
    isSound%=2;
}
void Game::renderSound()
{
    if(isSound) graphics.renderTextureEx(Sound,10,10,0);
    else graphics.renderTextureEx(NotSound,10,10,0);
}
void Game::prepare(){
    die = 0;
    graphics.prepareScene();
    bgrr.scroll(2);
    graphics.renderScrolling(bgrr,0);
    land.scroll(2);
    graphics.renderScrolling(land,500);
    bird.render(bird,graphics);
    graphics.renderTextureEx(message,(SCREEN_WIDTH-MESSAGE_WIDTH)/2,(SCREEN_HEIGHT-MESSAGE_HEIGHT-LAND_HEIGHT)/2,0);
    renderSound();
    graphics.presentScene();
    SDL_Delay(16);
    SDL_Event e;

    if ( SDL_PollEvent(&e) != 0)
    {
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_m ) updateSound();
        if((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)|| e.type == SDL_MOUSEBUTTONDOWN ) Play = true;
       // if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_m ) updateSound();
    }
}
void Game::playGame(){
    const int TARGET_FPS = 60;
    Uint32 frameStart, frameTime;
    SDL_Event event;
    while(!die)
    {
        if(checkCollide(pipe[0])){
            if(isSound) graphics.playSound(sDead);
            SDL_Delay(100);
            bird.setAngle(180);
            while(bird.getY()<=485)
            {
                graphics.prepareScene();
                graphics.renderScrolling(bgrr,0);
                for(int i=0;i<pipe.size();i++)
                {
                    pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Up(), graphics, 1);
                    pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Un(), graphics, 2);

                }
                graphics.renderScrolling(land,500);
                bird.disY();
                bird.render(bird,graphics);
                graphics.presentScene();
            }
            graphics.renderTextureEx(TTgameOver, (350-TTgameOver_WIDTH)/2, (500-TTgameOver_HEIGHT)/2,0);
            graphics.renderTextureEx(replay,(350-100)/2,360,0);
            graphics.presentScene();
            die = 1;
            while(true)
            {
                if(SDL_PollEvent(&event) != 0 && event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
                {
                    resetGame();
                    Play = 0;
                    break;
                }
            }
        }
        else{
         if (updateScore(pipe[0])){
            score++;
            if(isSound) graphics.playSound(sPoint);
         }
         graphics.prepareScene();
         frameStart = SDL_GetTicks();
         while(SDL_PollEvent(&event)!=0){
            if (event.type == SDL_QUIT) quit = true;
            const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
            if(currentKeyStates[SDL_SCANCODE_SPACE] || event.type == SDL_MOUSEBUTTONDOWN){
                bird.turnUp();
                if(isSound) graphics.playSound(sFlap);
            }
            else bird.turnDown();
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m ) updateSound();
         }
         bird.move();
         bgrr.scroll(2);
         graphics.renderScrolling(bgrr,0);
         for(int i = 0;i < pipe.size();i++)
         {
             pipe[i].scroll(2);
             pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Up(), graphics, 1);
             pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Un(), graphics, 2);
         }
         if(pipe[0].checkPipeOut())
         {
             pipe.erase(pipe.begin());
             tPipe.setPosX(pipe[2].getX()+220);
             tPipe.setPosY(rand()%141);
             pipe.push_back(tPipe);
         }
         renderScore(score);
         renderSound();
         land.scroll(2);
         graphics.renderScrolling(land,500);
         bird.render(bird,graphics);
         graphics.presentScene();
         frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < 1000 / TARGET_FPS){
            SDL_Delay((1000 / TARGET_FPS) - frameTime);
        }
        }

    }
}
void Game::resetGame()
{
    bird.reset();
    pipe.clear();
    for(int i = 0;i <= 3;i ++)
    {
        tPipe.setPosX(500 + 220*i);
        tPipe.setPosY(rand()%141);
        pipe.push_back(tPipe);
    }
    score = 0;
}

