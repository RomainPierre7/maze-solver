#include "maze_crea.hpp"

bool isWall(int i){
    return i == 0;
}

bool isExternWall(int i){
    return (i % SIDE_SIZE<int> == 0) || (i % SIDE_SIZE<int> == SIDE_SIZE<int> - 1) || (i / SIDE_SIZE<int> == 0) || (i / SIDE_SIZE<int> == SIDE_SIZE<int> - 1);
}

bool isAllSame(std::array <int, MAZE_SIZE<int>> maze){
    for (int i = START + 1; i < MAZE_SIZE<int>; i++){
        if (!isWall(maze[i])){
            if (maze[i] != maze[START+1]){
            return false;
            }
        }
    }
    return true;
}

void complexMaze(std::array<int, MAZE_SIZE<int>>& maze, std::array<SDL_Rect, MAZE_SIZE<int>>& squares){
    for (int i = 0; i < SIDE_SIZE<int> / 2; i++){
        int wall = rand() % MAZE_SIZE<int>;
        while (((!isWall(maze[wall])) || (isExternWall(wall))) || (!(((wall % SIDE_SIZE<int>) % 2) && ((wall / SIDE_SIZE<int>) % 2 == 0)) && !(((wall % SIDE_SIZE<int>) % 2 == 0) && ((wall / SIDE_SIZE<int>) % 2)))){
            wall = rand() % MAZE_SIZE<int>;
        }
        if (((wall % SIDE_SIZE<int>) % 2) && ((wall / SIDE_SIZE<int>) % 2 == 0)){
            int case1 = UP(wall);
            maze[wall] = maze[case1];
        } else if (((wall % SIDE_SIZE<int>) % 2 == 0) && ((wall / SIDE_SIZE<int>) % 2)){
            int case1 = LEFT(wall);
            maze[wall] = maze[case1];
        }
        SDL_Delay(100);
    }
}

void mazeCrea(std::array<int, MAZE_SIZE<int>>& maze, std::array<SDL_Rect, MAZE_SIZE<int>>& squares){

    while (!isAllSame(maze)){
        int wall = rand() % MAZE_SIZE<int>;
        while (((!isWall(maze[wall])) || (isExternWall(wall))) || (!(((wall % SIDE_SIZE<int>) % 2) && ((wall / SIDE_SIZE<int>) % 2 == 0)) && !(((wall % SIDE_SIZE<int>) % 2 == 0) && ((wall / SIDE_SIZE<int>) % 2)))){
            wall = rand() % MAZE_SIZE<int>;
        }
        if (((wall % SIDE_SIZE<int>) % 2) && ((wall / SIDE_SIZE<int>) % 2 == 0)){
            int case1 = UP(wall);
            int case2 = DOWN(wall);
            int case2_value = maze[case2];
            if (maze[case1] != maze[case2]){
                maze[wall] = maze[case1];
                for (int i = 0; i < MAZE_SIZE<int>; i++){
                    if (maze[i] == case2_value){
                        maze[i] = maze[case1];
                    }
                }
            }
        } else if (((wall % SIDE_SIZE<int>) % 2 == 0) && ((wall / SIDE_SIZE<int>) % 2)){
            int case1 = LEFT(wall);
            int case2 = RIGHT(wall);
            int case2_value = maze[case2];
            if (maze[case1] != maze[case2]){
                maze[wall] = maze[case1];
                for (int i = 0; i < MAZE_SIZE<int>; i++){
                    if (maze[i] == case2_value){
                        maze[i] = maze[case1];
                    }
                }
            }
        }
        SDL_Delay(5);
    }
    printf("Maze created\n");

    if (COMPLEX){
        complexMaze(maze, squares);
        printf("Complex maze created\n");
    }
}