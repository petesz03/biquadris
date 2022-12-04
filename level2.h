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

    Block* randomNextBlock(Board* subject);
    Block* fileNextBlock(Board* subject);
    void useFile(std::string file);
	
};

#endif
