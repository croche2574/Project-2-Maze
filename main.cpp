#include "maze.h"
#include "moveStack.h"
#include <iostream>
using namespace std;

bool solver(MoveStack* moves, MazeCell* current, MazeCell* end, Maze* board)   { //solves maze
    if (current == end) { //checks if exit has been reached
        return true;
    }
    else if ((current == NULL) || (current->getValue() == 1)  || (current->getSidesChecked() == 4))  { //checks if cell is not valid path
        return false;
    }
    
    moves->push(current); //pushes cell onto stack
    
    while(moves->peek()->getSidesChecked() <= 4)    { //checks if cell has been checked in all directions
        MazeCell* top = moves->peek(); //creates reference to top of move stack
        
        uint16_t s = top->getSidesChecked();
        if ((top->getValue() != 3) && (top->getValue() != 5))  { //changes value of cell to indicate that it's part of the solution if it hasn't been verified yet
            top->setValue(5);
            board->printBoard();
        }

        
        switch (s) //Handles checking the sides
        {
            
            case 0:               
                if ((top->getTop() != NULL) && (top->getTop()->getValue() != 5))   {                    
                    if (solver(moves, top->getTop(), end, board))   { //recursively calls solver with next cell
                        return true;
                    }
                    else    {
                        s++;
                        top->setSidesChecked(s);
                    }
                    
                }
                else   {
                    s++;
                    top->setSidesChecked(s);
                    break;
                }
                break;
            case 1:
                if ((top->getLeft() != NULL) && (top->getLeft()->getValue() != 5))    {
                    if (solver(moves, top->getLeft(), end, board))   {
                        return true;
                    }
                    else    {
                        s++;
                        top->setSidesChecked(s);
                    }
                    
                }
                else   {
                    s++;
                    top->setSidesChecked(s);
                    break;
                }
                break;
            case 2:

                if ((top->getBottom() != NULL) && (top->getBottom()->getValue() != 5))    {                    
                    if (solver(moves, top->getBottom(), end, board))   {
                        return true;
                    }
                    else    {
                        s++;
                        top->setSidesChecked(s);
                    }
                    
                }
                else   {
                    s++;
                    top->setSidesChecked(s);
                    break;
                }
                break;
            case 3:              
                if ((top->getRight() != NULL) && (top->getRight()->getValue() != 5))   {                    
                    if (solver(moves, top->getRight(), end, board))   {
                        return true;
                    }
                    else    {
                        s++;
                        top->setSidesChecked(s);
                    }
                    
                }
                else   {
                    s++;
                    top->setSidesChecked(s);
                    break;
                }
                break;
            case 4: //Handles the cell after checks are complete
                if (top->getValue() == 4)  { //returns true if goal is reached
                    return true;
                }
                else    {
                    if ((top->getValue() != 3) && (top->getValue() != 4))   { //Backtracks
                        top->setValue(0);
                    }
                    moves->pop();
                    cout << "Backtrack" <<  endl;
                    board->printBoard();
                    if (moves->peek()->getValue() == 3) { //checks if at start
                        return false;
                    }
                    break;
                }
            default:
                if ((top->getValue() != 3) && (top->getValue() != 4))  {
                    top->setValue(0);
                }
                moves->pop();
                cout << "Backtrack" <<  endl;
                board->printBoard();
                break;
        }

    }
    return false;
}

void solveMaze(Maze* board)    { //takes starting location as args
    MoveStack* moves = new MoveStack; // pointer to a stack for storing moves
    MazeCell* start = board->getLoc(board->getDX(), board->getDY()); //start of the maze
    MazeCell* end = board->getLoc(board->getGX(), board->getGY()); //end of the maze
    
    if (solver(moves, start, end, board) == false) { //checks if solution exists
        cout <<  "Maze has no solution." << endl;
    }
    else    {
        cout << "Maze has a solution"  << endl;
    }
}

int main()  {
    uint16_t sideDim, percentFree, dx, dy, gx, gy;

    printf("Enter the length of one side: ");
    cin >> sideDim;
    printf("Enter the percentage of free cells: ");
    cin >>  percentFree;
    
    Maze* mazeBoard = new Maze(sideDim, percentFree);
    
    mazeBoard->makeBoard();
    printf("Enter the Deadalus x-coord: ");
    cin >> dx;
    printf("Enter the Deadalus y-coord: ");
    cin >>  dy;
    mazeBoard->setDaedalusCurrentLocation(dx, dy);

    printf("Enter the Exit x-coord: ");
    cin >> gx;
    printf("Enter the Exit y-coord: ");
    cin >>  gy;
    mazeBoard->setGateLocation(gx, gy);

    mazeBoard->genMaze(); //creates maze
    mazeBoard->printBoard();

    solveMaze(mazeBoard); //solves maze
    
    uint16_t c; //Pauses program to view results if not run in console
    puts ("Enter \"e\" and press return to exit:"); 
    do {
        c=getchar();
    } while (c != 'e');
    return 0;
    
}
