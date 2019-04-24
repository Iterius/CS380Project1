#ifndef _CRandom_
#define _CRandom_
#include "CDominoes.h"
#include <random>
using namespace std;

class CRandom {
    private:

    public:
    vector<CDominoes> Dominoes;
    CRandom();
    ~CRandom();
    CDominoes getRand();
    bool isEmpty();
};


#endif //_CRandom_
