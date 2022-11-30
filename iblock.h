#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include <vector.h>
#include "block.h"

class Iblock: public Block {
public:
    int dir;
public:
    Iblock(int, bool, int);
    ~Iblock() override;
    void clockwiseturn();
    void counterturn();
};

#endif