//
//  Life.cpp
//  sdl test
//
//  Created by Richard on 12/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#include "Life.hpp"


Life::Life(int w, int h)
{
    width = w; height = h;
    grid.resize(width, std::vector<bool>(height, false));
    updateGrid.resize(width, std::vector<bool>(height, false));
}


void Life::clear()
{
    grid.clear();
    grid.resize(width, std::vector<bool>(height, false));
}

bool Life::isAlive(int x, int y)
{
    x = (x + width) % width;
    y = (y + height) % height;
    
    return grid[x][y];
}

bool Life::calculateState(int x, int y)
{
    int alive = 0;
    
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if ((i || j) && isAlive(x+i, y+j))
            {
                alive++;
            }
        }
    }
    
    
    if (alive == 2) return grid[x][y];
    if (alive == 3) return true;
    if (alive < 2) return false;
    if (alive > 3) return false;
    
    return false;
}

void Life::setCell(int x, int y, bool val)
{
    grid[x][y] = val;
}

void Life::iterate()
{
    
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            updateGrid[x][y] = calculateState(x, y);
        }
    }
    
    grid = updateGrid;
    updateGrid.resize(width, std::vector<bool>(height, false));

}
