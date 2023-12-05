all: program

program:
	g++ src/main.cpp src/maze_crea.cpp src/maze_solver.cpp src/maze_rendering.cpp -o prog -lSDL2main -lSDL2
