#ifndef MAZECELL
#define MAZECELL
#include <iostream>


class MazeCell  {
    public:
        char val;
        uint16_t x;
        uint16_t y;
        MazeCell *up;
        MazeCell *down;
        MazeCell *left;
        MazeCell *right; 
};

#endif