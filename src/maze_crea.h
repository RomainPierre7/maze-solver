#ifndef __MAZE_CREA_H__
#define __MAZE_CREA_H__

#include <SDL2/SDL.h>
#include <array>
#include <cstdlib>
#include "const.h"

bool isExternWall(int i);

bool isAllSame(std::array <int, MAZE_SIZE<int>> maze);

void mazeUpdate(SDL_Renderer* pRenderer, std::array<int, MAZE_SIZE<int>> maze, std::array<SDL_Rect, MAZE_SIZE<int>> squares);

void mazeCrea(SDL_Renderer* pRenderer);

#endif // __MAZE_CREA_H__