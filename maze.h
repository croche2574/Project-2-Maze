#ifndef MAZE
#define MAZE
#include  "mazeCell.h"
#include <iostream>
class Maze {
    private:
        uint16_t sideDimension;
        uint16_t percentFreeCells;
        uint16_t numCells;
        MazeCell *head, *tail;
    public:
        Maze();
        Maze(uint16_t sideDimension, uint16_t percentFreeCells);

        void addCell(uint16_t xLoc, uint16_t yLoc, char value);
        MazeCell* changeLoc(MazeCell* cur);
        MazeCell* getLoc(uint16_t x, uint16_t y);
        void makeBoard();
        void genMaze();
        void printBoard();
        void setDaedalusCurrentLocation(uint16_t x, uint16_t y);
        void setGateLocation(uint16_t x, uint16_t y);
};

#endif