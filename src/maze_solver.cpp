#include "maze_solver.h"

void mazeSolver(SDL_Renderer* pRenderer, std::array<int, MAZE_SIZE<int>> maze, std::array<SDL_Rect, MAZE_SIZE<int>> squares){
    std::array<int, MAZE_SIZE<int>> maze_distance;
    for (int i = 0; i < MAZE_SIZE<int>; i++){
        maze_distance[i] = -1;
    }
    maze_distance[END - 1] = 0;
    while (maze_distance[START + 1] == -1){
        for (int i = 0; i < MAZE_SIZE<int>; i++){
                if ((maze_distance[i] != -1) && (!isWall(maze[i]))){
                    if (!isWall(maze[UP(i)])){
                        if (maze_distance[UP(i)] == -1){
                            maze_distance[UP(i)] = maze_distance[i] + 1;
                        }
                    }
                    if (!isWall(maze[DOWN(i)])){
                        if (maze_distance[DOWN(i)] == -1){
                            maze_distance[DOWN(i)] = maze_distance[i] + 1;
                        }
                    }
                    if (!isWall(maze[LEFT(i)])){
                        if (maze_distance[LEFT(i)] == -1){
                            maze_distance[LEFT(i)] = maze_distance[i] + 1;
                        }
                    }
                    if (!isWall(maze[RIGHT(i)])){
                        if (maze_distance[RIGHT(i)] == -1){
                            maze_distance[RIGHT(i)] = maze_distance[i] + 1;
                        }
                    }
                }
        }
    }
    for (int i = 0; i < MAZE_SIZE<int>; i++){
        if ((maze_distance[i] == -1) || (isWall(maze[i]))){
            maze_distance[i] = 0;
        }
    }

    int current = START + 1;
    maze[current] += 125;
    while (current != END - 1){
        if ((maze_distance[UP(current)] == maze_distance[current] - 1) && (!isWall(maze[UP(current)]))){
            current = UP(current);
        }
        else if ((maze_distance[DOWN(current)] == maze_distance[current] - 1) && (!isWall(maze[DOWN(current)]))){
            current = DOWN(current);
        }
        else if ((maze_distance[LEFT(current)] == maze_distance[current] - 1) && (!isWall(maze[LEFT(current)]))){
            current = LEFT(current);
        }
        else if ((maze_distance[RIGHT(current)] == maze_distance[current] - 1) && (!isWall(maze[RIGHT(current)]))){
            current = RIGHT(current);
        }
        maze[current] += 125;
        mazeUpdate(pRenderer, maze, squares);
        SDL_Delay(100);
    }
    printf("Maze solved\n");
}