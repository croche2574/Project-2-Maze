#ifndef MAZE
#define MAZE
#include "mazeCell.h"
#include <iostream>
class Maze { //Class for the linked list
    private:
        uint16_t sideDimension;
        uint16_t percentFreeCells;
        uint16_t numCells;
        uint16_t dX;
        uint16_t dY;
        uint16_t gX;
        uint16_t gY;
        MazeCell *head, *tail; //head and tail nodes of the list
    public:
        Maze();
        Maze(uint16_t sideDimension, uint16_t percentFreeCells);

        void addCell(uint16_t xLoc, uint16_t yLoc, char value);

        uint16_t getDX() const;
        void setDX(uint16_t x);

        uint16_t getDY() const;
        void setDY(uint16_t y);

        uint16_t getGX() const;
        void setGX(uint16_t x);

        uint16_t getGY() const;
        void setGY(uint16_t y);

        uint16_t getNumCells() const;
        void setNumCells(uint16_t n);

        MazeCell* changeLoc(MazeCell* cur); //return a different cell
        MazeCell* getLoc(uint16_t x, uint16_t y) const; //get a cell based on x and y
        void makeBoard(); //Create the list
        void genMaze(); //Fill the list with obstacles
        void printBoard(); //Print the board
        void setDaedalusCurrentLocation(uint16_t x, uint16_t y);
        void setGateLocation(uint16_t x, uint16_t y);
};

#endif