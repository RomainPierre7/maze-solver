#ifndef CONST_HPP__
#define CONST_HPP__

template<typename T>
constexpr T SIDE_SIZE{ 81 }; //needs to be odd

template<typename T>
constexpr T MAZE_SIZE{ SIDE_SIZE<int> * SIDE_SIZE<int> };

template<typename T>
constexpr T WIDTHSCREEN{ SIDE_SIZE<int> * 15 };

template<typename T>
constexpr T HEIGHTSCREEN{ SIDE_SIZE<int> * 15 };

#define START SIDE_SIZE<int>
#define END MAZE_SIZE<int> - SIDE_SIZE<int> - 1

#define COMPLEX true

#endif // CONST_HPP__