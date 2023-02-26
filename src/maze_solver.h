#ifndef __MAZE_SOLVER_H__
#define __MAZE_SOLVER_H__

#include <SDL2/SDL.h>
#include <array>
#include <cstdlib>
#include "const.h"
#include "maze_crea.h"

void mazeSolver(SDL_Renderer* pRenderer, std::array<int, MAZE_SIZE<int>> maze, std::array<SDL_Rect, MAZE_SIZE<int>> squares);

#endif // __MAZE_SOLVER_H__