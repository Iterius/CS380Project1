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
void CDominoes::setLeft(int leftNum) {
    leftSide = leftNum;
}
void CDominoes::setRight(int rightNum) {
    rightSide = rightNum;
}
void CDominoes::printDomino() {
    printf("[%i|%i]", leftSide, rightSide);
}
