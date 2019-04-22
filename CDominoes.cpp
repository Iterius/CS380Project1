#include <cstdlib>
#include <stdio.h>

class CDominoes {
    private:
        int leftSide;
        int rightSide;
    public:
    CDominoes() {
        leftSide = 0;
        rightSide = 0;
    }
    CDominoes(int leftSide, int rightSide) {
        this->leftSide = leftSide;
        this->rightSide = rightSide;
    }
    bool contains(int validPlay) {
        return leftSide == validPlay || rightSide == validPlay;
    }
    int getLeft() {
        return leftSide;
    }
    int getRight() {
        return rightSide;
    }
    void printDomino() {
        printf("[%i|%i]", leftSide, rightSide);
    }
}