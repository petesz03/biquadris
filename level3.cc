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
#include <cstdlib>
using namespace std;

Level3::Level3(): Level{3}, blockIndex1{0}, blockIndex2{0}, isRandom{true} {
    ifstream seq1{"sequence1.txt"};
	ifstream seq2{"sequence2.txt"};

    char curr;

    while (seq1 >> curr) {
        file1.push_back(curr);
    }
    while (seq2 >> curr) {
        file2.push_back(curr);
    }
}

Level3::~Level3() {}

Block* Level3::nextBlock(Player* p) {
    if (isRandom) {
        // set the given seed value
        srand((unsigned) time(NULL));
        // generate a random number
        int random = rand();

        // decide next block with generated number
        switch (random % 9 + 1)
        {
        case 1: case 2:
            return new Sblock();
            break;
        case 3: case 4:
            return new Zblock();
            break;
        case 5:
            return new Iblock();
            break;
        case 6:
            return new Jblock();
            break;
        case 7:
            return new Lblock();
            break;
        case 8:
            return new Oblock();
            break;
        case 9:
            return new Tblock();
            break;
        default:
            return new Iblock();
        }
    } else {
        int pid = p->getPid();
        char next;

        if (pid == 1) {
            int size1 = file1.size();
            if (blockIndex1 == size1) {
                blockIndex1 = 0;
            }
            next = file1[blockIndex1];
            blockIndex1++;
        } else if (pid == 2) {
            int size2 = file2.size();
            if (blockIndex2 == size2) {
                blockIndex2 = 0;
            }
            next = file2[blockIndex2];
            blockIndex2++;
        }

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
}


// method to take its blocks in sequence from the files sequence1.txt 
// (for player 1) and sequence2.txt (for player 2), or other file with 
// name specified
void Level3::useFile1(string file) {
    blockIndex1 = 0;
    file1.clear();

    ifstream seq1{file};
    char curr;

    while (seq1 >> curr) {
        file1.push_back(curr);
    }
}

void Level3::useFile2(string file) {
    blockIndex2 = 0;
    file2.clear();

    ifstream seq2{file};
    char curr;

    while (seq2 >> curr) {
        file2.push_back(curr);
    }
}