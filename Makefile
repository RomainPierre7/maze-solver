all: program

program:
	g++ src/main.cpp src/maze_crea.cpp src/maze_solver.cpp -o prog -lSDL2main -lSDL2
