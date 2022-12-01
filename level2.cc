#include "level2.h"

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
        return new SBlock();
        break;
    case 2:
        return new ZBlock();
        break;
    case 3:
        return new IBlock;
        break;
    case 4:
        return new JBlock();
        break;
    case 5:
        return new LBlock();
        break;
    case 6:
        return new OBlock();
        break;
    case 7:
        return new TBlock();
        break;
    default:
        return new IBlock();
    }
}

