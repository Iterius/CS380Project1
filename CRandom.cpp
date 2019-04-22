#include <stdlib.h>
#include <vector>
#include <random>
#include <time.h>
#include <iterator>
#include "CDominoes.hpp"

class CRandom {
    private:
    std::default_random_engine generation;
    std::vector<CDominoes> Dominoes;
    public:
    CRandom(){
        for(int i = 0; i <= 6; i++) {
            for(int j = 0; j <= i; j++) {
                Dominoes.push_back(CDominoes(i, j));
            }
        }
    }
    ~CRandom() {
        delete[] &Dominoes;
    }
    CDominoes getRand() {
        std::uniform_int_distribution<int> distribution(0, (int)Dominoes.size()-1);
        int pickedPiece = distribution(generation);
        CDominoes toReturn = Dominoes[pickedPiece];
        std::vector<CDominoes>::iterator position = Dominoes.begin();
        position += pickedPiece;
        Dominoes.erase(position);
        return toReturn;
    }
    bool isEmpty() {
        return Dominoes.size() == 0;
    }
}