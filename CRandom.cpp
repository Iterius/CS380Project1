#include <stdlib.h>
#include <vector>
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
    srand(time(0));
    int pickedPiece = rand() % Dominoes.size();
    CDominoes toReturn = Dominoes[pickedPiece];
    std::vector<CDominoes>::iterator position = Dominoes.begin();
    position += pickedPiece;
    Dominoes.erase(position);
    return toReturn;
}
bool CRandom::isEmpty() {
    return Dominoes.size() == 0;
}
