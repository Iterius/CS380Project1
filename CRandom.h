#ifndef _CRandom_
#define _CRandom_
#include "CDominoes.h"
using namespace std;

class CRandom {
    private:
    default_random_engine generation;
    public:
    vector<CDominoes> Dominoes;
    CRandom();
    ~CRandom();
    CDominoes getRand();
    bool isEmpty();
};


#endif //_CRandom_
