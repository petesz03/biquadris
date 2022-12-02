#include "level2.h"
#include "sblock.h"
#include "zblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "tblock.h"
#include <cstdlib>

Level2::Level2(): Level{2} {}

Level2::~Level2() {}

Block* Level2::nextBlock(Player* p) {
    // set the given seed value
	srand((unsigned) time(NULL));
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 7 + 1)
    {
    case 1:
        return new Sblock();
        break;
    case 2:
        return new Zblock();
        break;
    case 3:
        return new Iblock();
        break;
    case 4:
        return new Jblock();
        break;
    case 5:
        return new Lblock();
        break;
    case 6:
        return new Oblock();
        break;
    case 7:
        return new Tblock();
        break;
    default:
        return new Iblock();
    }
}

