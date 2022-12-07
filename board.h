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
    std::shared_ptr<Block> currentBlock;
    std::shared_ptr<Block> nextBlock;
    int rowsCleared;
    int dropCounter;
public:
    Player* owner;
    std::shared_ptr<Level> owners_level;
    // Special Action
    bool isheavy;
    bool isblind;
    bool isforce;

    // Constructors and destructor:
    Board(std::shared_ptr<Player> owner, std::shared_ptr<Level> owners_level);
    ~Board();

    void checkfullrow();
    void clearRow(int row);

    // Creates a new block from level:
    std::shared_ptr<Block> createBlock();

    // Functions to set and get information:
    std::shared_ptr<Block> getCurrentBlock();
    char charAt(int row, int col);
    std::shared_ptr<Block> getNextBlock();
    void setCurrent(std::shared_ptr<Block> newBlock);
    void setNext(std::shared_ptr<Block> newBlock);

    void setPlayer(std::shared_ptr<Player> newPlayer);
    void setLevel(std::shared_ptr<Level> newLevel);
    
    // Function to check if board is full:
    bool checkLose();

    // Manipulating displays and blocks:
    void render();
    void attach(std::shared_ptr<Block> newBlock) override;
    void detach(std::shared_ptr<Block> newBlock) override;
    void attach(std::shared_ptr<DisplayObserver>  ob) override;
    void detach(DisplayObserver*  ob) override;

    // Special Actions:
    void unsetBlind(int pid);
    void blind();
    void punish();
    void setRowsCleared(int rows);
    int getRowsCleared();

    // Move block functions:
    void moveLeft();
    void moveRight();
    void moveDown();
    void drop();
    void clockwiseTurn();
    void counterClockwiseTurn();
};


#endif



