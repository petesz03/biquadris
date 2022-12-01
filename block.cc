#include "block.h"

Block::Block(char item, Posn box1, Posn box2, Posn box3, Posn box4, int heaviness = 0, bool candown = true):
    item{item}, box1{box1}, box2{box2}, box3{box3}, box4{box4}, heaviness{heaviness}, candown{candown} {}


void Block::moveleft() {
    if (box1.x == 0 || box2.x == 0 || box3.x == 0 || box4.x == 0) {
        return;
    } else {
        box1.x -= 1;
        box2.x -= 1;
        box3.x -= 1;
        box4.x -= 1;
    }
}

void Block::moveright() {
    if (box1.x == 10 || box2.x == 10 || box3.x == 10 || box4.x == 10) {
        return;
    } else {
        box1.x += 1;
        box2.x += 1;
        box3.x += 1;
        box4.x += 1;
    }
}

void Block::movedown() {
    if (candown) {
        box1.y += (1 + heaviness);
        box2.y += (1 + heaviness);
        box3.y += (1 + heaviness);
        box4.y += (1 + heaviness);
    }
}

void Block::clean(int x, int y) {
    if (box1.x == x && box1.y == y) {
        box1.x = -1;
        box1.y = -1;
    } else if (box2.x == x && box2.y == y) {
        box2.x = -1;
        box2.y = -1;
    } else if (box3.x == x && box3.y == y) {
        box3.x = -1;
        box3.y = -1;
    } else if (box4.x == x && box4.y == y) {
        box4.x = -1;
        box4.y = -1;
    }
}

void Block::cantmove() {
    candown = false;
}

void Block::clockwiseturn() {

}

void Block::counterturn() {

}

Block::~Block() {

}

void Block::setbox1(int x, int y) {
    Posn temp = Posn{x,y};
    box1 = temp;
}

void Block::setbox2(int x, int y) {
    Posn temp = Posn{x,y};
    box2 = temp;
}

void Block::setbox3(int x, int y) {
    Posn temp = Posn{x,y};
    box3 = temp;
}

void Block::setbox4(int x, int y) {
    Posn temp = Posn{x,y};
    box4 = temp;
}

char Block::getItem(){ return item; }