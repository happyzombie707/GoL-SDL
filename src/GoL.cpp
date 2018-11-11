//
//  CApp.cpp
//  sdl test
//
//  Created by Richard on 10/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#include "GoL.hpp"
#include <thread>
//include "UI.hpp"
//#include "Window.h"

CApp::CApp() {
    running = true;
    paused = true;
}

int CApp::OnExecute(char *luafile)
{
    if(!onInit())
    {
        return -1;
    }
    
    gol = Life(gol.width, gol.height, luafile);

    //if(!loadMedia("meme.png", pngSurface))
    //{
   ////     return -1;
   // }
    
    
    /*pngSurface = loadSurface("meme.png");
    
    
    Window w = Window(10, 10, 100, 100);
    SDL_GetWindowPixelFormat(window);
    w.setBGColour(SDL_Color{255,0,0});
    
    Window w1 = Window(150, 10, 100, 100);
    SDL_GetWindowPixelFormat(window);
    w1.setBGColour(SDL_Color{0,255,0});
    
    Window w2 = Window(300, 10, 100, 100);
    w2.setBGColour(SDL_Color{0,0,255});
    
    Window w3 = Window(10, 150, 100, 100);
    w3.setBGColour(SDL_Color{255,255,0});
    
    Window w4 = Window(150, 150, 100, 100);
    w4.setBGColour(SDL_Color{255,0,255});
    
    Window w5 = Window(300, 150, 100, 100);
    w5.setBGColour(SDL_Color{0,255,255});
    
    //ui.addControl(&w);
    //ui.addControl(&w1);
    //ui.addControl(&w2);
    //ui.addControl(&w3);
    //ui.addControl(&w4);
    //ui.addControl(&w5);
    */
    
    while(running)
    {
        
        frameStart = SDL_GetTicks();
        onEvent();
        if(!paused)
        {
            onLoop();
            onRender();
            //UI::onDraw(renderer);
        }
        

        
        frameTime = SDL_GetTicks() - frameStart;
        
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
        
    }
    
    onCleanup();
    
    return 0;
}


