#ifndef MAZECELL
#define MAZECELL
#include <iostream>


class MazeCell  {
    public:
        char val;
        uint8_t x;
        uint8_t y;
        MazeCell *up;
        MazeCell *down;
        MazeCell *left;
        MazeCell *right; 
};

#endif