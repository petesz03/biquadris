#ifndef LEVEL3_H
#define LEVEL3_H

#include <vector>
#include <string>

#include "level.h"

class Player;
class Board;

class Level3 : public Level {
	//  store its blocks in sequence from the files 
    // sequence1.txt (for player 1) and sequence2.txt (for player 2) 
    std::vector<char> file;

    // tracks the current index of block in the file sequence input
    int blockIndex;

public:
	Level3();
    ~Level3();

    std::shared_ptr<Block> randomNextBlock(Board* board);
    std::shared_ptr<Block> fileNextBlock(Board* board);

	// method to take its blocks in sequence from the files sequence1.txt 
    // (for player 1) and sequence2.txt (for player 2), or other file with 
    // name specified
	void useFile(std::string filename);
	
};

#endif
