//
//  Window.h
//  sdl test
//
//  Created by Richard on 15/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#ifndef Window_h
#define Window_h

#include "Control.hpp"

class Window : public Control
{
private:

    short r, g, b, a;

public:
    Window(int x, int y, int w, int h);
    //void setBGColour(SDL_Color col) override;
    virtual void onDraw(SDL_Renderer* ren) override;
};

#endif /* Window_h */
