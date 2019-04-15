#ifndef MAZECELL
#define MAZECELL
#include <iostream>
//Node of Maze Linked list

class MazeCell  { //Maze cell object
    private:
        uint16_t value; //number stored
        uint16_t x; //x location
        uint16_t y; //y location
        uint16_t sidesChecked; //How many sides of the cell have been checked for solution
        MazeCell *top;
        MazeCell *right;
        MazeCell *bottom;
        MazeCell *left;
    public:
        MazeCell(uint16_t xLoc, uint16_t yLoc, uint16_t value);
        
        uint16_t getValue() const;
        void setValue(uint16_t value);

        uint16_t getX() const;
        void setX(uint16_t x);

        uint16_t getY() const;
        void setY(uint16_t y);

        uint16_t getSidesChecked() const;
        void setSidesChecked(uint16_t s);
        
        MazeCell *getTop() const;
        void setTop(MazeCell *top);
        
        MazeCell *getRight() const;
        void setRight(MazeCell *right);
        
        MazeCell *getBottom() const;
        void setBottom(MazeCell *bottom);
        
        MazeCell *getLeft() const;
        void setLeft(MazeCell *left);
};

#endif