#include "block.h"
#include "board.h"
#include "posn.h"
#include <iostream>

Block::Block(char item, Posn box1, Posn box2, Posn box3, Posn box4, int heaviness, bool candown, std::shared_ptr<Board> board):
    item{item}, box1{box1}, box2{box2}, box3{box3}, box4{box4}, heaviness{heaviness}, candown{candown} {
        the_board = std::shared_ptr<Board>(board);
        level_when_create = the_board->owner->getLevel();
    }


void Block::moveleft() {
    the_board->grid[box1.y][box1.x] = ' ';
    the_board->grid[box2.y][box2.x] = ' ';
    the_board->grid[box3.y][box3.x] = ' ';
    the_board->grid[box4.y][box4.x] = ' ';
    if (box1.x == 0 || box2.x == 0 || box3.x == 0 || box4.x == 0) {
        the_board->grid[box1.y][box1.x] = item;
        the_board->grid[box2.y][box2.x] = item;
        the_board->grid[box3.y][box3.x] = item;
        the_board->grid[box4.y][box4.x] = item;
        if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
            the_board->owner->makeDrop();
            return;
        }
    } else {
        char temp1 = the_board->charAt(box1.y, box1.x - 1);
        char temp2 = the_board->charAt(box2.y, box2.x - 1);
        char temp3 = the_board->charAt( box3.y, box3.x - 1);
        char temp4 = the_board->charAt( box4.y, box4.x - 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            box1.x -= 1;
            box2.x -= 1;
            box3.x -= 1;
            box4.x -= 1;
        }
        if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
            the_board->grid[box1.y][box1.x] = item;
            the_board->grid[box2.y][box2.x] = item;
            the_board->grid[box3.y][box3.x] = item;
            the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
            }
        if (the_board->isheavy) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                the_board->grid[box1.y][box1.x] = item;
                the_board->grid[box2.y][box2.x] = item;
                the_board->grid[box3.y][box3.x] = item;
                the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
            } else {
                char temp5 = the_board->charAt(box1.y + 1, box1.x);
                char temp6 = the_board->charAt(box2.y + 1, box2.x);
                char temp7 = the_board->charAt(box3.y + 1, box3.x);
                char temp8 = the_board->charAt(box4.y + 1, box4.x);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    the_board->grid[box1.y][box1.x] = item;
                    the_board->grid[box2.y][box2.x] = item;
                    the_board->grid[box3.y][box3.x] = item;
                    the_board->grid[box4.y][box4.x] = item;
                    the_board->owner->makeDrop();
                    return;
                }
            }
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                the_board->grid[box1.y][box1.x] = item;
                the_board->grid[box2.y][box2.x] = item;
                the_board->grid[box3.y][box3.x] = item;
                the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
            } else {
                char temp9 = the_board->charAt(box1.y + 1, box1.x);
                char temp10 = the_board->charAt(box2.y + 1, box2.x);
                char temp11 = the_board->charAt(box3.y + 1, box3.x);
                char temp12 = the_board->charAt(box4.y + 1, box4.x);
                if (temp9 == ' ' && temp10 == ' ' && temp11 == ' ' && temp12 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    the_board->grid[box1.y][box1.x] = item;
                    the_board->grid[box2.y][box2.x] = item;
                    the_board->grid[box3.y][box3.x] = item;
                    the_board->grid[box4.y][box4.x] = item;
                    the_board->owner->makeDrop();
                    return;
                }
            }
            
        }
        if (the_board->owners_level->getLevel() >= 3) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                the_board->grid[box1.y][box1.x] = item;
                the_board->grid[box2.y][box2.x] = item;
                the_board->grid[box3.y][box3.x] = item;
                the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
            } else {
                char temp5 = the_board->charAt(box1.y + 1, box1.x);
                char temp6 = the_board->charAt(box2.y + 1, box2.x);
                char temp7 = the_board->charAt(box3.y + 1, box3.x);
                char temp8 = the_board->charAt(box4.y + 1, box4.x);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    the_board->grid[box1.y][box1.x] = item;
                    the_board->grid[box2.y][box2.x] = item;
                    the_board->grid[box3.y][box3.x] = item;
                    the_board->grid[box4.y][box4.x] = item;
                    the_board->owner->makeDrop();
                    return;
                }
            }
        }
    }
    the_board->grid[box1.y][box1.x] = item;
    the_board->grid[box2.y][box2.x] = item;
    the_board->grid[box3.y][box3.x] = item;
    the_board->grid[box4.y][box4.x] = item;
}

