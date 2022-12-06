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

std::shared_ptr<Block> Level2::randomNextBlock(Board* board) {
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 7 + 1)
    {
    case 1:
        return std::shared_ptr<Block>(new Sblock(board));
        break;
    case 2:
        return std::shared_ptr<Block>(new Zblock(board));
        break;
    case 3:
        return std::shared_ptr<Block>(new Iblock(board));
        break;
    case 4:
        return std::shared_ptr<Block>(new Jblock(board));
        break;
    case 5:
        return std::shared_ptr<Block>(new Lblock(board));
        break;
    case 6:
        return std::shared_ptr<Block>(new Oblock(board));
        break;
    case 7:
        return std::shared_ptr<Block>(new Tblock(board));
        break;
    default:
        return std::shared_ptr<Block>(new Iblock(board));
    }
}

std::shared_ptr<Block> Level2::fileNextBlock(Board* board) {
	// generate a random number
	int random = rand();

    // decide next block with generated number
    switch (random % 7 + 1)
    {
    case 1:
        return std::shared_ptr<Block>(new Sblock(board));
        break;
    case 2:
        return std::shared_ptr<Block>(new Zblock(board));
        break;
    case 3:
        return std::shared_ptr<Block>(new Iblock(board));
        break;
    case 4:
        return std::shared_ptr<Block>(new Jblock(board));
        break;
    case 5:
        return std::shared_ptr<Block>(new Lblock(board));
        break;
    case 6:
        return std::shared_ptr<Block>(new Oblock(board));
        break;
    case 7:
        return std::shared_ptr<Block>(new Tblock(board));
        break;
    default:
        return std::shared_ptr<Block>(new Iblock(board));
    }
}

void Level2::useFile(std::string file) {}
