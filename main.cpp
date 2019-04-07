#include "maze.h"
#include "moveStack.h"
#include <iostream>
using namespace std;

void solve()    {
    
}


int main()  {
    uint16_t sideDim, percentFree, x, y;

    printf("Enter the length of one side: ");
    cin >> sideDim;
    printf("Enter the percentage of free cells: ");
    cin >>  percentFree;
    
    Maze mazeBoard = Maze(sideDim, percentFree);
    
    mazeBoard.makeBoard();
    printf("Enter the Deadalus x-coord: ");
    cin >> x;
    printf("Enter the Deadalus y-coord: ");
    cin >>  y;
    mazeBoard.setDaedalusCurrentLocation(x, y);

    printf("Enter the Exit x-coord: ");
    cin >> x;
    printf("Enter the Exit y-coord: ");
    cin >>  y;
    mazeBoard.setGateLocation(x, y);

    mazeBoard.genMaze();
    mazeBoard.printBoard();
    
}
