#include "maze.h"
#include "moveStack.h"
#include <iostream>
using namespace std;

bool solver(MoveStack* moves, MazeCell* current, MazeCell* end, Maze* board)   {
    MazeCell* temp;

    cout << "Current " << current->getValue() << endl;
    temp = current->getTop();
    cout << "value" << temp << "space"  << endl;
    
    if (current == end) {
        return true;
    }
    
    moves->push(current);
    /**
    while(current->checked != 4)    {
        cout << "current " << current->checked << endl;
        
        switch (current->checked)
        {
            
            case 0:
                
                if ((current->up->val != '*') && (current->up->checked != 4))    {
                    cout << "case 0" << endl;
                    current->checked++;
                    
                    if (solver(moves, current->up, end, board))    {
                        current->val = 1;
                        
                        return true;
                    }
                    else    {
                        moves->peek()->val = '\0';
                        moves->pop();
                        break;
                    }
                }
                
            case 1:
                if (current->left->val != '*' && current->left->checked != 4)    {
                    current->checked++;
                    if (solver(moves, current->left, end, board))    {
                        return true;
                    }
                    else    {
                        moves->peek()->val = '\0';
                        moves->pop();
                        break;
                    }
                }
            case 2:
                if (current->down->val != '*' && current->down->checked != 4)    {
                    current->checked++;
                    if (solver(moves, current->down, end, board))    {
                        return true;
                    }
                    else    {
                        moves->peek()->val = '\0';
                        moves->pop();
                        break;
                    }
                }
            case 3:
                if (current->right->val != '*' && current->right->checked != 4)    {
                    current->checked++;
                    if (solver(moves, current->right, end, board))    {
                        return true;
                    }
                    else    {
                        moves->peek()->val = '\0';
                        moves->pop();
                        break;
                    }
                }
            default:
                break;
        }

    }
    **/
    return false;
}

void solveMaze(Maze* board)    { //takes starting location as args
    MoveStack* moves = new MoveStack;
    MazeCell* start = board->getDLoc();
    MazeCell* end = board->getGloc();

    cout << "start up val " << start->getTop() << endl;
    
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
