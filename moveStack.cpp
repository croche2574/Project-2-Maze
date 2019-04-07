#include "moveStack.h"
using namespace std;

void MoveStack::push(MazeCell* data) {
    StackNode *temp = new StackNode;
    StackNode *cur = top;

    temp->data = data;
    temp->link = cur;
    cur = temp;
    temp = NULL;
}

void MoveStack::pop()   {
    StackNode *temp;

    if (top == NULL)  {
        cout << "\nEmpty Stack" << endl;
    }
    else {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }

}

MazeCell* MoveStack::peek() {
    if (top != NULL) {
        return top->data;
    }
    return 0;
}

void MoveStack::display()   {

}

MoveStack::MoveStack()  {}