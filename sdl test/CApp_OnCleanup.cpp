//
//  CApp_OnCleanup.cpp
//  sdl test
//
//  Created by Richard on 10/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#include "CApp.hpp"

void CApp::onCleanup()
{
    //Free loaded image
    SDL_FreeSurface( surface );
    surface = NULL;
    
    //destroy renderer
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    
    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    
}
