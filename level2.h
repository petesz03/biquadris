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

    std::shared_ptr<Block> randomNextBlock(std::shared_ptr<Board> subject);
    std::shared_ptr<Block> fileNextBlock(std::shared_ptr<Board> subject);
    void useFile(std::string file);
	
};

#endif
