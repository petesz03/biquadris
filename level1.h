#ifndef LEVEL1_H
#define LEVEL1_H

#include <vector>
#include <string>

#include "level.h"

class Player;

class Level1 : public Level {
public:
    
	Level1();
    ~Level1();

    Block* randomNextBlock();
    Block* fileNextBlock();
    void useFile(std::string file);
	
};

#endif
