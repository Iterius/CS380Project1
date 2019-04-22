#ifndef _CRandom_
#define _CRandom_
#include "CDominoes.hpp"


class CRandom {
    public:
    CRandom();
    ~CRandom();
    CDominoes getRand();
    bool isEmpty();
};


#endif //_CRandom_