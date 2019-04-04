#include "maze.h"
#include <iomanip>
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
    
    for (int i = 1; i < y; i++) {
        cur = cur->up;
        
    }
    for (int i = 1; i < x; i++) {
        cur = cur->right;
    }

    return cur;
}

void Maze::makeBoard()  {
    uint16_t x = 1;
    uint16_t y = 1;
    numCells = (sideDimension * sideDimension);
    
    for (int i = 0; i < numCells; i++)   {
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
    uint16_t numWalls = (numCells * percentFreeCells) / 100;
    uint16_t randX, randY;
    MazeCell* cell;
    bool containsX = false;
   

    for (int i = 0; i < numWalls; i++)  {
        
        do {
            
            randX = rand() % sideDimension + 1;
            randY = rand() % sideDimension + 1;
            //cout << "randX: " << randX << endl;
            //cout << "randY: " << randY << endl;
            cell = getLoc(randX, randY);

            if (cell->val == '\0')   {
                cell->val = '*';
                containsX = true;
            }
        } 
        while(!containsX);
    }
}

void Maze::printBoard() {
    uint16_t x = 1, y = 1;
    uint16_t wallsPerRow = 0;
    MazeCell *cursor;
    cout << setw(4) << "+" << setfill('-') << setw(sideDimension) << "+" << endl;
    for (int i = 0; i < numCells; i++)   {
        cursor = getLoc(x, y);
        
        if (x == 1) {
            cout << setfill(' ') << setw(2) << y << " |";
        }
        if (x < sideDimension) {
            cout << cursor->val;
            x++;
            if (cursor->val == '*') {
                wallsPerRow++;
            }
        }
        else{
            x = 1;
            y++;
            cout << "| " << wallsPerRow << endl;
            wallsPerRow = 0;
            if (y > sideDimension) {
                break;
            }
        }
    }
    cout << setw(4) << "+" << setfill('-') << setw(sideDimension) << "+" << endl;
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