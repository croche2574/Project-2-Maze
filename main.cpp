#include "maze.h"
#include "moveStack.h"
#include <iostream>
using namespace std;

bool solver(MoveStack* moves, MazeCell* current, MazeCell* end, Maze* board)   {
    if (current == end) {
        return true;
        cout << "found";
    }
    else if ((current == NULL) || (current->getValue() == 1)  || (current->getSidesChecked() == 4))  {
        return false;
    }
    
    moves->push(current);
    cout << "Cell Value: " << moves->peek()->getValue() << endl;
    cout << "sides3 : " << moves->peek()->getSidesChecked() << endl;
    while(moves->peek()->getSidesChecked() <= 4)    {
        MazeCell* top = moves->peek(); //creates reference to top of move stack
        
        uint16_t s = top->getSidesChecked();
        cout << "sides: " << s << endl;
        if ((top->getValue() != 3) || (top->getValue() != 3))  {
            top->setValue(5);
            board->printBoard();
        }

        
        switch (s)
        {
            
            case 0:               
                if ((top->getTop() != NULL) && (top->getTop()->getValue() != 5))   {
                    cout << "case 0" << endl;
                    cout << "Current top: " << top->getTop()->getValue() << endl;
                    
                    if (solver(moves, top->getTop(), end, board))   {
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
                cout  << "case 1" <<  endl;
                if ((top->getLeft() != NULL) && (top->getLeft()->getValue() != 5))    {
                    cout << "case 1" << endl;
                    cout << "Current left val: " << top->getLeft()->getValue() << endl;
                    cout << "left address " << top->getLeft() << endl;
                    cout << "side count 1: " << top->getSidesChecked();
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
                    cout << "sides1: " << top->getSidesChecked() << endl;
                    break;
                }
                break;
            case 2:

                if ((top->getBottom() != NULL) && (top->getBottom()->getValue() != 5))    {
                    cout << "case 2" << endl;
                    cout << "Current bottom: " << top->getBottom()->getValue() << endl;
                    
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
                    cout << "case 3" << endl;
                    cout << "Current right: " << top->getRight()->getValue() << endl;
                    
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
            case 4:
                /**
                if (top->getValue() == 3)    { //if all 4 directions at start have been checked
                    cout << "case 4" << endl;
                    return false;
                }
                **/
                if (top->getValue() == 4)  {
                    return true;
                }
                else    {
                    top->setValue(0);
                    moves->pop();
                    cout << "Popped" <<  endl;
                    board->printBoard();
                    break;
                }
            default:
                top->setValue(0);
                moves->pop();
                cout << "Popped" <<  endl;
                board->printBoard();
                break;
        }

    }
    cout << "Switch over" <<endl;
    return false;
}

void solveMaze(Maze* board)    { //takes starting location as args
    MoveStack* moves = new MoveStack;
    MazeCell* start = board->getLoc(board->getDX(), board->getDY());
    MazeCell* end = board->getLoc(board->getGX(), board->getGY());
    
    if (solver(moves, start, end, board) == false) {
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

    mazeBoard->genMaze();
    mazeBoard->printBoard();

    solveMaze(mazeBoard);
    
    
}
