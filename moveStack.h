#ifndef MOVESTACK
#define MOVESTACK
#include "maze.h"

class StackNode {
    public:
        MazeCell *data;
        StackNode *link;
};

class MoveStack {
    private:
        StackNode *top;
    public:
        void push(MazeCell* data);
        void pop();
        int isEmpty();
        MazeCell* peek();
        void display();

        MoveStack ();
};

#endif