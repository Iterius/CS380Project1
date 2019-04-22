#include <stdlib.h>
#include <vector>
#include "CDominoes.hpp"



class CPlayer {
    private:
    std::vector<CDominoes> Hand;
    public:
    CPlayer() {}
    ~CPlayer() {
        delete[] &Hand;
    }
    void addDomino(CDominoes toAdd) {
        Hand.push_back(toAdd);
    }
    void removeDomino(int toRemove) {
        std::vector<CDominoes>::iterator position = Hand.begin();
        position += toRemove;
        Hand.erase(position);
    }
    std::vector<CDominoes> getHand() {
        return Hand;
    }
    bool contains(int validPlay) {
        for(int i = 0; i < Hand.size(); i++) {
            if(Hand[i].contains(validPlay)) {
                return true;
            }
        }
        return false;
    }
    void printHand() {
        for(int i = 0; i < Hand.size(); i++) {
            Hand[i].printDomino();
        }
        printf("\n");
    }
    bool isEmpty() {
        return Hand.size() == 0;
    }
}