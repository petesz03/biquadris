#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include <vector>
#include "block.h"
#include "board.h"

class Zblock : public Block {
public:
    int dir;
public:
    Zblock(Board* the_board = nullptr, int heaviness = 0, bool candown = true, int dir = 1);
    ~Zblock();
    void clockwiseturn();
    void counterturn();
};


#endif

