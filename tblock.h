#ifndef __TBLOCK_H__
#define __TBLOCK_H__

#include <vector>
#include "block.h"
#include "board.h"

class Tblock : public Block {
public:
    int dir;
public:
    Tblock(std::shared_ptr<Board> the_board = nullptr, int heaviness = 0, bool candown = true, int dir = 1);
    ~Tblock();
    void clockwiseturn();
    void counterturn();
};


#endif
