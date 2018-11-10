#include "Life.hpp"
#include <iostream>


/*
    UTILITY FUNCTIONS
*/
int getIntField(lua_State* L, const char* key)
{
    lua_getglobal(L, key);
 
    int result = (int)lua_tonumber(L, -1);
    lua_pop(L, 1);  // remove number from stack
    return result;
}
 
std::string getStringField(lua_State* L, const char* key)
{
    lua_getglobal(L, key);
 
    std::string result = lua_tostring(L, -1);
    lua_pop(L, 1);  // remove string from stack
    return result;
}

//returns the global colour table defined in the lua file
/* e.g. 
colors = {
    {255, 0, 0},
    {0, 255, 0},
    {0, 0, 255},
}
*/
std::vector<std::array<int,3>> getColors(lua_State* L, const std::string& name) {
    std::vector<std::array<int,3>> v;

    //get table
    lua_getglobal(L, "colors");
    if(lua_isnil(L, -1)) {
        return v;
    }
    //holders for rgb value
    int r, g, b;

    //set up stack 
    lua_pushnil(L);

    //for each colour
    while (lua_next(L, -2))
    {
    
        lua_pushnil(L);
    
        //read rgb values
        lua_next(L, -2);
        r = (int)lua_tonumber(L, -1);
        lua_pop(L, 1);
    
        lua_next(L, -2);
        g = (int)lua_tonumber(L, -1);
        lua_pop(L, 1);
    
        lua_next(L, -2);
        b = (int)lua_tonumber(L, -1);
        lua_pop(L, 1);
        //push to vector
        v.push_back({r, g, b});
        lua_pop(L, 2);
    }
    

    return v;
}


/*
    LIFE CLASS
*/
Life::Life(int w, int h)
{
    width = w; height = h;
    grid.resize(width, std::vector<int>(height, 0));
    updateGrid.resize(width, std::vector<int>(height, 0));
}

Life::Life(int w, int h, char * luapath)
{
    width = w; height = h;
    grid.resize(width, std::vector<int>(height, 0));
    updateGrid.resize(width, std::vector<int>(height, 0));
    
    L = luaL_newstate();
    luaL_openlibs(L);

    luaL_loadfile(L, luapath);

    lua_pcall(L, 0, 1, 0);

    std::string name = getStringField(L, "name");
    int meep = getIntField(L, "meep");

    std::cout << "Loaded: " << name << " " << meep << "\n";
    stateColors = getColors(L, "colors");

}


void Life::clear()
{
    grid.clear();
    grid.resize(width, std::vector<int>(height, 0));
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

    if(lua_pcall(L, 1, 1, 0))
    {
        printf("%s\n", lua_tostring(L, -1));
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
    updateGrid.resize(width, std::vector<int>(height, 0));

}