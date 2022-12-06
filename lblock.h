#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include <vector>
#include "block.h"
#include "board.h"

class Lblock: public Block {
public:
    int dir;
public:
    Lblock(std::shared_ptr<Board> the_board = nullptr, int heaviness = 0, bool candown = true, int dir = 1);
    ~Lblock();
    void clockwiseturn();
    void counterturn();
};




#endif

