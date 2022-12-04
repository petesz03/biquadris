#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include <vector>
#include "block.h"
#include "board.h"

class Jblock : public Block {
public:
    int dir;
public:
    Jblock(Board* the_board = nullptr, int heaviness = 0, bool candown = true, int dir = 1);
    ~Jblock();
    void clockwiseturn();
    void counterturn();
};





#endif
