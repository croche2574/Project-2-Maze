#include "maze.h"
#include <iostream>
using namespace std;


int main()  {
    uint16_t sideDim, percentFree;

    printf("Enter the length of one side: ");
    cin >> sideDim;
    printf("Enter the percentage of free cells: ");
    cin >>  percentFree;
    
    Maze mazeBoard = Maze(sideDim, percentFree);
    
    mazeBoard.makeBoard();

    mazeBoard.genMaze();
    printf("maze made");
    mazeBoard.printBoard();
    
}
