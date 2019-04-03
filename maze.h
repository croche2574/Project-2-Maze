#ifndef MAZE
#define MAZE
#include  "mazeCell.h"
#include <iostream>
class Maze {
    private:
        uint8_t sideDimension;
        uint8_t percentFreeCells;
        MazeCell *head, *tail;
    public:
        Maze();
        Maze(uint8_t sideDimension, uint8_t percentFreeCells);

        void addCell(uint8_t xLoc, uint8_t yLoc, char value);
        MazeCell* changeLoc(MazeCell* cur);
        MazeCell* getLoc(uint8_t x, uint8_t y);
        void makeBoard();
        void genMaze();
        void printBoard();
        void setDaedalusCurrentLocation(uint8_t x, uint8_t y);
        void setGateLocation(uint8_t x, uint8_t y);
};

#endif