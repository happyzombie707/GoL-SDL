#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/GoL.hpp src/GoL.cpp src/Init.cpp src/Loop.cpp src/Render.cpp src/Event.cpp src/Cleanup.cpp src/Life.hpp src/Life.cpp #src/UI/Control.hpp src/UI/Control.cpp src/UI/UI.hpp src/UI/UI.cpp
#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -ggdb

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -llua

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = GoL.out

run: all
	./GoL.out

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm GoL.out
