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

std::shared_ptr<Block> Level2::randomNextBlock(std::shared_ptr<Board> subject) {
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 7 + 1)
    {
    case 1:
        return std::shared_ptr<Block>(new Sblock(subject.get()));
        break;
    case 2:
        return std::shared_ptr<Block>(new Zblock(subject.get()));
        break;
    case 3:
        return std::shared_ptr<Block>(new Iblock(subject.get()));
        break;
    case 4:
        return std::shared_ptr<Block>(new Jblock(subject.get()));
        break;
    case 5:
        return std::shared_ptr<Block>(new Lblock(subject.get()));
        break;
    case 6:
        return std::shared_ptr<Block>(new Oblock(subject.get()));
        break;
    case 7:
        return std::shared_ptr<Block>(new Tblock(subject.get()));
        break;
    default:
        return std::shared_ptr<Block>(new Iblock(subject.get()));
    }
}

std::shared_ptr<Block> Level2::fileNextBlock(std::shared_ptr<Board> subject) {
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 7 + 1)
    {
    case 1:
        return std::shared_ptr<Block>(new Sblock(subject.get()));
        break;
    case 2:
        return std::shared_ptr<Block>(new Zblock(subject.get()));
        break;
    case 3:
        return std::shared_ptr<Block>(new Iblock(subject.get()));
        break;
    case 4:
        return std::shared_ptr<Block>(new Jblock(subject.get()));
        break;
    case 5:
        return std::shared_ptr<Block>(new Lblock(subject.get()));
        break;
    case 6:
        return std::shared_ptr<Block>(new Oblock(subject.get()));
        break;
    case 7:
        return std::shared_ptr<Block>(new Tblock(subject.get()));
        break;
    default:
        return std::shared_ptr<Block>(new Iblock(subject.get()));
    }
}

void Level2::useFile(std::string file) {}
