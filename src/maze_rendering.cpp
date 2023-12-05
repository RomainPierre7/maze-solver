#include "maze_rendering.hpp"

static int getOwnRed(int i){
    return 3 * i;
}

static int getOwnGreen(int i){
    return 5 * i;
}

static int getOwnBlue(int i){
    return 7 * i;
}

void mazeUpdate(SDL_Renderer* pRenderer, std::array<int, MAZE_SIZE<int>> maze, std::array<SDL_Rect, MAZE_SIZE<int>> squares){
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