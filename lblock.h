#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include <vector>
#include "block.h"

class Lblock: public Block {
public:
    int dir;
public:
    Lblock(int, bool, int);
    ~Lblock();
    void clockwiseturn();
    void counterturn();
};




#endif

