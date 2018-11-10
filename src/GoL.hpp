//
//  CApp.hpp
//  sdl test
//
//  Created by Richard on 10/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#ifndef CApp_hpp
#define CApp_hpp

#include "Life.hpp"
//#include "UI.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class CApp
{
    
private:
    bool running;
    bool paused;
    SDL_Window* window;
    SDL_Renderer* renderer;
    //UI ui;
    /*
        INIT
     */
    
    
    /*
        EVENT
     */
    const int MOUSEMODE_NONE = 0;
    const int MOUSEMODE_DRAW = 1;
    const int MOUSEMODE_MOVE = 2;
    
    int mouseMode;
    
    int oldX, oldY = 0;
    /*
        LOOP
     */
    
    int tickLength = 500;
    Uint32 currentTime;
    Uint32 nextFrame = 0;
    int stepTime;
    
    
    /*
        RENDER
     */
    
    int FPS = 60;
    int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    Life gol = Life(67, 35, "/home/richard/Documents/prog/C++/GoL/GoL-SDL/life.lua");

    int CELL_HEIGHT = 20;
    int CELL_WIDTH = 20;
    SDL_Texture* drawTexture; 
    /*
        CLEANUP
     */
    
    
    
    SDL_Surface* surface;
    SDL_Surface* pngSurface;
    
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    
    SDL_Rect viewport;
    
    const int GRID_WIDTH = 64;
    const int GRID_HEIGHT = 36;
    

    
    //int grid[20][15];
    void toggleGrid(int x, int y);
    void drawGrid();

    
    bool grid[64][36];
    bool update[64][36];
    
    
    bool calculateState(int x, int y);
    bool isAlive(int x, int y);


    bool isDrawing;
    bool drawType;
    int currentDrawX, currentDrawY;
    void handleMouseDown(SDL_Event e);
    void handleMouseMove(SDL_Event e);
    void handleMouseUp(SDL_Event e);
    void clearGrid();
    

    
public:
    CApp();
    
    int OnExecute();
    
    
    
    
    bool onInit();
    bool loadMedia(const char path[]);
    void onEvent();
    void onLoop();
    void onRender();
    void onCleanup();
    
    bool loadMedia(const char path[], SDL_Surface* surf);
    
    SDL_Surface* loadSurface( const char path[] );
    SDL_Surface loadFromPNG( const char path[] );

};




#endif /* CApp_hpp */
