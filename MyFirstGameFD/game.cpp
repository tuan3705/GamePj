#include "game.h"
#include<bits/stdc++.h>
using namespace std;
void Game::initG()
{
    graphics.init();
    tPipe.loadTexturePipe(graphics);
    for(int i = 0;i <= 3;i++)
    {
        tPipe.setPosX(350 + 220 * i);
        tPipe.setPosY(rand() % 141);
        pipe.push_back(tPipe);
    }
    for(int i= 0;i <= 9; i++)
    {
        string tmp1 = "Picture/BigNum/" + to_string(i) + ".png";
        SDL_Texture* num = graphics.loadTexture(tmp1.c_str());
        largeNum.push_back(num);
        string tmp2 = "Picture/SmallNum/" + to_string(i) + ".png";
        SDL_Texture* num2 = graphics.loadTexture(tmp2.c_str());
        smallNum.push_back(num2);
    }
    for(int i = 0; i <= 2; i++)
    {
        string tmp1 = "Picture/medal/"+to_string(i) + ".png";
        SDL_Texture* md = graphics.loadTexture(tmp1.c_str());
        medal.push_back(md);
    }
    fstream file("score.txt");
    file >> bestScore;
    file.close();
    Play = 0;
    isDay = 1;
    isSound = 1;
    score = 0;
    die = 0;
    quit = false;
    button = graphics.loadTexture("picture/button.png");
    pause = graphics.loadTexture("Picture/pause.png");
    pauseTab = graphics.loadTexture("Picture/pauseTab.png");
    resume = graphics.loadTexture("Picture/resume.png");
    RightButton = graphics.loadTexture("Picture/nextRight.png");
    LeftButton = graphics.loadTexture("Picture/nextLeft.png");
    Sound = graphics.loadTexture("Picture/soundon.png");
    NotSound = graphics.loadTexture("Picture/soundoff.png");
    replay = graphics.loadTexture("Picture/replay.png");
    message = graphics.loadTexture("Picture/message.png");
    TTgameOver = graphics.loadTexture("Picture/TTgameOVer.png");
    land.setTexture(graphics.loadTexture("Picture/land.png"));
    bgrr.setTexture(graphics.loadTexture("Picture/background-day.png"));
    bgrrN.setTexture(graphics.loadTexture("Picture/background-night.png"));
    sClick = graphics.loadSound("Sound/mouse-click.mp3");
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
void Game::updateBestScore()
{
    bestScore = score;
    fstream file("score.txt");
    file << bestScore;
    file.close();
}
void Game::changeBackground()
{
    isDay += 1;
    isDay %= 2;
}
void Game::renderLargeScore(int sc)
{
    string s = to_string(sc);
    int width = 30;
    int PosX = (SCREEN_WIDTH - width*s.length())/2;
    for(int i = 0; i < s.length(); i++)
    {
        graphics.renderTextureEx(largeNum[s[i]-'0'], PosX, 10, 0);
        PosX += 30;
    }
}
void Game::renderSmallScore(int sc, int posY)
{
    string s = to_string(sc);
    int width = 21;
    int PosX = 271  - 21*s.length();
    for(int i = 0; i < s.length(); i++)
    {
        graphics.renderTextureEx(smallNum[s[i]-'0'], PosX, posY, 0);
        PosX += 21;
    }
}
void Game::renderMedal()
{
    if(score >= 10 && score < 20 ) graphics.renderTextureEx(medal[0], 75, 263, 0);
    else if(score >= 20 && score < 30) graphics.renderTextureEx(medal[1], 75, 263, 0);
    else if(score >= 30) graphics.renderTextureEx(medal[2], 75, 263, 0);
}
void Game::updateSound()
{
    isSound++;
    isSound %= 2;
}
void Game::renderSound(int x,int y)
{
    if(isSound) graphics.renderTextureEx(Sound, x, y, 0);
    else graphics.renderTextureEx(NotSound, x, y, 0);
}
void Game::animation_dead(){
    if(isSound) graphics.playSound(sDead);
    SDL_Delay(100);
    bird.setAngle(180);
    SDL_Event event;
    while(bird.getY() <= 485)
    {
        graphics.prepareScene();
        if(isDay) graphics.renderScrolling(bgrr, 0);
        else graphics.renderScrolling(bgrrN, 0);
        for(int i = 0; i < pipe.size(); i++)
        {
            pipe[i].disY();
            pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Up(), graphics, 1);
            pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Un(), graphics, 2);
        }
        graphics.renderScrolling(land,500);
        bird.disY();
        bird.render(bird,graphics);
        graphics.presentScene();
    }
    for(int i = 1;i <= 50; i++ )
    {
        graphics.prepareScene();
        if(isDay) graphics.renderScrolling(bgrr, 0);
        else graphics.renderScrolling(bgrrN, 0);
        for(int j = 0; j < pipe.size(); j++)
        {
            pipe[j].disY();
            pipe[j].renderPipe( pipe[j].getX(), pipe[j].getY_Up(), graphics, 1);
            pipe[j].renderPipe( pipe[j].getX(), pipe[j].getY_Un(), graphics, 2);
        }
        graphics.renderScrolling(land,500);
        bird.render(bird, graphics);
        graphics.presentScene();
    }
    for(int i = 1;i <= 209; i+=2 )
    {
        graphics.prepareScene();
        if(isDay) graphics.renderScrolling(bgrr, 0);
        else graphics.renderScrolling(bgrrN, 0);
        for(int i = 0; i < pipe.size(); i++)
        {
            pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Up(), graphics, 1);
            pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Un(), graphics, 2);
        }
        graphics.renderScrolling(land, 500);
        bird.render(bird, graphics);
        graphics.renderTextureEx(TTgameOver, (350-TTgameOver_WIDTH)/2 , (500-TTgameOver_HEIGHT)/2 + 209 - i, 0);
        graphics.presentScene();
    }
    renderMedal();
    renderSmallScore(score, 263);
    renderSmallScore(bestScore, 313);
    graphics.renderTextureEx(replay, (350-100)/2, 360, 0);
    graphics.presentScene();
    die = 1;
    while(true)
    {
        if(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&mouseX,&mouseY);
                if(mouseX >= 125 && mouseX <= 225 && mouseY >= 360 && mouseY <= 416)
                {
                    if(isSound) graphics.playSound(sClick);
                    resetGame();
                    Play = 0;
                    break;
                }
            }
            if(event.type == SDL_QUIT ) { quit = 1; break;}
        }
    }

};
void Game::pause_game(){
    SDL_Event event;
    while(true)
    {
        graphics.prepareScene();
        if(isDay) graphics.renderScrolling(bgrr, 0);
        else graphics.renderScrolling(bgrrN, 0);
        for(int i = 0; i < pipe.size(); i++)
        {
            pipe[i].renderPipe(pipe[i].getX(), pipe[i].getY_Up(), graphics, 1);
            pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Un(), graphics, 2);
        }
        renderLargeScore(score);
        graphics.renderScrolling(land, 500);
        bird.render(bird, graphics);

        graphics.renderTextureEx(pauseTab, (SCREEN_WIDTH-250)/2, (SCREEN_HEIGHT-128)/2-17, 0);
        graphics.renderTextureEx(resume, (SCREEN_WIDTH-26)/2, 365, 0);
        graphics.renderTextureEx(button, 105, 316, 0);
        renderSound(105, 266);
        renderSmallScore(score, 263);
        renderSmallScore(bestScore, 313);
        graphics.presentScene();
        if(SDL_PollEvent(&event) != 0){
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState( &mouseX, &mouseY );
                if(mouseX >= 105 && mouseX <= 105 + 32 && mouseY >= 266 && mouseY <= 266 + 24) {updateSound(); if(isSound) graphics.playSound(sClick);}
                if(mouseX >= 105 && mouseX <= 105 + 26 && mouseY >= 316 && mouseY <= 316 + 26) {changeBackground(); if(isSound) graphics.playSound(sClick);}
                if(mouseX >= 162 && mouseX <= 162 + 26 && mouseY >= 365 && mouseY <= 365 + 28) {if(isSound) graphics.playSound(sClick); break;}
            }
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p ) break;
            if(event.type == SDL_QUIT ) {quit = 1;die = 1; break;}
        }
        SDL_Delay(50);
    }
}
void Game::prepare(){
    die = 0;
    graphics.prepareScene();
    bgrr.scroll(2);
    bgrrN.scroll(2);
    if(isDay) graphics.renderScrolling(bgrr, 0);
    else graphics.renderScrolling(bgrrN, 0);
    land.scroll(2);
    graphics.renderScrolling(land, 500);
    graphics.renderTextureEx(LeftButton, 0, SCREEN_HEIGHT/2, 0);
    graphics.renderTextureEx(RightButton, SCREEN_WIDTH - 13, SCREEN_HEIGHT/2, 0);
    bird.render(bird, graphics);
    graphics.renderTextureEx(message, (SCREEN_WIDTH-MESSAGE_WIDTH)/2, (SCREEN_HEIGHT-MESSAGE_HEIGHT-LAND_HEIGHT)/2, 0);
    renderSound(10, 10);
    graphics.renderTextureEx(LeftButton, 31, 317, 0);
    graphics.renderTextureEx(RightButton, 90, 317, 0);
    graphics.presentScene();
    SDL_Delay(16);
    SDL_Event e;

    if ( SDL_PollEvent(&e) != 0)
    {
        if(e.type == SDL_QUIT) quit = true;
        if(e.type == SDL_KEYDOWN)
        {
            if(e.key.keysym.sym == SDLK_m) updateSound();
            if(e.key.keysym.sym == SDLK_SPACE) Play = true;
        }
        if(e.type == SDL_MOUSEBUTTONDOWN )
        {
            SDL_GetMouseState(&mouseX, &mouseY);
            if(mouseX >= 10 && mouseX <= 42 && mouseY >= 10 && mouseY <= 34 ) {updateSound(); if(isSound) graphics.playSound(sClick);}
            else if(mouseX >= 31 && mouseX <= 44 && mouseY >= 317 && mouseY <= 333 ){bird.updateTypeBird(-1); if(isSound) graphics.playSound(sClick);}
            else if(mouseX >= 90 && mouseX <= 103 && mouseY >= 317 && mouseY <= 333 ){bird.updateTypeBird(1); if(isSound) graphics.playSound(sClick);}
            else if(mouseX >= 0 && mouseX <= 13 && mouseY >= 312 && mouseY <= 328) {changeBackground(); if(isSound) graphics.playSound(sClick);}
            else if(mouseX >= 337 && mouseX <= 350 && mouseY >= 312 && mouseY <= 328) {changeBackground(); if(isSound) graphics.playSound(sClick);}
            else Play = true;
        }
    }
}
void Game::updateG()
{
             graphics.prepareScene();
         bird.move();
         bgrr.scroll(2);
         bgrrN.scroll(2);
         if(isDay) graphics.renderScrolling(bgrr, 0);
         else graphics.renderScrolling(bgrrN, 0);
         for(int i = 0; i < pipe.size(); i++)
         {
             pipe[i].scroll(2);
             pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Up(), graphics, 1);
             pipe[i].renderPipe( pipe[i].getX(), pipe[i].getY_Un(), graphics, 2);
         }
         if(pipe[0].checkPipeOut())
         {
             pipe.erase(pipe.begin());
             tPipe.setPosX(pipe[2].getX() + 220);
             tPipe.setPosY(rand() % 141);
             pipe.push_back(tPipe);
         }
         renderLargeScore(score);
         land.scroll(2);
         graphics.renderScrolling(land, 500);
         bird.render(bird,graphics);
         graphics.renderTextureEx(pause, 320, 10, 0);
         graphics.presentScene();
}
void Game::playGame(){
    const int TARGET_FPS = 60;
    Uint32 frameStart, frameTime;
    SDL_Event event;
    while(!die)
    {
        if(checkCollide(pipe[0])){
           if(score>bestScore) updateBestScore();
           animation_dead();
        }
        else{
         if (updateScore(pipe[0])){
            score++;
            if(isSound) graphics.playSound(sPoint);
         }
         frameStart = SDL_GetTicks();
         while(SDL_PollEvent(&event) != 0){
            if (event.type == SDL_QUIT) {quit = true; die = 1;}
            const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
            if(currentKeyStates[SDL_SCANCODE_SPACE]){
                bird.turnUp();
                if(isSound) graphics.playSound(sFlap);
            }
            else bird.turnDown();
            if(event.type == SDL_MOUSEBUTTONDOWN )
            {
                SDL_GetMouseState(&mouseX, &mouseY);
                if(mouseX >= 320 && mouseX <= 346 && mouseY >= 10 && mouseY <= 38)
                {
                    if(isSound) graphics.playSound(sClick);
                    pause_game();
                }
            }
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p )
            {
                pause_game();
            }
         }
         updateG();
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
        tPipe.setPosX(500 + 220 * i);
        tPipe.setPosY(rand() % 141);
        pipe.push_back(tPipe);
    }
    score = 0;
}
void Game::clearG()
{
    bird.clearBird();
    for(int i = 0; i < pipe.size(); i++)
    {
        pipe[i].clearPipe();
    }
    for(int i = 0; i < 9; i++)
    {
        SDL_DestroyTexture(largeNum[i]);
        SDL_DestroyTexture(smallNum[i]);
    }
    for(int i = 0; i < 3; i++)
    {
        SDL_DestroyTexture(medal[i]);
    }
    SDL_DestroyTexture(button);
    SDL_DestroyTexture(pause);
    SDL_DestroyTexture(pauseTab);
    SDL_DestroyTexture(resume);
    SDL_DestroyTexture(RightButton);
    SDL_DestroyTexture(LeftButton);
    SDL_DestroyTexture(replay);
    SDL_DestroyTexture(message);
    SDL_DestroyTexture(TTgameOver);
    SDL_DestroyTexture(Sound);
    SDL_DestroyTexture(NotSound);
    Mix_FreeChunk(sClick);
    Mix_FreeChunk(sFlap);
    Mix_FreeChunk(sDead);
    Mix_FreeChunk(sPoint);
    graphics.quit();
}

