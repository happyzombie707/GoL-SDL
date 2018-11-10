#ifndef Life_hpp
#define Life_hpp

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

#include <string>
#include <array>
#include <vector>



#endif /* Life_hpp */





class Life {
        
public:


    //typedef enum state {DEAD,ALIVE} State;

    int height, width;
    std::vector<std::vector<int>> grid;
    std::vector<std::array<int, 3>> stateColors;

    Life(int w, int h);
    Life(int w, int h, char * luapath);
    void iterate();
    void clear();
    //void setCell(int x, int y, int val);
    //int calculateState(int x, int y);
    private:
    std::vector<std::vector<int>> updateGrid;
    lua_State *L;
    //int isAlive(int x, int y);
    //void luaTest();
    
};

