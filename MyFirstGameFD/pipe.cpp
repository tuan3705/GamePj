#include "pipe.h"
void PIPE::loadTexturePipe(Graphics g)
{
    pipeUp = g.loadTexture(PIPEUP);
    pipeUn = g.loadTexture(PIPEUN);
}
void PIPE::renderPipe( int x, int y, Graphics g, int role)
{
    if(role == 1) g.renderTextureEx(pipeUp, x, y, 0);
    else if(role == 2) g.renderTextureEx(pipeUn, x, y, 0);
}
void PIPE::scroll(int distance)
{
    upper.x -= distance;
    under.x -= distance;
}
void PIPE::setPosX(int PosX)
{
    upper.x = under.x = PosX;
}
void PIPE::setPosY(int PosY)
{
    upper.y = -320 + 100 + PosY;
    under.y = PosY + 270;
}
void PIPE::disY()
{
    upper.y -= 5;
    under.y += 5;
}
void PIPE::clearPipe()
{
    SDL_DestroyTexture(pipeUp);
    SDL_DestroyTexture(pipeUn);
}
int PIPE::getX()
{
    return (int)upper.x;
}
int PIPE::getY_Up()
{
    return (int)upper.y;
}
int PIPE::getY_Un()
{
    return (int)under.y;
}
bool PIPE::checkPipeOut()
{
    if(upper.x + 52 <= 0) return true;
    return false;
}

