#ifndef __MAZE_RENDERING_HPP__
#define __MAZE_RENDERING_HPP__

#include <SDL2/SDL.h>
#include <array>
#include "const.hpp"

void mazeUpdate(SDL_Renderer* pRenderer, std::array<int, MAZE_SIZE<int>> maze, std::array<SDL_Rect, MAZE_SIZE<int>> squares);

#endif //__MAZE_RENDERING_HPP__