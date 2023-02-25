#ifndef CONST_H
#define CONST_H

template<typename T>
constexpr T WIDTHSCREEN{ 1200 };

template<typename T>
constexpr T HEIGHTSCREEN{ 1200 };

template<typename T>
constexpr T SIDE_SIZE{ 41 }; //needs to be odd

template<typename T>
constexpr T MAZE_SIZE{ SIDE_SIZE<int> * SIDE_SIZE<int> };

#endif