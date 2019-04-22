#include <stdlib.h>
#include <vector>
#include "CDominoes.hpp"
#include "CPlayer.hpp"
#include "CRandom.hpp"

#ifndef _CTable_
#define _CTable_

class CTable {
    public:
    CPlayer * player1;
    CPlayer * player2;
    void playDomino(CDominoes toPlay, bool isHead);
    CTable();
    void printBoard();
    int getWinner();
    bool takeTurn(int * playerTurn);
};

#endif //_CTable_