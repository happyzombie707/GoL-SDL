
name = "Game of Life"   --global name field (required)
version = 1           --global version field(required)
--probably more things when I think of them


colors = {              --global colour table (required)
    {0,0,0},            --0: dead, black
    {255,255,255},      --1: alive, white
}

width = 0
height = 0

function isAlive(grid, x, y)
    xx = ((x-1 + width) % width) + 1
    yy = ((y-1 + height) % height) + 1

    if grid[xx][yy] == 0 then return false else return true end

end

function calculateState(grid, x, y)

    alive = 0

    for i = -1, 1 do
        for j = -1, 1 do
            if (i ~= 0 or j ~= 0) and isAlive(grid, x+i, y+j) then 
              alive = alive + 1 
            end
        end
    end

    if alive == 2 then return grid[x][y] end
    if alive == 3 then return 1 end
    
    return 0

end

--iterate function required, called each iteration
--current state of the grid is passed as a parameter
function iterate(grid)

    width = #grid
    height = #grid[1]    

    local updateGrid = {}      --table to be returned
    --init table
    for x=1,width do
        updateGrid[x] = {}
      for y=1,height do
        updateGrid[x][y] = 0
      end
    end

    --for each cell
    for y = 1, height do
        for x = 1, width do
            updateGrid[x][y] = calculateState(grid, x, y)
        end
    end

    return updateGrid --iterate must return a new grid of the same size as the original
end
