#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include <vector>
#include "block.h"
#include "board.h"

class Iblock: public Block {
public:
    int dir;
public:
    Iblock(int heaviness = 0, bool candown = true, int dir = 1, Board* the_board = nullptr);
    ~Iblock() override;
    void clockwiseturn();
    void counterturn();
    void moveleft();
    void moveright();
    void movedown();
    void drop();
};

#endif