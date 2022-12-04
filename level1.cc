#include "level1.h"
#include "sblock.h"
#include "zblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "tblock.h"
#include <cstdlib>
#include "board.h"

Level1::Level1(): Level(1) {}

Level1::~Level1() {}

Block* Level1::randomNextBlock(Board* subject) {
    // set the given seed value
	srand((unsigned) time(NULL));
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 12 + 1)
    {
    case 1:
        return new Sblock(subject);
        break;
    case 2:
        return new Zblock(subject);
        break;
    case 3: case 4:
        return new Iblock(subject);
        break;
    case 5: case 6:
        return new Jblock(subject);
        break;
    case 7: case 8:
        return new Lblock(subject);
        break;
    case 9: case 10:
        return new Oblock(subject);
        break;
    case 11: case 12:
        return new Tblock(subject);
        break;
    default:
        return new Iblock(subject);
    }
}

Block* Level1::fileNextBlock(Board* subject) {
    // set the given seed value
	srand((unsigned) time(NULL));
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 12 + 1)
    {
    case 1:
        return new Sblock(subject);
        break;
    case 2:
        return new Zblock(subject);
        break;
    case 3: case 4:
        return new Iblock(subject);
        break;
    case 5: case 6:
        return new Jblock(subject);
        break;
    case 7: case 8:
        return new Lblock(subject);
        break;
    case 9: case 10:
        return new Oblock(subject);
        break;
    case 11: case 12:
        return new Tblock(subject);
        break;
    default:
        return new Iblock(subject);
    }
}

void Level1::useFile(std::string file) {}

