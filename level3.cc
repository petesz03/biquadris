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

Block* Level3::randomNextBlock(Board* subject) {
    // generate a random number
    int random = rand();

    // decide next block with generated number
    switch (random % 9 + 1)
    {
    case 1: case 2:
        return new Sblock(subject);
        break;
    case 3: case 4:
        return new Zblock(subject);
        break;
    case 5:
        return new Iblock(subject);
        break;
    case 6:
        return new Jblock(subject);
        break;
    case 7:
        return new Lblock(subject);
        break;
    case 8:
        return new Oblock(subject);
        break;
    case 9:
        return new Tblock(subject);
        break;
    default:
        return new Iblock(subject);
    }
}

Block* Level3::fileNextBlock(Board* subject) {
    char next;

    int size = file.size();
    if (blockIndex == size) {
        blockIndex = 0;
    }
    next = file[blockIndex];
    blockIndex++;

    switch (next) {
        case 'I':
            return new Iblock(subject);
            break;
        case 'J':
            return new Jblock(subject);
            break;
        case 'L':
            return new Lblock(subject);
            break;
        case 'O':
            return new Oblock(subject);
            break;
        case 'S':
            return new Sblock(subject);
            break;
        case 'Z':
            return new Zblock(subject);
            break;
        case 'T':
            return new Tblock(subject);
            break;
        default:
            return new Iblock(subject);
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
