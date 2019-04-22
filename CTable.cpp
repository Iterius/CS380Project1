#include <stdlib.h>
#include <vector>
#include "CDominoes.hpp"
#include "CPlayer.hpp"
#include "CRandom.hpp"

class CTable {
    private:
    /**
     * @param head is the right side of the train.
     * @param tail is the left side of the train.
     */
    int head = 0;
    int tail = 0;
    std::vector<CDominoes> playedDominoes;
    CPlayer * player1;
    CPlayer * player2;
    CRandom * bag;
    public:
    void playDomino(CDominoes toPlay, bool isHead) {
        if(playedDominoes.size() == 0) {
            playedDominoes.push_back(toPlay);
        }
        else if(isHead) {
            playedDominoes.push_back(toPlay);
            head++;
        } 
        else {
            playedDominoes.insert(playedDominoes.begin(), toPlay);
            head++;
        }

    }
    CTable() {
        bag = new CRandom();
        player1 = new CPlayer();
        player2 = new CPlayer();
        playDomino(bag->getRand(), true);
        for(int i = 0; i < 10; i++) {
            player1->addDomino(bag->getRand());
            player2->addDomino(bag->getRand());
        }
    }
    void printBoard() {
        for(int i = 0; i < playedDominoes.size(); i++) {
            playedDominoes[i].printDomino();
        }
        printf("\n");
    }
}