void Block::moveright() {
    the_board->grid[box1.y][box1.x] = ' ';
    the_board->grid[box2.y][box2.x] = ' ';
    the_board->grid[box3.y][box3.x] = ' ';
    the_board->grid[box4.y][box4.x] = ' ';
    if (box1.x == 10 || box2.x == 10 || box3.x == 10 || box4.x == 10) {
        the_board->grid[box1.y][box1.x] = item;
        the_board->grid[box2.y][box2.x] = item;
        the_board->grid[box3.y][box3.x] = item;
        the_board->grid[box4.y][box4.x] = item;
        if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
            the_board->owner->makeDrop();
            return;
        }
    } else {
        char temp1 = the_board->charAt(box1.y, box1.x + 1);
        char temp2 = the_board->charAt(box2.y, box2.x + 1);
        char temp3 = the_board->charAt(box3.y, box3.x + 1);
        char temp4 = the_board->charAt(box4.y, box4.x + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            box1.x += 1;
            box2.x += 1;
            box3.x += 1;
            box4.x += 1;
        }
        if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
            the_board->grid[box1.y][box1.x] = item;
            the_board->grid[box2.y][box2.x] = item;
            the_board->grid[box3.y][box3.x] = item;
            the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
        }
        if (the_board->isheavy) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                the_board->grid[box1.y][box1.x] = item;
            the_board->grid[box2.y][box2.x] = item;
            the_board->grid[box3.y][box3.x] = item;
            the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
            } else {
                char temp5 = the_board->charAt(box1.y + 1, box1.x);
                char temp6 = the_board->charAt(box2.y + 1, box2.x);
                char temp7 = the_board->charAt(box3.y + 1, box3.x);
                char temp8 = the_board->charAt(box4.y + 1, box4.x);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    the_board->grid[box1.y][box1.x] = item;
                    the_board->grid[box2.y][box2.x] = item;
                    the_board->grid[box3.y][box3.x] = item;
                    the_board->grid[box4.y][box4.x] = item;
                    the_board->owner->makeDrop();
                    return;
                }
            }
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                the_board->grid[box1.y][box1.x] = item;
                the_board->grid[box2.y][box2.x] = item;
                the_board->grid[box3.y][box3.x] = item;
                the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
            } else {
                char temp9 = the_board->charAt(box1.y + 1, box1.x);
                char temp10 = the_board->charAt(box2.y + 1, box2.x);
                char temp11 = the_board->charAt(box3.y + 1, box3.x);
                char temp12 = the_board->charAt(box4.y + 1, box4.x);
                if (temp9 == ' ' && temp10 == ' ' && temp11 == ' ' && temp12 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    the_board->grid[box1.y][box1.x] = item;
                    the_board->grid[box2.y][box2.x] = item;
                    the_board->grid[box3.y][box3.x] = item;
                    the_board->grid[box4.y][box4.x] = item;
                    the_board->owner->makeDrop();
                    return;
                }
            }
            
        }
        if (the_board->owners_level->getLevel() >= 3) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                the_board->grid[box1.y][box1.x] = item;
                the_board->grid[box2.y][box2.x] = item;
                the_board->grid[box3.y][box3.x] = item;
                the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
            } else {
                char temp5 = the_board->charAt(box1.y + 1, box1.x);
                char temp6 = the_board->charAt(box2.y + 1,box2.x);
                char temp7 = the_board->charAt(box3.y + 1, box3.x);
                char temp8 = the_board->charAt(box4.y + 1, box4.x);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    the_board->grid[box1.y][box1.x] = item;
                    the_board->grid[box2.y][box2.x] = item;
                    the_board->grid[box3.y][box3.x] = item;
                    the_board->grid[box4.y][box4.x] = item;
                    the_board->owner->makeDrop();
                    return;
                }
            }
        }
    }
    the_board->grid[box1.y][box1.x] = item;
    the_board->grid[box2.y][box2.x] = item;
    the_board->grid[box3.y][box3.x] = item;
    the_board->grid[box4.y][box4.x] = item;
}

