#include "maze.h"
#include <cmath>
using namespace std;

void Maze::addCell(uint8_t xLoc, uint8_t yLoc, char v)    {
    MazeCell *temp = new MazeCell;
    MazeCell *cur = head;
    temp->val = v;
    temp->up = NULL;
    temp->down = NULL;
    temp->left = NULL;
    temp->right = NULL;

    if (head==NULL) { //No cells
        temp->x = 1;
        temp->y = 1;
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else //add cell
    {
        if (tail->x == sideDimension)   {
            while (cur->up != NULL)    {
                cur = cur->up;
            }

            cur->up = temp;
            temp->down = cur;
            tail = temp;
            temp = NULL;
        }
        else
        {
            temp->left = tail;
            tail->right =  temp;

            if (tail->y !=  1)  {
                
                temp->down = getLoc(temp->x, (temp->y - 1));
                getLoc(temp->x, (temp->y - 1))->up = temp;
            }
            tail = temp;
            temp = NULL;
        

        }
        

    }
}

MazeCell* Maze::getLoc(uint8_t x, uint8_t y)    {
    MazeCell *cur = head;

    for (int i = 0; i < y; i++) {
        cur = cur->up;
    }

    for (int i = 0; i < x; i++) {
        cur = cur->right;
    }
    return cur;
}

void Maze::makeBoard()  {
    uint8_t x = 1;
    uint8_t y = 1;
    for (int i = 0; i < pow(sideDimension, 2); i++)   {
        addCell(x, y, '\0');
        if (x < sideDimension) {
            x++;
        }
        else{
            x = 1;
            y++;
            if (y > sideDimension) {
                break;
            }
        }
        
    }
}

void Maze::genMaze()    {
    uint8_t numWalls = (pow(sideDimension, 2) * percentFreeCells) / 100;
    uint8_t randX, randY;
    bool containsX = false;
    for (int i = 0; i < numWalls; i++)  {
        do {

        } while(containsX);        
    }
}

void Maze::printBoard() {
    printf("");
}

void Maze::setDaedalusCurrentLocation(uint8_t x, uint8_t y) {
    MazeCell *cur = getLoc(x, y);
    cur->val = 'D';
}

void Maze::setGateLocation(uint8_t x, uint8_t y)    {
    MazeCell *cur = getLoc(x, y);
    cur->val = '#';
}

Maze::Maze()    {}

Maze::Maze(uint8_t side, uint8_t percentFree)   {
    sideDimension = side;
    percentFreeCells =  percentFree;
    head = NULL;
    tail = NULL;
}