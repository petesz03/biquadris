#include "block.h"
#include "board.h"
#include "posn.h"

Block::Block(char item, Posn box1, Posn box2, Posn box3, Posn box4, int heaviness, bool candown, Board* the_board):
    item{item}, box1{box1}, box2{box2}, box3{box3}, box4{box4}, heaviness{heaviness}, candown{candown}, the_board{the_board} {}


void Block::moveleft() {
    if (box1.x == 0 || box2.x == 0 || box3.x == 0 || box4.x == 0) {
        return;
    } else {
        char temp1 = the_board->charAt(box1.x - 1, box1.y);
        char temp2 = the_board->charAt(box2.x - 1, box2.y);
        char temp3 = the_board->charAt(box3.x - 1, box3.y);
        char temp4 = the_board->charAt(box4.x - 1, box4.y);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            box1.x -= 1;
            box2.x -= 1;
            box3.x -= 1;
            box4.x -= 1;
        }
        if (the_board->isheavy) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                drop();
                return;
            } else {
                char temp5 = the_board->charAt(box1.x, box1.y + 1);
                char temp6 = the_board->charAt(box2.x, box2.y + 1);
                char temp7 = the_board->charAt(box3.x, box3.y + 1);
                char temp8 = the_board->charAt(box4.x, box4.y + 1);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    drop();
                    return;
                }
            }
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                drop();
                return;
            } else {
                char temp9 = the_board->charAt(box1.x, box1.y + 1);
                char temp10 = the_board->charAt(box2.x, box2.y + 1);
                char temp11 = the_board->charAt(box3.x, box3.y + 1);
                char temp12 = the_board->charAt(box4.x, box4.y + 1);
                if (temp9 == ' ' && temp10 == ' ' && temp11 == ' ' && temp12 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    drop();
                    return;
                }
            }
            
        }
        if (the_board->owners_level->level >= 3) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                return;
            } else {
                char temp5 = the_board->charAt(box1.x, box1.y + 1);
                char temp6 = the_board->charAt(box2.x, box2.y + 1);
                char temp7 = the_board->charAt(box3.x, box3.y + 1);
                char temp8 = the_board->charAt(box4.x, box4.y + 1);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    return;
                }
            }
        }
    }
}

void Block::moveright() {
    if (box1.x == 10 || box2.x == 10 || box3.x == 10 || box4.x == 10) {
        return;
    } else {
        char temp1 = the_board->charAt(box1.x + 1, box1.y);
        char temp2 = the_board->charAt(box2.x + 1, box2.y);
        char temp3 = the_board->charAt(box3.x + 1, box3.y);
        char temp4 = the_board->charAt(box4.x + 1, box4.y);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            box1.x += 1;
            box2.x += 1;
            box3.x += 1;
            box4.x += 1;
        }
        if (the_board->isheavy) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                drop();
                return;
            } else {
                char temp5 = the_board->charAt(box1.x, box1.y + 1);
                char temp6 = the_board->charAt(box2.x, box2.y + 1);
                char temp7 = the_board->charAt(box3.x, box3.y + 1);
                char temp8 = the_board->charAt(box4.x, box4.y + 1);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    drop();
                    return;
                }
            }
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                drop();
                return;
            } else {
                char temp9 = the_board->charAt(box1.x, box1.y + 1);
                char temp10 = the_board->charAt(box2.x, box2.y + 1);
                char temp11 = the_board->charAt(box3.x, box3.y + 1);
                char temp12 = the_board->charAt(box4.x, box4.y + 1);
                if (temp9 == ' ' && temp10 == ' ' && temp11 == ' ' && temp12 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    drop();
                    return;
                }
            }
            
        }
        if (the_board->owners_level->level >= 3) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                return;
            } else {
                char temp5 = the_board->charAt(box1.x, box1.y + 1);
                char temp6 = the_board->charAt(box2.x, box2.y + 1);
                char temp7 = the_board->charAt(box3.x, box3.y + 1);
                char temp8 = the_board->charAt(box4.x, box4.y + 1);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    return;
                }
            }
        }
    }
}

void Block::movedown() {
    if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
        drop();
        return;
    } else {
        char temp5 = the_board->charAt(box1.x, box1.y + 1);
        char temp6 = the_board->charAt(box2.x, box2.y + 1);
        char temp7 = the_board->charAt(box3.x, box3.y + 1);
        char temp8 = the_board->charAt(box4.x, box4.y + 1);
        if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
            box1.y += 1;
            box2.y += 1;
            box3.y += 1;
            box4.y += 1;
        } else {
            drop();
            return;
        }
    }
    if (the_board->owners_level->level >= 3) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                drop();
                return;
            } else {
                char temp5 = the_board->charAt(box1.x, box1.y + 1);
                char temp6 = the_board->charAt(box2.x, box2.y + 1);
                char temp7 = the_board->charAt(box3.x, box3.y + 1);
                char temp8 = the_board->charAt(box4.x, box4.y + 1);
                if (temp5 == ' ' && temp6 == ' ' && temp7 == ' ' && temp8 == ' ') {
                    box1.y += 1;
                    box2.y += 1;
                    box3.y += 1;
                    box4.y += 1;
                } else {
                    drop();
                    return;
                }
            }
        }
}

void Block::drop() {
	if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17){
		return;
	}
	char temp1 = the_board->charAt(box1.x, box1.y + 1);
	char temp2 = the_board->charAt(box2.x, box2.y + 1);
	char temp3 = the_board->charAt(box3.x, box3.y + 1);
	char temp4 = the_board->charAt(box4.x, box4.y + 1);
	if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' '){
		box1.y += 1;
		box2.y += 1;
		box3.y += 1;
		box4.y += 1;
		drop();
	}
	else{ return; }
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
