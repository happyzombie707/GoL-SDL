name = "Wireworld"   --global name field (required)
version = 1           --global version field(required)
--probably more things when I think of them


colors = {              --global colour table (required)
    {17,17,17},            --0: empty - black
    {73, 208, 239},      --1: electron head - blue
    {239, 73, 73},       --2: electron tail - red
    {239,185,73},        --3: conductor - yellow
}

width = 0
height = 0


function doesConduct(grid, x, y)

    xx = ((x-1 + width) % width) + 1
    yy = ((y-1 + height) % height) + 1

    return grid[xx][yy] == 1

end

function calculateState(grid, x, y)

    state = 0

    if(grid[x][y] == 1) then
        state = 2
    elseif(grid[x][y] == 2) then
        state = 3
    elseif(grid[x][y] == 3) then
        local n = 0
        state = 3
        for i = -1, 1 do
            for j = -1, 1 do
                if (i ~= 0 or j ~= 0) and doesConduct(grid, x+i, y+j) then 
                  n = n + 1 
                end
            end
        end
        if n == 1 or n == 2 then state = 1 end
    end

    return state

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
