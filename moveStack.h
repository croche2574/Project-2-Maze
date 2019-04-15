#ifndef MOVESTACK
#define MOVESTACK
#include "maze.h"
//nodes in stack.
struct MoveNode {
    MazeCell *data;
    struct MoveNode *link;
};
// Linked list stack for storing moves
class  MoveStack {
    private:
        struct MoveNode *top;
    public:
        void push(MazeCell *data);
        MazeCell* peek();
        void pop();
        void display();
};

#endif