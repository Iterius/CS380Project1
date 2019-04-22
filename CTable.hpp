#include <stdlib.h>
#include <vector>
#include "CDominoes.hpp"
#include "CPlayer.hpp"
#include "CRandom.hpp"

#ifndef _CTable_
#define _CTable_

class CTable {
    public:
    void playDomino(CDominoes toPlay, bool isHead);
    CTable();
    void printBoard();
};

#endif //_CTable_