#include "moveStack.h"
using namespace std;

void MoveStack::push(MazeCell *move)   {
    struct MoveNode* newnode = new MoveNode; 
    newnode->data = move; 
    newnode->link = top; 
    top = newnode; 
}

MazeCell* MoveStack::peek()    {
    return top->data;
}

void MoveStack::pop()   {
    if(top==NULL)
        cout<<"Stack Underflow"<<endl;
    else {
        top = top->link;
   }
}

void MoveStack::display()   {
    struct MoveNode* ptr;
    if(top==NULL)
       cout<<"stack is empty";
    else {   
        ptr = top; 
        cout<<"Stack elements are: ";
        while (ptr != NULL) { 
            cout<< ptr->data <<" "; 
            ptr = ptr->link; 
        } 
    }
    cout<<endl;
}