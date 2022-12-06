#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include <vector>
#include "block.h"
#include "board.h"

class Iblock: public Block {
public:
    int dir;
public:
    Iblock(std::shared_ptr<Board> the_board = nullptr, int heaviness = 0, bool candown = true, int dir = 1);
    ~Iblock() override;
    void clockwiseturn();
    void counterturn();
};

#endif