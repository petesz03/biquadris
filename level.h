#ifndef LEVEL_H
#define LEVEL_H

class Player;
class Block;

class Level {
protected:


public:
    int level;
    // ctor and virtual dtor for Level class
    Level(int level, bool random);
    virtual ~Level();

    // method for generating the next block for the given player
    virtual Block* nextBlock(Player* p) = 0;
};


#endif
