#ifndef __MAZE_CREA_HPP__
#define __MAZE_CREA_HPP__

#include <SDL2/SDL.h>
#include <array>
#include <cstdlib>
#include "const.hpp"

#define START SIDE_SIZE<int>
#define END MAZE_SIZE<int> - SIDE_SIZE<int> - 1

#define UP(i) i - SIDE_SIZE<int>
#define DOWN(i) i + SIDE_SIZE<int>
#define LEFT(i) i - 1
#define RIGHT(i) i + 1

bool isWall(int i);

bool isExternWall(int i);

bool isAllSame(std::array <int, MAZE_SIZE<int>> maze);

void complexMaze(std::array<int, MAZE_SIZE<int>>& maze, std::array<SDL_Rect, MAZE_SIZE<int>>& squares);

void mazeUpdate(SDL_Renderer* pRenderer, std::array<int, MAZE_SIZE<int>> maze, std::array<SDL_Rect, MAZE_SIZE<int>> squares);

void mazeCrea(std::array<int, MAZE_SIZE<int>>& maze, std::array<SDL_Rect, MAZE_SIZE<int>>& squares);

#endif // __MAZE_CREA_HPP__