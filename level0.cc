#include "level0.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Level0::Level0(std::string fileToRead): Level{0} {
    ifstream seq1{fileToRead};
	/* ifstream seq2{"sequence2.txt"}; */
    string curr;

    while (seq1 >> curr) {
        file1.push_back(curr);
    }

    /*
    while (seq2 >> curr) {
        file2.push_back(curr);
    }
    */
}
Level0::Level0(std::string file){
    ifstream seq1{file};
    string curr;
    while (seq1 >> curr) {
        file1.push_back(curr);
    }
}


Level0::~Level0() {}

void changefile2(std::string file);

Block* Level0::nextBlock(Player* p) {
    int pid = p->getPid();
    string next;

    if (pid == 1) {
        if (blockIndex1 == file1.size()) {
            blockIndex1 = 0;
        }
        next = file1[blockIndex1];
        blockIndex1++;
    } else if (pid == 2) {
        if (blockIndex2 == file2.size()) {
            blockIndex2 = 0;
        }
        next = file2[blockIndex2];
        blockIndex2++;
    }

    switch (next) {
        case "I":
            return new IBlock();
            break;
        case "J":
            return new JBlock();
            break;
        case "L":
            return new LBlock();
            break;
        case "O":
            return new OBlock();
            break;
        case "S":
            return new SBlock();
            break;
        case "Z":
            return new ZBlock();
            break;
        case "T":
            return new TBlock();
            break;
        default:
            return new IBlock();
    }
}

// method to take its blocks in sequence from the files sequence1.txt 
// (for player 1) and sequence2.txt (for player 2), or other file with 
// name specified
void Level0::useFile1(string file) {
    blockIndex1 = 0;
    file1.clear();

    ifstream seq1{file};
    string curr;

    while (seq1 >> curr) {
        file1.push_back(curr);
    }
}
/*
void Level0::useFile2(string file) {
    blockIndex2 = 0;
    file2.clear();

    ifstream seq2{file};
    string curr;

    while (seq2 >> curr) {
        file2.push_back(curr);
    }
}
*/