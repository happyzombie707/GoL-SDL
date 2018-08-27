
#ifndef UI_hpp
#define UI_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <vector>
#include "Control.hpp"


class UI;
class Control;

static SDL_Texture* uiTexture;
static SDL_Surface* uiSurf;





class UI
{

private:

    std::vector<Control*> controls;

public:
    

    
    void addControl(Control* c)
    {
        printf("%p\n", c);
        controls.push_back(c);
    }
    
    void onDraw(SDL_Renderer* ren)
    {
        


        for(int i = 0; i < controls.size(); i++)
        {
            //controls[i]->onDraw(ren);
        }
        
        
       //SDL_SetRenderTarget(ren, NULL);
        
        //return NULL;

    }
};




#endif /* UI_hpp */

