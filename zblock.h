#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include <vector>
#include "block.h"

class Zblock : public Block {
public:
    int dir;
public:
    Zblock(int heaviness = 0, bool candown = true, int dir = 1, Board* the_board = nullptr);
    ~Zblock();
    void clockwiseturn();
    void counterturn();
};


#endif

