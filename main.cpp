#include "maze.h"
#include "moveStack.h"
#include <iostream>
using namespace std;

void solve(uint16_t x, uint16_t y)    { //takes starting location as args

}


int main()  {
    uint16_t sideDim, percentFree, dx, dy, gx, gy;

    printf("Enter the length of one side: ");
    cin >> sideDim;
    printf("Enter the percentage of free cells: ");
    cin >>  percentFree;
    
    Maze mazeBoard = Maze(sideDim, percentFree);
    
    mazeBoard.makeBoard();
    printf("Enter the Deadalus x-coord: ");
    cin >> dx;
    printf("Enter the Deadalus y-coord: ");
    cin >>  dy;
    mazeBoard.setDaedalusCurrentLocation(x, y);

    printf("Enter the Exit x-coord: ");
    cin >> gx;
    printf("Enter the Exit y-coord: ");
    cin >>  gy;
    mazeBoard.setGateLocation(x, y);

    solve(dx, dy);

    mazeBoard.genMaze();
    mazeBoard.printBoard();
    
}
