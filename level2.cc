#include "level2.h"
#include "sblock.h"
#include "zblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "tblock.h"
#include <cstdlib>
#include "board.h"

Level2::Level2(): Level{2} {}

Level2::~Level2() {}

Block* Level2::randomNextBlock(Board* subject) {
    // set the given seed value
	srand((unsigned) time(NULL));
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 7 + 1)
    {
    case 1:
        return new Sblock(subject);
        break;
    case 2:
        return new Zblock(subject);
        break;
    case 3:
        return new Iblock(subject);
        break;
    case 4:
        return new Jblock(subject);
        break;
    case 5:
        return new Lblock(subject);
        break;
    case 6:
        return new Oblock(subject);
        break;
    case 7:
        return new Tblock(subject);
        break;
    default:
        return new Iblock(subject);
    }
}

Block* Level2::fileNextBlock(Board* subject) {
    // set the given seed value
	srand((unsigned) time(NULL));
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 7 + 1)
    {
    case 1:
        return new Sblock(subject);
        break;
    case 2:
        return new Zblock(subject);
        break;
    case 3:
        return new Iblock(subject);
        break;
    case 4:
        return new Jblock(subject);
        break;
    case 5:
        return new Lblock(subject);
        break;
    case 6:
        return new Oblock(subject);
        break;
    case 7:
        return new Tblock(subject);
        break;
    default:
        return new Iblock(subject);
    }
}

void Level2::useFile(std::string file) {}
