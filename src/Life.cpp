#include "Life.hpp"
#include <iostream>
int getIntField(lua_State* L, const char* key)
{
    lua_pushstring(L, key);
    lua_gettable(L, -2);  // get table[key]
 
    int result = (int)lua_tonumber(L, -1);
    lua_pop(L, 1);  // remove number from stack
    return result;
}
 
std::string getStringField(lua_State* L, const char* key)
{
    lua_pushstring(L, key);
    lua_gettable(L, -2);  // get table[key]
 
    std::string result = lua_tostring(L, -1);
    lua_pop(L, 1);  // remove string from stack
    return result;
}

Life::Life(int w, int h)
{
    width = w; height = h;
    grid.resize(width, std::vector<bool>(height, false));
    updateGrid.resize(width, std::vector<bool>(height, false));
}

Life::Life(int w, int h, char * luapath)
{
    width = w; height = h;
    grid.resize(width, std::vector<bool>(height, false));
    updateGrid.resize(width, std::vector<bool>(height, false));
    
    L = luaL_newstate();
    luaL_openlibs(L);

    luaL_loadfile(L, luapath);

    lua_pcall(L, 0, 1, 0);

    std::string name = getStringField(L, "name");
    int meep = getIntField(L, "meep");

    std::cout << "Loaded: " << name << " " << meep << "\n";

}

void Life::luaTest()
{


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
    
    return false;
}

void Life::setCell(int x, int y, bool val)
{
    grid[x][y] = val;
}

void Life::iterate()
{
    
    lua_getglobal(L, "iterate");    //call lua function
    
    lua_newtable(L);

    for(int x = 0; x < width; x++)
    {

        lua_newtable(L);

        for (int y = 0; y < height; y++)
        {   
            lua_pushnumber(L, y + 1);
            lua_pushnumber(L, grid.at(x).at(y));
            lua_settable(L, -3);
        }

        lua_rawseti(L, -2, x + 1); // RT[j] = CT
    }

    lua_setglobal(L, "grid");
    if(lua_pcall(L, 0, 1, 0))
    {
        printf("%s", lua_tostring(L, -1));
    }
    
    lua_pushnil(L);

    int x = 0;
    int y = 0;

    while (lua_next(L, -2))
    {
        lua_pushnil(L);
        while(lua_next(L, -2)) {
            updateGrid[x][y] = lua_tonumber(L, -1);
            lua_pop(L, 1);
            y++;
        }
        x++;
        y = 0;
        lua_pop(L, 1);
    }
    
    grid = updateGrid;
    updateGrid.resize(width, std::vector<bool>(height, false));

}