void Block::movedown() {
    the_board->grid[box1.y][box1.x] = ' ';
    the_board->grid[box2.y][box2.x] = ' ';
    the_board->grid[box3.y][box3.x] = ' ';
    the_board->grid[box4.y][box4.x] = ' ';
    if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
        the_board->grid[box1.y][box1.x] = item;
        the_board->grid[box2.y][box2.x] = item;
        the_board->grid[box3.y][box3.x] = item;
        the_board->grid[box4.y][box4.x] = item;
        the_board->owner->makeDrop();
        return;
    } else {
        char temp5 = the_board->charAt(box1.y + 1, box1.x);
        char temp6 = the_board->charAt(box2.y + 1,box2.x);
        char temp7 = the_board->charAt(box3.y + 1, box3.x);
        char temp8 = the_board->charAt(box4.y + 1, box4.x);
        if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
            box1.y += 1;
            box2.y += 1;
            box3.y += 1;
            box4.y += 1;
        } else {
            the_board->grid[box1.y][box1.x] = item;
            the_board->grid[box2.y][box2.x] = item;
            the_board->grid[box3.y][box3.x] = item;
            the_board->grid[box4.y][box4.x] = item;
            the_board->owner->makeDrop();
            return;
        }
    }
    if (the_board->owners_level->getLevel() >= 3) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                the_board->grid[box1.y][box1.x] = item;
                the_board->grid[box2.y][box2.x] = item;
                the_board->grid[box3.y][box3.x] = item;
                the_board->grid[box4.y][box4.x] = item;
                the_board->owner->makeDrop();
                return;
            } else {
                char temp5 = the_board->charAt(box1.y + 1, box1.x);
                char temp6 = the_board->charAt(box2.y + 1, box2.x);
                char temp7 = the_board->charAt(box3.y + 1, box3.x);
                char temp8 = the_board->charAt(box4.y + 1, box4.x);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    the_board->grid[box1.y][box1.x] = item;
                    the_board->grid[box2.y][box2.x] = item;
                    the_board->grid[box3.y][box3.x] = item;
                    the_board->grid[box4.y][box4.x] = item;
                    the_board->owner->makeDrop();
                    return;
                }
            }
        }
    the_board->grid[box1.y][box1.x] = item;
    the_board->grid[box2.y][box2.x] = item;
    the_board->grid[box3.y][box3.x] = item;
    the_board->grid[box4.y][box4.x] = item;
}

void Block::drop() {
    the_board->grid[box1.y][box1.x] = ' ';
    the_board->grid[box2.y][box2.x] = ' ';
    the_board->grid[box3.y][box3.x] = ' ';
    the_board->grid[box4.y][box4.x] = ' ';
	if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17){
        the_board->grid[box1.y][box1.x] = item;
        the_board->grid[box2.y][box2.x] = item;
        the_board->grid[box3.y][box3.x] = item;
        the_board->grid[box4.y][box4.x] = item;
		return;
	}
	char temp1 = the_board->charAt(box1.y + 1, box1.x);
	char temp2 = the_board->charAt(box2.y + 1, box2.x);
	char temp3 = the_board->charAt(box3.y + 1, box3.x);
	char temp4 = the_board->charAt(box4.y + 1, box4.x);
	if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' '){
		box1.y += 1;
		box2.y += 1;
		box3.y += 1;
		box4.y += 1;
        // std::cout << "value:" <<temp1 << temp2 << temp3 << temp4 << std::endl;
		drop();
	} else {
        the_board->grid[box1.y][box1.x] = item;
        the_board->grid[box2.y][box2.x] = item;
        the_board->grid[box3.y][box3.x] = item;
        the_board->grid[box4.y][box4.x] = item;
        return;
    }
}

void Block::clean(int x, int y) {
    if (box1.x == x && box1.y == y) {
        box1.x = -1;
        box1.y = -1;
        the_board->grid[box1.y][box1.x] = ' ';
    } else if (box2.x == x && box2.y == y) {
        the_board->grid[box2.y][box2.x] = ' ';
        box2.x = -1;
        box2.y = -1;
    } else if (box3.x == x && box3.y == y) {
        the_board->grid[box3.y][box3.x] = ' ';
        box3.x = -1;
        box3.y = -1;
    } else if (box4.x == x && box4.y == y) {
        box4.x = -1;
        box4.y = -1;
        the_board->grid[box4.y][box4.x] = ' ';
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

void Block::debug() {
    std::cout <<"(" <<box1.x << "," << box1.y << ")";
    std::cout <<"(" <<box2.x << "," << box2.y << ")";
    std::cout <<"(" <<box3.x << "," << box3.y << ")";
    std::cout <<"(" <<box4.x << "," << box4.y << ")";
    std::cout << std::endl;
}

bool Block::inrange(Posn box1, Posn box2, Posn box3, Posn box4) {
    if (box1.x >= 0
    && box1.x <= 10
    && box2.x >= 0
    && box2.x <= 10
    && box3.x >= 0
    && box3.x <= 10
    && box4.x >= 0
    && box4.x <= 10
    && box1.y >= 0
    && box1.y <= 17
    && box2.y >= 0
    && box2.y <= 17
    && box3.y >= 0
    && box3.y <= 17
    && box4.y >= 0
    && box4.y <= 17) {
        return true;
    } else {
        return false;
    }
}
