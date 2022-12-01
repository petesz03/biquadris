#ifndef __SBLOCK_H__
#define __SBLOCK_H__

#include <vector>
#include "block.h"

class Sblock : public Block {
public:
    int dir;
public:
    Sblock(int, bool, int);
    ~Sblock();
    void clockwiseturn();
    void counterturn();
};


#endif

