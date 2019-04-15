#include "maze.h"
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

uint16_t Maze::getDX() const {
    return dX;
}
void Maze::setDX(uint16_t x) {
    Maze::dX = x;
}

uint16_t Maze::getDY() const {
    return dY;
}
void Maze::setDY(uint16_t y) {
    Maze::dY = y;
}

uint16_t Maze::getGX() const {
    return gX;
}
void Maze::setGX(uint16_t x) {
    Maze::gX = x;
}

uint16_t Maze::getGY() const {
    return gY;
}
void Maze::setGY(uint16_t y) {
    Maze::gY = y;
}

uint16_t Maze::getNumCells() const {
    return numCells;
}
void Maze::setNumCells(uint16_t n) {
    Maze::numCells = n;
}

MazeCell* Maze::getLoc(uint16_t x, uint16_t y) const   {
    MazeCell *cur = head;
    
    for (int i = 1; i < y; i++) { //moves y rows up
        cur = cur->getTop();
        
    }
    for (int i = 1; i < x; i++) { //moves x columns over
        cur = cur->getRight();
    }

    return cur;
}

void Maze::addCell(uint16_t xLoc, uint16_t yLoc, char v)    { //Adds cells to the board from the tail.
    MazeCell *temp = new MazeCell(xLoc, yLoc, v);
    MazeCell *cur = head;

    if (head==NULL) { //No cells in maze
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
                cur->setTop(temp);
                temp->setBottom(cur);
                cur = temp;
            }
            tail = temp;
            temp = NULL;
        }
    }
}

void Maze::makeBoard()  { //calls the function to add cells
    uint16_t x = 1;
    uint16_t y = 1;
    setNumCells(sideDimension * sideDimension);
    
    for (int i = 0; i < getNumCells(); i++)   {
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

void Maze::genMaze()    { //Fills in the maze
    uint16_t numWalls = (getNumCells() * (100 - percentFreeCells)) / 100; //Calculate how many walls there should be
    uint16_t randX, randY;
    srand(time(NULL)); //generates a random seed
    MazeCell* cell; // creates empty reference to a cell
    bool containsX = false;
   

    for (int i = 0; i < numWalls; i++)  {
        
        do {
            
            randX = rand() % sideDimension + 1;
            randY = rand() % sideDimension + 1;
            //cout << "randX: " << randX << endl;
            //cout << "randY: " << randY << endl;
            cell = getLoc(randX, randY); //gets the cell at the random location

            if (cell->getValue() == 0)   { //checks if the cell is empty
                cell->setValue(1);
                containsX = true;
            }
        } 
        while(!containsX); //Loops and picks another spot if the chosen spot is occupied
    }
}

void Maze::printBoard() { //prints the maze board
    uint16_t x = 1, y = 1;
    uint16_t wallsPerRow = 0; //stores how many walls are in each row
    MazeCell *cursor; //cell reference to move through board
    cout << setfill(' ') << setw(4) << "+" << setfill('-') << setw(sideDimension + 1) << "+" << endl;
    for (int i = 0; i < getNumCells(); i++)   {
        cursor = getLoc(x, y);
        
        if (x == 1) {
            cout << setfill(' ') << setw(2) << y << " |";
        }
        if (x <= sideDimension) { //translates numbers in cells to symbols
            
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
            else if (cursor->getValue() == 5)   {
                cout << "@";
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
    setDX(x);
    setDY(y);
    
    MazeCell *cur = getLoc(x, y);
    cur->setValue(3);
}

void Maze::setGateLocation(uint16_t x, uint16_t y)    {
    setGX(x);
    setGY(y);

    MazeCell *cur = getLoc(x, y);
    cur->setValue(4);
}

Maze::Maze(uint16_t side, uint16_t percentFree) : sideDimension(side), percentFreeCells(percentFree)  { 
    head = NULL;
    tail = NULL;
}