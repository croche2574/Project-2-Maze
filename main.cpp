#include "maze.h"
#include "moveStack.h"
#include <iostream>
using namespace std;

bool solver(MoveStack* moves, MazeCell* current, MazeCell* end)   {
    
    
    return false;
}

void solveMaze(Maze* board)    { //takes starting location as args
    MoveStack* moves = new MoveStack;
    MazeCell* start = board->getDLoc();
    MazeCell* end = board->getGloc();
    
    if (solver(moves, start, end) == false) {
        cout <<  "Maze has no solution." << endl;
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
