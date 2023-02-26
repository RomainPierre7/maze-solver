#include <SDL2/SDL.h>   
#include <array>
#include <cstdlib>    
#include <time.h>
#include <thread>
#include "const.h"
#include "maze_crea.h"
#include "maze_solver.h"

void program(SDL_Window* pWindow, SDL_Renderer* pRenderer){
    std::array<int, MAZE_SIZE<int>> maze;
    std::array<SDL_Rect, MAZE_SIZE<int>> squares;

    for (int i = 0; i < MAZE_SIZE<int>; i++){
        squares[i] = { (i % SIDE_SIZE<int>) * (WIDTHSCREEN<int> / SIDE_SIZE<int>), (i / SIDE_SIZE<int>) * (HEIGHTSCREEN<int> / SIDE_SIZE<int>), WIDTHSCREEN<int> / SIDE_SIZE<int>, HEIGHTSCREEN<int> / SIDE_SIZE<int> };
        if (((i % SIDE_SIZE<int>) % 2 == 0) || ((i / SIDE_SIZE<int>) % 2 == 0)){
            maze[i] = 0;
        } else {
            maze[i] = i;
        }
    }

    SDL_SetWindowTitle(pWindow, "Maze Solver (creation)");
    mazeCrea(pRenderer, maze, squares);
    SDL_SetWindowTitle(pWindow, "Maze Solver (solution)");
    mazeSolver(pRenderer, maze, squares);
}

int main(int argc, char* argv[])
{
     if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }

     SDL_Window* pWindow{ nullptr };
    SDL_Renderer* pRenderer{ nullptr };

     if (SDL_CreateWindowAndRenderer(WIDTHSCREEN<unsigned int>, HEIGHTSCREEN<unsigned int>, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    std::thread Thread(program, pWindow, pRenderer);

    SDL_Event events;

     while (true)
    {
         while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                SDL_DestroyRenderer(pRenderer);
                SDL_DestroyWindow(pWindow);
                SDL_Quit();
                return EXIT_SUCCESS;
                break;
            }
        }
    }

    Thread.join();

    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return EXIT_SUCCESS;
}