#ifndef _CDominoes_
#define _CDominoes_

class CDominoes {
private:
    int leftSide;
    int rightSide;
public:
    CDominoes();
    CDominoes(int leftSide, int rightSide);
    bool contains(int validPlay);
    int getLeft();
    int getRight();
    void printDomino();
    void setLeft(int leftNum);
    void setRight(int rightNum);
};

#endif //_CDominoes_
