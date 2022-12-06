#ifndef LEVEL2_H
#define LEVEL2_H

#include <vector>
#include <string>

#include "level.h"

class Player;
class Board;

class Level2 : public Level {
public:
    Level2();
    ~Level2();

    std::shared_ptr<Block> randomNextBlock(Board* board);
    std::shared_ptr<Block> fileNextBlock(Board* board);
    void useFile(std::string file);
	
};

#endif
