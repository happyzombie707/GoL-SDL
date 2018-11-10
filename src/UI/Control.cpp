//
//  Control.cpp
//  sdl test
//
//  Created by Richard on 13/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#include "UI.hpp"

Control::Control(int xPos, int yPos, int width, int height)
{
    x = xPos; y = yPos;
    w = width; h = height;
    
    box = {x, y, w, h};
    
}

void Control::setBGColour(SDL_Color xdddddd)
{
    printf("before change %d %d %d\n", _bgColour.r, _bgColour.g, _bgColour.b);
    printf("new           %d %d %d\n", xdddddd.r, xdddddd.g, xdddddd.b);
    this->_bgColour = xdddddd;
    printf("after change  %d %d %d\n\n", _bgColour.r, _bgColour.g, _bgColour.b);

}

void Control::onDraw(SDL_Renderer* ren){
    printf("xd lole");
}
