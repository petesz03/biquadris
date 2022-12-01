#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include <vector>
#include "block.h"

class Oblock : public Block {
public:
    int dir;
public:
    Oblock(int, bool, int);
    ~Oblock();
    void clockwiseturn();
    void counterturn();
};



#endif


