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

using namespace std;

Level0::Level0(std::string fileToRead): Level{0}, blockIndex{0} {
    ifstream seq{fileToRead};
    char curr;

    while (seq >> curr) {
        file.push_back(curr);
    }

}

Level0::~Level0() {}

Block* Level0::randomNextBlock() {
	char next;
    int size = file.size();

    if (blockIndex == size) {
        blockIndex = 0;
    }
    next = file[blockIndex];
    blockIndex++;

    switch (next) {
        case 'I':
            return new Iblock();
            break;
        case 'J':
            return new Jblock();
            break;
        case 'L':
            return new Lblock();
            break;
        case 'O':
            return new Oblock();
            break;
        case 'S':
            return new Sblock();
            break;
        case 'Z':
            return new Zblock();
            break;
        case 'T':
            return new Tblock();
            break;
        default:
            return new Iblock();
    }
}

Block* Level0::fileNextBlock() {
    char next;
    int size = file.size();

    if (blockIndex == size) {
        blockIndex = 0;
    }
    next = file[blockIndex];
    blockIndex++;

    switch (next) {
        case 'I':
            return new Iblock();
            break;
        case 'J':
            return new Jblock();
            break;
        case 'L':
            return new Lblock();
            break;
        case 'O':
            return new Oblock();
            break;
        case 'S':
            return new Sblock();
            break;
        case 'Z':
            return new Zblock();
            break;
        case 'T':
            return new Tblock();
            break;
        default:
            return new Iblock();
    }
}

// method to take its blocks in sequence from the files sequence1.txt 
// (for player 1) and sequence2.txt (for player 2), or other file with 
// name specified
void Level0::useFile(string file) {
    blockIndex = 0;
    file.clear();

    ifstream seq{file};
    char curr;

    while (seq >> curr) {
        file.push_back(curr);
    }
}
