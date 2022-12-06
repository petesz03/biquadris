#include <fstream>
#include "level3.h"
#include "sblock.h"
#include "zblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "tblock.h"
#include "player.h"
#include "board.h"
#include <cstdlib>
using namespace std;

Level3::Level3(): Level{3}, blockIndex{0} {}

Level3::~Level3() {}

std::shared_ptr<Block> Level3::randomNextBlock(Board* board) {
    // generate a random number
    int random = rand();

    // decide next block with generated number
    switch (random % 9 + 1)
    {
    case 1: case 2:
        return std::shared_ptr<Block>(new Sblock(board));
        break;
    case 3: case 4:
        return std::shared_ptr<Block>(new Zblock(board));
        break;
    case 5:
        return std::shared_ptr<Block>(new Iblock(board));
        break;
    case 6:
        return std::shared_ptr<Block>(new Jblock(board));
        break;
    case 7:
        return std::shared_ptr<Block>(new Lblock(board));
        break;
    case 8:
        return std::shared_ptr<Block>(new Oblock(board));
        break;
    case 9:
        return std::shared_ptr<Block>(new Tblock(board));
        break;
    default:
        return std::shared_ptr<Block>(new Iblock(board));
    }
}

std::shared_ptr<Block> Level3::fileNextBlock(Board* board) {
    char next;

    int size = file.size();
    if (blockIndex == size) {
        blockIndex = 0;
    }
    next = file[blockIndex];
    blockIndex++;

    switch (next) {
        case 'I':
            return std::shared_ptr<Block>(new Iblock(board));
            break;
        case 'J':
            return std::shared_ptr<Block>(new Jblock(board));
            break;
        case 'L':
            return std::shared_ptr<Block>(new Lblock(board));
            break;
        case 'O':
            return std::shared_ptr<Block>(new Oblock(board));
            break;
        case 'S':
            return std::shared_ptr<Block>(new Sblock(board));
            break;
        case 'Z':
            return std::shared_ptr<Block>(new Zblock(board));
            break;
        case 'T':
            return std::shared_ptr<Block>(new Tblock(board));
            break;
        default:
            return std::shared_ptr<Block>(new Iblock(board));
    }

}


// method to take its blocks in sequence from the files sequence1.txt 
// (for player 1) and sequence2.txt (for player 2), or other file with 
// name specified
void Level3::useFile(string filename) {
    blockIndex = 0;
    file.clear();

    ifstream seq{filename};
    char curr;

    while (seq >> curr) {
        file.push_back(curr);
    }
}
