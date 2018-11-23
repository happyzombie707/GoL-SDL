## Extendable cellular automata thing

Run cellular automata defined in a lua file.

The Lua file must contain: 
 * Global variables containing the `name` of the cellular automata, the `version` and a table of `colors` for the states.
 * Function named iterate that takes one parameter (current state of the grid) and returns the new state of the grid.
 
 See life.lua for an example


### Building
Requires SDL2, SDL2_Image and liblua, build with `make all`.


### Running
Run with `./GoL.out <automaton.lua>`

### Bugs, things to do
 * Renderer is just all around really dodgy, needs to be redone, hopefully using OpenGL (for 2D and potentially 3D CAs).
 * UI stuff (started, far from finished).
