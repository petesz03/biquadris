#ifndef LEVEL0_H
#define LEVEL0_H

#include <vector>
#include <string>

#include "level.h"

class Player;

class Level0 : public Level {
	// store its blocks in sequence from the files 
    // sequence1.txt (for player 1) and sequence2.txt (for player 2) 
    std::vector<char> file;

    // tracks the current index of block in the file sequence input
    int blockIndex;
    
public:
    // We overload constructor to support reading from a different file!!
    Level0(std::string file);
    ~Level0();

    Block* fileNextBlock();
    Block* randomNextBlock();

    // method to take its blocks in sequence from the files sequence1.txt 
    // (for player 1) and sequence2.txt (for player 2), or other file with 
    // name specified
	void useFile(std::string file);
};

#endif
