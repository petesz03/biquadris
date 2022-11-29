#ifndef LEVEL2_H
#define LEVEL2_H

#include <vector>
#include <string>

#include "level.h"

class Player;

class Level0 : public Level {
public:
	Level2();
    ~Level2();

    Block* nextBlock(Player* p);
	
};

#endif
