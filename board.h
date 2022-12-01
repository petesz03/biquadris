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

class Board: public Subject{
public:
    Player* owner;
    Level* owners_level;
    Block* currentBlock;
    Block* nextBlock;
    //special action
    bool isblind;
    bool isforce;
    /*

    //all blocks
    std::vector<Block*> v_all;
    
    //vector of each row
    std::vector<Block*> row0;
    std::vector<Block*> row1;
    std::vector<Block*> row2;
    std::vector<Block*> row3;
    std::vector<Block*> row4;
    std::vector<Block*> row5;
    std::vector<Block*> row6;
    std::vector<Block*> row7;
    std::vector<Block*> row8;
    std::vector<Block*> row9;
    std::vector<Block*> row10;
    std::vector<Block*> row11;
    std::vector<Block*> row12;
    std::vector<Block*> row13;
    std::vector<Block*> row14;
    std::vector<Block*> row15;
    std::vector<Block*> row16;
    std::vector<Block*> row17;
    */
    
    /*
    //max height
    int max_height;
    std::vector<int> to_free;
    int num_of_full;
    bool start_action;
    */

public:
    Board(Player* owner, Level* owners_level);
    ~Board();
    void checkfullrow();
    void clearRow(int row);
    Block* createBlock();
    Block* get_current();
    Char charAt(int row, int col);
};





#endif



