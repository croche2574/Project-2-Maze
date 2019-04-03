#include "maze.h"
using namespace std;


int main()  {
    uint8_t sideDim, percentFree;

    printf("Enter the length of one side: ");
    cin >> sideDim;
    printf("Enter the percentage of free cells: ");
    cin >> percentFree;
    
    Maze* mazeBoard = new Maze(sideDim, percentFree);
}
