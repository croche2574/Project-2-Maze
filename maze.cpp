#include "maze.h"
#include <cmath>
#include <cstdlib>
using namespace std;

void Maze::addCell(uint16_t xLoc, uint16_t yLoc, char v)    {
    MazeCell *temp = new MazeCell;
    MazeCell *cur = head;
    temp->val = v;
    temp->x = xLoc;
    temp->y = yLoc;
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
                cur = getLoc(temp->x, (temp->y - 1));
                temp->down = cur;
                cur = temp;                
            }
            tail = temp;
            temp = NULL;
        }
    }
}

MazeCell* Maze::getLoc(uint16_t x, uint16_t y)    {
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
    uint16_t x = 1;
    uint16_t y = 1;
    
    for (int i = 0; i < pow(sideDimension, 2); i++)   {
        addCell(x, y, '\0');
        cout << "X: " << x << "  Y: " << y << endl;
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
    numCells = pow(sideDimension, 2);
    uint16_t numWalls = (numCells * (100 - percentFreeCells)) / 100;
    uint16_t randX, randY;
    MazeCell* cell;
    bool containsX = false;

    for (int i = 0; i < numWalls; i++)  {
        do {
            randX = rand() % numCells + 1;
            randY = rand() % numCells + 1;
            cell = getLoc(randX, randY);
            if (cell->val != '*')   {
                cell->val = '*';
                containsX = true;
            }
        } 
        while(containsX);
    }
}

void Maze::printBoard() {
    MazeCell *upPoint, *rightPoint = head; 
    uint16_t rowNum = 1;
  
    // loop until the down pointer is not NULL 
    while (upPoint) { 
        rightPoint = upPoint; 
        cout << rowNum << " |";
  
        // loop until the right pointer is not NULL 
        while (rightPoint) { 
            cout << rightPoint->val; 
            rightPoint = rightPoint->right; 
        } 
        cout << "|" << endl; 
        upPoint = upPoint->up; 
        rowNum++;
    } 
}

void Maze::setDaedalusCurrentLocation(uint16_t x, uint16_t y) {
    MazeCell *cur = getLoc(x, y);
    cur->val = 'D';
}

void Maze::setGateLocation(uint16_t x, uint16_t y)    {
    MazeCell *cur = getLoc(x, y);
    cur->val = '#';
}

Maze::Maze()    {}

Maze::Maze(uint16_t side, uint16_t percentFree)   {
    sideDimension = side;
    percentFreeCells =  percentFree;
    head = NULL;
    tail = NULL;
}