//
//  Control.hpp
//  sdl test
//
//  Created by Richard on 13/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#ifndef Control_hpp
#define Control_hpp

#include <vector>


class Control
{
    
private:
    
public:
    Control(int xPos, int yPos, int width, int height);
    bool isLeaf;
    int x, y, z;
    int h, w;
    SDL_Rect box;
    SDL_Color _bgColour = {255,255,255};
    std::vector<Control*> children;
    
    virtual void onDraw(SDL_Renderer* ren);
    void setBGColour(SDL_Color col);
    
};


#endif /* Control_hpp */
