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

    std::shared_ptr<Block> randomNextBlock(std::shared_ptr<Board> subject);
    std::shared_ptr<Block> fileNextBlock(std::shared_ptr<Board> subject);
    void useFile(std::string file);
	
};

#endif
