#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include <vector>
#include "block.h"
#include "board.h"

class Lblock: public Block {
public:
    int dir;
public:
    Lblock(int heaviness = 0, bool candown = true, int dir = 1, Board* the_board = nullptr);
    ~Lblock();
    void clockwiseturn();
    void counterturn();
};




#endif

