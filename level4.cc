#include <fstream>
#include "level4.h"
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

Level4::Level4(): Level{4}, blockIndex{0} {}

Level4::~Level4() {}

/////////////////////////////////////////////////////////////////
// PLEASE IMPLEMENT THE HEAVINESS OF BLOCK IF BLOCK CLASS IS DONE
/////////////////////////////////////////////////////////////////
std::shared_ptr<Block> Level4::randomNextBlock(std::shared_ptr<Board> subject) {
    // generate a random number
    int random = rand();

    // decide next block with generated number
    switch (random % 9 + 1)
    {
    case 1: case 2:
        return std::shared_ptr<Block>(new Sblock(subject));
        break;
    case 3: case 4:
        return std::shared_ptr<Block>(new Zblock(subject));
        break;
    case 5:
        return std::shared_ptr<Block>(new Iblock(subject));
        break;
    case 6:
        return std::shared_ptr<Block>(new Jblock(subject));
        break;
    case 7:
        return std::shared_ptr<Block>(new Lblock(subject));
        break;
    case 8:
        return std::shared_ptr<Block>(new Oblock(subject));
        break;
    case 9:
        return std::shared_ptr<Block>(new Tblock(subject));
        break;
    default:
        return std::shared_ptr<Block>(new Iblock(subject));
    }
} 
    
std::shared_ptr<Block> Level4::fileNextBlock(std::shared_ptr<Board> subject) {
    char next;
    int size = file.size();

    if (blockIndex == size) {
        blockIndex = 0;
    }
    next = file[blockIndex];
    blockIndex++;
        
    switch (next) {
        case 'I':
            return std::shared_ptr<Block>(new Iblock(subject));
            break;
        case 'J':
            return std::shared_ptr<Block>(new Jblock(subject));
            break;
        case 'L':
            return std::shared_ptr<Block>(new Lblock(subject));
            break;
        case 'O':
            return std::shared_ptr<Block>(new Oblock(subject));
            break;
        case 'S':
            return std::shared_ptr<Block>(new Sblock(subject));
            break;
        case 'Z':
            return std::shared_ptr<Block>(new Zblock(subject));
            break;
        case 'T':
            return std::shared_ptr<Block>(new Tblock(subject));
            break;
        default:
            return std::shared_ptr<Block>(new Iblock(subject));
    }
}

// method to take its blocks in sequence from the files sequence1.txt 
// (for player 1) and sequence2.txt (for player 2), or other file with 
// name specified
void Level4::useFile(string filename) {
    blockIndex = 0;
    file.clear();

    ifstream seq{filename};
    char curr;

    while (seq >> curr) {
        file.push_back(curr);
    }
}
