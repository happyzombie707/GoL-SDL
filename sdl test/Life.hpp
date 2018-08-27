//
//  Life.hpp
//  sdl test
//
//  Created by Richard on 12/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#ifndef Life_hpp
#define Life_hpp

#include <stdio.h>
#include <vector>

#endif /* Life_hpp */

class Life {
    
private:
    std::vector<std::vector<bool>> updateGrid;
    
    bool isAlive(int x, int y);
    bool calculateState(int x, int y);
    
public:
    int height, width;
    std::vector<std::vector<bool>> grid;
    
    Life(int w, int h);
    void iterate();
    void clear();
    void setCell(int x, int y, bool val);
};

