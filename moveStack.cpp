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

    if (isEmpty())  {
        cout << "\nEmpty Stack" << endl;
    }
    else {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }

}

int MoveStack::isEmpty()    {
    return top == NULL;
}

MazeCell* MoveStack::peek() {
    if (!isEmpty()) {
        return top->data;
    }
}

void MoveStack::display()   {

}

MoveStack::MoveStack()  {}