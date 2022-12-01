#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "posn.h"
#include <vector>

class Block {
public:
    char item;
    Posn box1;
    Posn box2;
    Posn box3;
    Posn box4;
    int heaviness;
    bool candown;
public:
    void moveleft();
    void moveright();
    void movedown();
    void clean(int x, int y);
    virtual void clockwiseturn();
    virtual void counterturn();
    //ctor
    Block(char, Posn, Posn, Posn, Posn, int, bool);
    //dtor
    virtual ~Block();
    void cantmove();
    void setbox1(int x, int y);
    void setbox2(int x, int y);
    void setbox3(int x, int y);
    void setbox4(int x, int y);
};




#endif

