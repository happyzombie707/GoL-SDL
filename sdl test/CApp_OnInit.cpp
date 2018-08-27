//
//  CApp_OnInit.cpp
//  sdl test
//
//  Created by Richard on 10/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#include "CApp.hpp"


bool CApp::onInit()
{

    memset(grid, 0, sizeof(grid));
    memset(update, 0, sizeof(update));
    
    viewport.x = 0;
    viewport.y = 0;
    viewport.h = SCREEN_HEIGHT;
    viewport.w = SCREEN_WIDTH;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    
    //Create window
    window = SDL_CreateWindow("mem xd", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if( window == NULL )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_TEXTUREACCESS_TARGET | SDL_RENDERER_TARGETTEXTURE);
    if(renderer == NULL)
    {
        printf("error creating renderer!\n");
        return false;
    }
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    
    drawTexture = SDL_CreateTexture(renderer, SDL_GetWindowPixelFormat(window), SDL_TEXTUREACCESS_TARGET, gol.width*CELL_WIDTH, gol.height*CELL_HEIGHT);
    
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }
    
    //Get window surface
    surface = SDL_GetWindowSurface( window );
    
    onRender();
    printf("%d, %d\n", gol.width*CELL_WIDTH, CELL_HEIGHT*gol.height);
    return true;
}

SDL_Surface* CApp::loadSurface( const char* path )
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, surface->format, NULL );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError() );
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    return optimizedSurface;
}

bool CApp::loadMedia(const char path[], SDL_Surface* surf)
{
    //Loading success flag
    bool success = true;
    
    //Load PNG surface
    surf = loadSurface( path );
    if( surf == NULL )
    {
        printf( "Failed to load PNG image!\n" );
        success = false;
    }
    
    return success;
}
