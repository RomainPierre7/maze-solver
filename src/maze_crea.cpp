#include "maze_crea.h"
#define START SIDE_SIZE<int> + 1
#define END MAZE_SIZE<int> - SIDE_SIZE<int> - 2

int getOwnRed(int i){
    return 3 * i % 255;
}

int getOwnGreen(int i){
    return 5 * i % 255;
}

int getOwnBlue(int i){
    return 7 * i % 255;
}

void maze_crea(SDL_Renderer* pRenderer)
{
    std::array<int, MAZE_SIZE<int>> maze;
    std::array<SDL_Rect, MAZE_SIZE<int>> squares;
    
    for (int i = 0; i < MAZE_SIZE<int>; i++){
        squares[i] = { (i % SIDE_SIZE<int>) * (WIDTHSCREEN<int> / SIDE_SIZE<int>), (i / SIDE_SIZE<int>) * (HEIGHTSCREEN<int> / SIDE_SIZE<int>), WIDTHSCREEN<int> / SIDE_SIZE<int>, HEIGHTSCREEN<int> / SIDE_SIZE<int> };
        if ((i % 2) || (i / SIDE_SIZE<int> % 2 == 0)){
            maze[i] = 0;
        } else {
            maze[i] = i;
        }
    }

    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

    for (int i = 0; i < MAZE_SIZE<int>; i++){
        SDL_SetRenderDrawColor(pRenderer, getOwnRed(maze[i]), getOwnGreen(maze[i]), getOwnBlue(maze[i]), 255);
        SDL_RenderFillRect(pRenderer, &squares[i]);
    }
    SDL_SetRenderDrawColor(pRenderer, 0, 255, 0, 255);
    SDL_RenderFillRect(pRenderer, &squares[START]);
    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(pRenderer, &squares[END]);

    SDL_RenderPresent(pRenderer);
}