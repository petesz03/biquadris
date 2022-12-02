#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include <vector>
#include "block.h"

class Oblock : public Block {
public:
    int dir;
public:
    Oblock(int heaviness = 0, bool candown = true, int dir = 1);
    ~Oblock();
    void clockwiseturn();
    void counterturn();
};



#endif


