//
//  Window.cpp
//  sdl test
//
//  Created by Richard on 14/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//


#include "Window.h"

Window::Window(int x, int y, int w, int h) : Control(x, y, w, h)
{
    //printf("%dx%d - %d %d\n", x, y, w, h);
    _bgColour = {0, 255, 255};
}




void Window::onDraw(SDL_Renderer* ren)
{
    //printf("xdxdxdxd");
    
    r = this->_bgColour.r;
    g = this->_bgColour.g;
    b = this->_bgColour.b;
    SDL_SetRenderDrawColor(ren, r, g, b, 255);
    SDL_RenderFillRect(ren, &box);

    
    return;
}

/*
void Window::setBGColour(SDL_Color col)
{
    _bgColour.r = col.r;
    _bgColour.g = col.g;
    _bgColour.b = col.b;
    printf("%d %d %d\n", col.r, col.g, col.b);
    
    
}
*/
