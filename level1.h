#ifndef LEVEL1_H
#define LEVEL1_H

#include <vector>
#include <string>

#include "level.h"

class Player;

class Board;

class Level1 : public Level {
public:
    
	Level1();
    ~Level1();

    std::shared_ptr<Block> randomNextBlock(Board* board);
    std::shared_ptr<Block> fileNextBlock(Board* board);
    void useFile(std::string file);
	
};

#endif
