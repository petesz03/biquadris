#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include <vector>
#include "block.h"
#include "board.h"

class Oblock : public Block {
public:
    int dir;
public:
    Oblock(Board* the_board = nullptr, int heaviness = 0, bool candown = true, int dir = 1);
    ~Oblock();
    void clockwiseturn();
    void counterturn();
};



#endif


