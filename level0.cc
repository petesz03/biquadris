#include "level0.h"
#include "player.h"
#include <string>
#include <fstream>
#include <vector>
#include "sblock.h"
#include "zblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "tblock.h"
#include <cstdlib>
#include <iostream>
#include "board.h"

using namespace std;

Level0::Level0(std::string fileToRead): Level{0}, blockIndex{0} {
    ifstream seq{fileToRead};
    char curr;

    while (seq >> curr) {
        file.push_back(curr);
    }

}

Level0::~Level0() {}

std::shared_ptr<Block> Level0::randomNextBlock(std::shared_ptr<Board> subject) {
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

std::shared_ptr<Block> Level0::fileNextBlock(std::shared_ptr<Board> subject) {
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
void Level0::useFile(string filename) {
    blockIndex = 0;
    file.clear();

    ifstream seq{filename};
    char curr;

    while (seq >> curr) {
        file.push_back(curr);
    }
}
