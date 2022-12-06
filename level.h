#ifndef LEVEL_H
#define LEVEL_H
#include <string>

class Player;
class Block;
class Board;

class Level {
protected:
    int level;

public:
    // ctor and virtual dtor for Level class
    Level(int level);
    virtual ~Level();

    // method for generating the next block for the given player
    virtual Block* randomNextBlock(Board* subject) = 0;
    virtual Block* fileNextBlock(Board* subject) = 0;
    virtual void useFile(std::string file) = 0;

    // field getter
    int getLevel();

};

#endif
