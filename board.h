#ifndef __BOARD_H__
#define __BOARD_H__

#include "player.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include <vector>
#include "level.h"
#include "subject.h"
#include <memory>

class Board: public Subject{
public:
    Player* owner;
    std::shared_ptr<Level> owners_level;
    std::shared_ptr<Block> currentBlock;
    std::shared_ptr<Block> nextBlock;
    //special action
    bool isblind;
    bool isforce;
    bool isheavy;
    

public:
    Board(std::shared_ptr<Player> owner, std::shared_ptr<Level> owners_level);
    ~Board();
    void checkfullrow();
    void clearRow(int row);
    std::shared_ptr<Block> createBlock();
    std::shared_ptr<Block> getCurrentBlock();
    char charAt(int row, int col);
    std::shared_ptr<Block> getNextBlock();
    void setCurrent(std::shared_ptr<Block> newBlock);
    void setNext(std::shared_ptr<Block> newBlock);
    void render();
    void setPlayer(std::shared_ptr<Player> newPlayer);
    void setLevel(std::shared_ptr<Level> newLevel);
    bool checkLose();
    void attach(std::shared_ptr<Block> newBlock) override;
    void detach(std::shared_ptr<Block> newBlock) override;
    void attach(std::shared_ptr<DisplayObserver> ob) override;
    void detach(std::shared_ptr<DisplayObserver> ob) override;
    void unsetBlind(int pid);
    // Move block functions:
    void moveLeft();
    void moveRight();
    void moveDown();
    void drop();
    void clockwiseTurn();
    void counterClockwiseTurn();
};





#endif



