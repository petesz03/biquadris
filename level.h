#ifndef LEVEL_H
#define LEVEL_H
#include <string>

class Player;
class Block;

class Level {
protected:


public:
    int level;
    // ctor and virtual dtor for Level class
    Level(int level);
    virtual ~Level();

    // method for generating the next block for the given player
    virtual Block* randomNextBlock() = 0;
    virtual Block* fileNextBlock() = 0;
    virtual void useFile(std::string file) = 0;

};

#endif
