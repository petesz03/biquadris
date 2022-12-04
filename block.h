#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "posn.h"
#include <vector>

class Board;

class Block {
public:
    char item;
    Posn box1;
    Posn box2;
    Posn box3;
    Posn box4;
    int heaviness;
    bool candown;
    Board* the_board;

public:
    void moveleft();
    void moveright();
    void movedown();
    void drop();
    void clean(int x, int y);
    virtual void clockwiseturn();
    virtual void counterturn();
    //ctor
    Block(char, Posn, Posn, Posn, Posn, int, bool, Board*);
    //dtor
    virtual ~Block();
    void cantmove();
    void setbox1(int x, int y);
    void setbox2(int x, int y);
    void setbox3(int x, int y);
    void setbox4(int x, int y);
    char getItem();
};




#endif

