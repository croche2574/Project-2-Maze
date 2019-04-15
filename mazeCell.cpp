#include "mazeCell.h"
using namespace std;

MazeCell::MazeCell(uint16_t xLoc, uint16_t yLoc, uint16_t value) : value(value), x(xLoc), y(yLoc) {
    top=NULL;
    right=NULL;
    bottom=NULL;
    left=NULL;
}
    
uint16_t MazeCell::getValue() const {
    return value;
}
void MazeCell::setValue(uint16_t value) {
    MazeCell::value = value;
}

uint16_t MazeCell::getX() const {
    return x;
}
void MazeCell::setX(uint16_t x) {
    MazeCell::x = x;
}

uint16_t MazeCell::getY() const {
    return y;
}
void MazeCell::setY(uint16_t y) {
    MazeCell::y = y;
}

uint16_t MazeCell::getSidesChecked() const {
    return sidesChecked;
}
void MazeCell::setSidesChecked(uint16_t s) {
    MazeCell::sidesChecked = s;
}

MazeCell *MazeCell::getTop() const {
    return top;
}
void MazeCell::setTop(MazeCell *top) {
    MazeCell::top = top;
}

MazeCell *MazeCell::getRight() const {
    return right;
}
void MazeCell::setRight(MazeCell *right) {
    MazeCell::right = right;
}

MazeCell *MazeCell::getBottom() const {
    return bottom;
}
void MazeCell::setBottom(MazeCell *bottom) {
    MazeCell::bottom = bottom;
}

MazeCell *MazeCell::getLeft() const {
    return left;
}
void MazeCell::setLeft(MazeCell *left) {
    MazeCell::left = left;
}