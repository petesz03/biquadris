#include "level4.h"

Level3::Level4(): Level(), blockIndex1{0}, blockIndex2{0}, isRandom{true} {
    ifstream seq1{"sequence1.txt"};
	ifstream seq2{"sequence2.txt"};

    string curr;

    while (seq1 >> curr) {
        file1.push_back(curr);
    }
    while (seq2 >> curr) {
        file2.push_back(curr);
    }
}

Level4::~Level4() {}

/////////////////////////////////////////////////////////////////
// PLEASE IMPLEMENT THE HEAVINESS OF BLOCK IF BLOCK CLASS IS DONE
/////////////////////////////////////////////////////////////////
Block* Level4::nextBlock(Player* p) {
    if (isRandom) {
        // set the given seed value
        srand((unsigned) time(NULL));
        // generate a random number
        int random = rand();

        // decide next block with generated number
        switch (random % 9 + 1)
        {
        case 1: case 2:
            return new SBlock();
            break;
        case 3: case 4:
            return new ZBlock();
            break;
        case 5:
            return new IBlock;
            break;
        case 6:
            return new JBlock();
            break;
        case 7:
            return new LBlock();
            break;
        case 8:
            return new OBlock();
            break;
        case 9:
            return new TBlock();
            break;
        default:
            return new IBlock();
        }
    } else {
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
}

// method to take its blocks in sequence from the files sequence1.txt 
// (for player 1) and sequence2.txt (for player 2), or other file with 
// name specified
void Level4::useFile1(string file) {
    blockIndex1 = 0;
    file1.clear();

    ifstream seq1{file};
    string curr;

    while (seq1 >> curr) {
        file1.push_back(curr);
    }
}

void Level4::useFile2(string file) {
    blockIndex2 = 0;
    file2.clear();

    ifstream seq2{file};
    string curr;

    while (seq2 >> curr) {
        file2.push_back(curr);
    }
}