#ifndef CTable_H_
#define CTable_H_

#include <stdlib.h>
#include <vector>
#include "CDominoes.h"
#include "CPlayer.h"
#include "CRandom.h"

class CTable {
private:
    int head = 0;
    int tail = 0;
    std::vector<CDominoes> playedDominoes;
    CRandom * bag;
public:
    CPlayer * player1;
    CPlayer * player2;
    void playDomino(CDominoes toPlay, bool isHead);
    CTable();
    ~CTable();
    void printBoard();
    int getWinner();
    bool takeTurn(int* playerTurn);
    bool noPlays(CPlayer* turnTaker);
};

#endif //_CTable_
