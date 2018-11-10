
#include "GoL.hpp"

SDL_Rect r;

void CApp::drawGrid()
{
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    
    for(int i = 1; i < gol.width; i++)
    {
        SDL_RenderDrawLine(renderer, i*CELL_WIDTH, 0, i*CELL_WIDTH, gol.height*GRID_HEIGHT);
    }
    
    for(int i = 1; i < gol.height; i++)
    {
        SDL_RenderDrawLine(renderer, 0, i*CELL_HEIGHT, gol.width*CELL_WIDTH, i*CELL_WIDTH);
    }
}

void CApp::onRender()
{
    SDL_SetRenderTarget(renderer, drawTexture);
    
    SDL_RenderClear(renderer);

    for(int y = 0; y < gol.height; y++)
    {
        for(int x = 0; x < gol.width; x++)
        {
            if(gol.grid[x][y])
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }else{
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            
            r = {CELL_WIDTH * x, CELL_HEIGHT * y, CELL_WIDTH, CELL_HEIGHT};
            SDL_RenderFillRect(renderer, &r);
        }
    }
    
    drawGrid();
    
    
    SDL_SetRenderTarget(renderer, NULL);
    
    
    
    SDL_RenderCopy(renderer, drawTexture, &viewport, NULL);
    
    //SDL_RenderCopy(renderer, UI::onDraw(renderer), &viewport, &viewport);

    //ui.onDraw(renderer);
    SDL_RenderPresent(renderer);
    
}



