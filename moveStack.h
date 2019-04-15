#ifndef MOVESTACK
#define MOVESTACK
#include "maze.h"
struct MoveNode {
    MazeCell *data;
    struct MoveNode *link;
};

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