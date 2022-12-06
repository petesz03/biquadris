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

std::shared_ptr<Block> Level1::randomNextBlock(std::shared_ptr<Board> subject) {
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 12 + 1)
    {
    case 1:
        return std::shared_ptr<Block>(new Sblock(subject.get()));
        break;
    case 2:
        return std::shared_ptr<Block>(new Zblock(subject.get()));
        break;
    case 3: case 4:
        return std::shared_ptr<Block>(new Iblock(subject.get()));
        break;
    case 5: case 6:
        return std::shared_ptr<Block>(new Jblock(subject.get()));
        break;
    case 7: case 8:
        return std::shared_ptr<Block>(new Lblock(subject.get()));
        break;
    case 9: case 10:
        return std::shared_ptr<Block>(new Oblock(subject.get()));
        break;
    case 11: case 12:
        return std::shared_ptr<Block>(new Tblock(subject.get()));
        break;
    default:
        return std::shared_ptr<Block>(new Iblock(subject.get()));
    }
}

std::shared_ptr<Block> Level1::fileNextBlock(std::shared_ptr<Board> subject) {
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 12 + 1)
    {
    case 1:
        return std::shared_ptr<Block>(new Sblock(subject.get()));
        break;
    case 2:
        return std::shared_ptr<Block>(new Zblock(subject.get()));
        break;
    case 3: case 4:
        return std::shared_ptr<Block>(new Iblock(subject.get()));
        break;
    case 5: case 6:
        return std::shared_ptr<Block>(new Jblock(subject.get()));
        break;
    case 7: case 8:
        return std::shared_ptr<Block>(new Lblock(subject.get()));
        break;
    case 9: case 10:
        return std::shared_ptr<Block>(new Oblock(subject.get()));
        break;
    case 11: case 12:
        return std::shared_ptr<Block>(new Tblock(subject.get()));
        break;
    default:
        return std::shared_ptr<Block>(new Iblock(subject.get()));
    }
}

void Level1::useFile(std::string file) {}

