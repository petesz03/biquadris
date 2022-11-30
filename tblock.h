#ifndef __TBLOCK_H__
#define __TBLOCK_H__

#include <vector.h>
#include "block.h"

class Tblock : public Block {
public:
    int dir;
public:
    Tblock(int, bool, int);
    ~Tblock();
    void clockwiseturn();
    void counterturn();
};


#endif
