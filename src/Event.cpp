//
//  CApp_OnEvent.cpp
//  sdl test
//
//  Created by Richard on 10/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#include "GoL.hpp"

void CApp::toggleGrid(int x, int y)
{
    bool t = gol.grid[x][y];
    
    printf("%d\n", t);
    gol.grid[x][y] = true;
    onRender();
}

void CApp::handleMouseDown(SDL_Event e)
{

    int x = e.motion.x ;
    int y = e.motion.y;
    
    if (e.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseMode = MOUSEMODE_MOVE;
        oldX = x;
        oldY = y;
        return;
    }
        

    currentDrawX = (x + viewport.x) / CELL_WIDTH;
    currentDrawY = (y + viewport.y) / CELL_HEIGHT;
    
    gol.grid[currentDrawX][currentDrawY] = e.button.button == SDL_BUTTON_LEFT ? drawType : 0;

    mouseMode = MOUSEMODE_DRAW;
    
    onRender();
}

void CApp::handleMouseMove(SDL_Event e)
{
    
    int x = e.motion.x ;
    int y = e.motion.y;
    
    if(mouseMode == MOUSEMODE_MOVE)
    {
        //printf("Move %d, %d\n", x - oldX, y - oldY);
        int moveX = viewport.x + (oldX - x);
        int moveY = viewport.y + (oldY - y);
                
        if(moveX > 0 && moveX < gol.width * CELL_WIDTH - SCREEN_WIDTH)
            viewport.x = moveX;

        if(moveY > 0 && moveY < gol.height * CELL_HEIGHT - SCREEN_HEIGHT)
            viewport.y = moveY;
        
        oldX = x;
        oldY = y;
        
        onRender();
        
    }else if(mouseMode == MOUSEMODE_DRAW){

        
        int gX = (x + viewport.x) /CELL_WIDTH;
        int gY = (y + viewport.y) /CELL_HEIGHT;
        
        
        
        if(currentDrawX != gX || currentDrawY != gY)
        {
            gol.grid[gX][gY] = e.button.button == SDL_BUTTON_LEFT ? drawType : 0;
            currentDrawX = gX;
            currentDrawY = gY;
            onRender();
        }
    }
    
    
}

void CApp::handleMouseUp(SDL_Event e)
{
    mouseMode = MOUSEMODE_NONE;
    onRender();
}

void CApp::clearGrid()
{
    gol.clear();
    onRender();
}

void CApp::setBrush(char v)
{
    drawType = v - 48;
}

void CApp::onEvent()
{
    SDL_Event e;
    
    
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
        case SDL_KEYDOWN:
            if(e.key.keysym.sym == SDLK_SPACE)
                paused = !paused;
            if(e.key.keysym.sym == SDLK_c)
                clearGrid();
            if(e.key.keysym.sym == SDLK_EQUALS)
                tickLength -= 50;
            if(e.key.keysym.sym == SDLK_MINUS)
                tickLength += 50;
            if(e.key.keysym.sym >= '0' && e.key.keysym.sym <= '9')
                setBrush(e.key.keysym.sym);
            break;
        case SDL_MOUSEBUTTONDOWN:
            handleMouseDown(e);
            break;
        case SDL_MOUSEBUTTONUP:
            handleMouseUp(e);
            break;
        case SDL_MOUSEMOTION:
            handleMouseMove(e);
            break;
        case SDL_MOUSEWHEEL:
                int x, y;
                SDL_GetMouseState(&x, &y);
                CELL_HEIGHT += 0.5 * e.wheel.y;
                CELL_WIDTH += 0.5 * e.wheel.y;
                //printf("%d", e.wheel.y);
                //viewport.w += 5 * e.wheel.y;
                //viewport.h += 5 *  e.wheel.y;
                //viewport.x = x - viewport.w/2;
                //viewport.y = y - viewport.h/2;

                onRender();
                break;
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
        }
    }
}
