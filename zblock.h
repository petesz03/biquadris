#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include <vector.h>
#include "block.h"

class Zblock : public Block {
public:
    int dir;
public:
    Zblock(int, bool, int);
    ~Zblock();
    void clockwiseturn();
    void counterturn();
};


#endif

