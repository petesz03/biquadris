#ifndef __SBLOCK_H__
#define __SBLOCK_H__

#include <vector>
#include "block.h"
#include "board.h"

class Sblock : public Block {
public:
    int dir;
public:
    Sblock(int heaviness = 0, bool candown = true, int dir = 1, Board* the_board = nullptr);
    ~Sblock();
    void clockwiseturn();
    void counterturn();
};


#endif

