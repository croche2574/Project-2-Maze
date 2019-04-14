#include "maze.h"
#include <iomanip>
#include <cstdlib>
using namespace std;

void Maze::addCell(uint16_t xLoc, uint16_t yLoc, char v)    {
    MazeCell *temp = new MazeCell(xLoc, yLoc, v);
    MazeCell *cur = head;

    if (head==NULL) { //No cells
        temp->setX(1);
        temp->setY(1);
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else //add cell
    {
        
        if (tail->getX() == sideDimension)   {
            while (cur->getTop() != NULL)    {
                cur = cur->getTop();
            }
            cur->setTop(temp);
            temp->setBottom(cur);
            tail = temp;
            temp = NULL;
        }
        else
        {
            temp->setLeft(tail);
            tail->setRight(temp);
            if (tail->getY() !=  1)  {                
                cur = getLoc(temp->getX(), (temp->getY() - 1));
                temp->setBottom(cur);
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
        cur = cur->getTop();
        
    }
    for (int i = 1; i < x; i++) {
        cur = cur->getRight();
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

            if (cell->getValue() == 0)   {
                cell->setValue(1);
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
            
            x++;
            if (cursor->getValue() == 1) {
                cout << "*";
                wallsPerRow++;
            }
            else if (cursor->getValue() == 3)   {
                cout << "D";
            }
            else if (cursor->getValue() == 4)   {
                cout << "#";
            }
            else   {
                cout << " ";
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
    cur->setValue(3);
    cout << "Setting deadalus " << cur << " d up " << cur->getTop() << endl;
    deadalus = cur;
}

void Maze::setGateLocation(uint16_t x, uint16_t y)    {
    MazeCell *cur = getLoc(x, y);
    cur->setValue(4);
    gate = cur;
}

MazeCell* Maze::getDLoc()   {
    return deadalus;
}

MazeCell* Maze::getGloc()   {
    return gate;
}

Maze::Maze()    {}

Maze::Maze(uint16_t side, uint16_t percentFree)   {
    sideDimension = side;
    percentFreeCells =  percentFree;
    head = NULL;
    tail = NULL;
}