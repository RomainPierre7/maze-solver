#ifndef __MAZE_SOLVER_HPP__
#define __MAZE_SOLVER_HPP__

#include <SDL2/SDL.h>
#include <array>
#include <cstdlib>
#include "const.hpp"
#include "maze_crea.hpp"

void mazeSolver(SDL_Renderer* pRenderer, std::array<int, MAZE_SIZE<int>> maze, std::array<SDL_Rect, MAZE_SIZE<int>> squares);

#endif // __MAZE_SOLVER_HPP__