local life = {
    name = "Conway's Game of Life",
    meep = 69,

}

colors = {
    {255,0,20},
    {100,255,0},
}

width = 0
height = 0

function isAlive(x, y)
    xx = ((x-1 + width) % width) + 1
    yy = ((y-1 + height) % height) + 1

    if grid[xx][yy] == 0 then return false else return true end

end

function calculateState(x, y)

    alive = 0

    for i = -1, 1 do
        for j = -1, 1 do
            if (i ~= 0 or j ~= 0) and isAlive(x+i, y+j) then 
              alive = alive + 1 
            end
        end
    end

    if alive == 0 then return grid[x][y] end
    if alive == 1 then return 1 end
    
    return 0

end

function iterate()

    width = #grid
    height = #grid[1]    
    
    local updateGrid = {}          -- create the matrix
    
    for x=1,width do
        updateGrid[x] = {}     -- create a new row
      for y=1,height do
        updateGrid[x][y] = 0
      end
    end

    for y = 1, height do
        for x = 1, width do
            updateGrid[x][y] = calculateState(x, y)
        end
    end
    return updateGrid
end

return life



--[[

    lua newtable



]]