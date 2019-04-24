#include <cstdlib>
#include <stdio.h>
#include "CDominoes.h"
CDominoes::CDominoes() {
    leftSide = 0;
    rightSide = 0;
}
CDominoes::CDominoes(int leftSide, int rightSide) {
    this->leftSide = leftSide;
    this->rightSide = rightSide;
}
bool CDominoes::contains(int validPlay) {
    return leftSide == validPlay || rightSide == validPlay;
}
int CDominoes::getLeft() {
    return leftSide;
}
int CDominoes::getRight() {
    return rightSide;
}
void CDominoes::flip()
{
    int temp = leftSide;
    leftSide = rightSide;
    rightSide = temp;
}
void CDominoes::printDomino() {
    printf("[%i|%i]", leftSide, rightSide);
}
