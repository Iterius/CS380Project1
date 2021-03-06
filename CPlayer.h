#ifndef _CPlayer_
#define _CPlayer_

#include <stdlib.h>
#include <vector>
#include "CDominoes.h"

class CPlayer{
private:
    std::vector<CDominoes> Hand;

public:
    CPlayer();
    ~CPlayer();
    void addDomino(CDominoes);
    void removeDomino(int toRemove);
    std::vector<CDominoes> getHand();
    bool contains(int validPlay);
    void printHand();
    bool isEmpty();
};

#endif //_CPlayer_
