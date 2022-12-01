#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include <vector>
#include "block.h"

class Jblock : public Block {
public:
    int dir;
public:
    Jblock(int, bool, int);
    ~Jblock();
    void clockwiseturn();
    void counterturn();
};





#endif
