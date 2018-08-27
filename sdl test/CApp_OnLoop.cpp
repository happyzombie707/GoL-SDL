#include "CApp.hpp"

bool CApp::isAlive(int x, int y)
{
    x += GRID_WIDTH;
    x %= GRID_WIDTH;
    
    y += GRID_HEIGHT;
    y %= GRID_HEIGHT;
    
    return grid[x][y];
}

bool CApp::calculateState(int x, int y)
{
    int alive = 0;
    
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if ((i || j) && isAlive(x+i, y+j))
            {
                alive++;
            }
        }
    }


    if (alive == 2) return grid[x][y];
    if (alive == 3) return true;
    if (alive < 2) return false;
    if (alive > 3) return false;

    return false;    
}

void CApp::onLoop()
{
    currentTime = SDL_GetTicks();
   
    if(currentTime > nextFrame)
    {
        gol.iterate();
        nextFrame = SDL_GetTicks() + tickLength;
    }
    
}
