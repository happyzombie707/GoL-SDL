#include "GoL.hpp"


int main( int argc, char* args[] )
{

    if(argc != 2)
    {
        printf("Invalid number of args, must specify lua file.\n");
        printf("Usage: ./GoL life.lua\n");
        return 1;
    }

    CApp app;
    return app.OnExecute(args[1]);
	
}

