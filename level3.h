#ifndef LEVEL3_H
#define LEVEL3_H

#include <vector>
#include <string>

#include "level.h"

class Player;

class Level3 : public Level {
	//  store its blocks in sequence from the files 
    // sequence1.txt (for player 1) and sequence2.txt (for player 2) 
    vector<string> file1;
	vector<string> file2;

    // tracks the current index of block in the file sequence input
    int blockIndex1;
    int blockIndex2;

    // store whether or not this Level3 is random currently
    bool isRandom;
public:
	Level3();
    ~Level3();

    Block* nextBlock(Player* p);

	// method to take its blocks in sequence from the files sequence1.txt 
    // (for player 1) and sequence2.txt (for player 2), or other file with 
    // name specified
	void useFile1(string file);
	void useFile2(string file);
	
};

#endif
