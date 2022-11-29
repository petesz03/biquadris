#include "level1.cc"
#include <cstdlib>

Level1::Level1(): Level() {}

Level1::~Level1() {}

Block* Level1::nextBlock(Player* p) {
    // set the given seed value
	srand((unsigned) time(NULL));
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 12 + 1)
    {
    case 1:
        return new SBlock();
        break;
    case 2:
        return new ZBlock();
        break;
    case 3: case 4:
        return new IBlock;
        break;
    case 5: case 6:
        return new JBlock();
        break;
    case 7: case 8:
        return new LBlock();
        break;
    case 9: case 10:
        return new OBlock();
        break;
    case 11: case 12:
        return new TBlock();
        break;
    default:
        return new IBlock();
    }
}

