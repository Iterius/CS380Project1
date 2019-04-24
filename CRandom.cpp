#include <stdlib.h>
#include <vector>
#include <random>
#include <time.h>
#include <iterator>
#include "CDominoes.h"
#include "CRandom.h"

    CRandom::CRandom(){
        for(int i = 0; i <= 6; i++) {
            for(int j = 0; j <= i; j++) {
                Dominoes.push_back(CDominoes(i, j));
            }
        }
    }
    CRandom::~CRandom() {
        delete[] &Dominoes;
    }
    CDominoes CRandom::getRand() {
        std::uniform_int_distribution<int> distribution(0, (int)Dominoes.size()-1);
        int pickedPiece = distribution(generation);
        CDominoes toReturn = Dominoes[pickedPiece];
        std::vector<CDominoes>::iterator position = Dominoes.begin();
        position += pickedPiece;
        Dominoes.erase(position);
        return toReturn;
    }
    bool CRandom::isEmpty() {
        return Dominoes.size() == 0;
    }
};
