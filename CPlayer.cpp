#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "CDominoes.h"
#include "CPlayer.h"




CPlayer::CPlayer() {}
CPlayer::~CPlayer() {
    delete[] &Hand;
}
void CPlayer::addDomino(CDominoes toAdd) {
    Hand.push_back(toAdd);
}
void CPlayer::removeDomino(int toRemove) {
    std::vector<CDominoes>::iterator position = Hand.begin();
    position += toRemove;
    Hand.erase(position);
}
std::vector<CDominoes> CPlayer::getHand() {
    return Hand;
}
bool CPlayer::contains(int validPlay) {
    for(int i = 0; i < Hand.size(); i++) {
        if(Hand[i].contains(validPlay)) {
            return true;
        }
    }
    return false;
}
void CPlayer::printHand() {
    printf("Your hand: \n");
    for(int i = 0; i < Hand.size(); i++) {
        Hand[i].printDomino();
    }
    printf("\n");
    for(int i = 0; i < Hand.size(); i++)
    {
        printf("[ %i ]",i);
    }
    printf("\n");
}
bool CPlayer::isEmpty() {
    return Hand.size() == 0;
}
