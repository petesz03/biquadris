#include <vector>
#include "iblock.h"
#include "posn.h"

Iblock::Iblock(int heaviness, bool candown, int dir, Board* the_board):
    Block{'I', Posn{3,2}, Posn{4,2}, Posn{5,2}, Posn{6,2}, heaviness, candown, the_board}, dir{dir} {}


Iblock::~Iblock() {

}

void Iblock::moveleft() {
    if (dir == 1 || dir == 3) {
        if (the_board->isheavy == false) {
            char temp = the_board->charAt(box1.x - 1, box1.y);
            if (temp == ' ') {
                box1.x -= 1;
                box2.x -= 1;
                box3.x -= 1;
                box4.x -= 1;
            }
        } else {
            char temp1 = the_board->charAt(box1.x - 1, box1.y);
            if (temp1 == ' ') {
                box1.x -= 1;
                box2.x -= 1;
                box3.x -= 1;
                box4.x -= 1;
            }
            char temp2 = the_board->charAt(box2.x, box2.y + 1);
            char temp3 = the_board->charAt(box3.x, box3.y + 1);
            char temp4 = the_board->charAt(box4.x, box4.y + 1);
            char temp5 = the_board->charAt(box1.x, box1.y + 1);
            if (temp2 == ' '&& temp3 == ' '&& temp4 == ' '&& temp5 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
            char temp6 = the_board->charAt(box1.x, box1.y + 1);
            char temp7 = the_board->charAt(box2.x, box2.y + 1);
            char temp8 = the_board->charAt(box3.x, box3.y + 1);
            char temp9 = the_board->charAt(box4.x, box4.y + 1);
            if (temp6 == ' '&& temp7 == ' '&& temp8 == ' '&& temp9 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
        }
    } else {
        if (the_board->isheavy == false) {
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
            char temp5 = the_board->charAt(box1.x, box1.y + 1);
            if (temp5 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
            char temp6 = the_board->charAt(box1.x, box1.y + 1);
            if (temp6 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
        }
    }
}
void Iblock::moveright() {
    if (dir == 1 || dir == 3) {
        if (the_board->isheavy == false) {
            char temp = the_board->charAt(box1.x + 1, box1.y);
            if (temp == ' ') {
                box1.x += 1;
                box2.x += 1;
                box3.x += 1;
                box4.x += 1;
            }
        } else {
            char temp1 = the_board->charAt(box1.x + 1, box1.y);
            if (temp1 == ' ') {
                box1.x += 1;
                box2.x += 1;
                box3.x += 1;
                box4.x += 1;
            }
            char temp2 = the_board->charAt(box2.x, box2.y + 1);
            char temp3 = the_board->charAt(box3.x, box3.y + 1);
            char temp4 = the_board->charAt(box4.x, box4.y + 1);
            char temp5 = the_board->charAt(box1.x, box1.y + 1);
            if (temp2 == ' '&& temp3 == ' '&& temp4 == ' '&& temp5 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
            char temp6 = the_board->charAt(box1.x, box1.y + 1);
            char temp7 = the_board->charAt(box2.x, box2.y + 1);
            char temp8 = the_board->charAt(box3.x, box3.y + 1);
            char temp9 = the_board->charAt(box4.x, box4.y + 1);
            if (temp6 == ' '&& temp7 == ' '&& temp8 == ' '&& temp9 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
        }
    } else {
        if (the_board->isheavy == false) {
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
            char temp5 = the_board->charAt(box1.x, box1.y + 1);
            if (temp5 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
            char temp6 = the_board->charAt(box1.x, box1.y + 1);
            if (temp6 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
        }
    }
}
void Iblock::movedown() {
    for (int i = 0; i <= heaviness; i++) {
        if (dir == 1 || dir == 3) {
            char temp2 = the_board->charAt(box2.x, box2.y + 1);
            char temp3 = the_board->charAt(box3.x, box3.y + 1);
            char temp4 = the_board->charAt(box4.x, box4.y + 1);
            char temp5 = the_board->charAt(box1.x, box1.y + 1);
            if (temp2 == ' '&& temp3 == ' '&& temp4 == ' '&& temp5 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
        } else {
            char temp = the_board->charAt(box1.x, box1.y + 1);
            if (temp == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
        }
    }
}
void Iblock::drop() {
    while (true) {
        if (dir == 1 || dir == 3) {
            char temp2 = the_board->charAt(box2.x, box2.y + 1);
            char temp3 = the_board->charAt(box3.x, box3.y + 1);
            char temp4 = the_board->charAt(box4.x, box4.y + 1);
            char temp5 = the_board->charAt(box1.x, box1.y + 1);
            if (temp2 == ' '&& temp3 == ' '&& temp4 == ' '&& temp5 == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
        } else {
            char temp = the_board->charAt(box1.x, box1.y + 1);
            if (temp == ' ') {
                box1.y += 1;
                box2.y += 1;
                box3.y += 1;
                box4.y += 1;
            } else {
                candown = false;
                return;
            }
        }
    }
}




void Iblock::clockwiseturn() {
    if (dir == 1) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val, y_val - 1);
        char temp2 = the_board->charAt(x_val, y_val - 2);
        char temp3 = the_board->charAt(x_val, y_val - 3);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val, y_val - 1);
            setbox3(x_val, y_val - 2);
            setbox4(x_val, y_val - 3);
        }
    } else if (dir == 2) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val + 1, y_val);
        char temp2 = the_board->charAt(x_val + 2, y_val);
        char temp3 = the_board->charAt(x_val + 3, y_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val + 1, y_val);
            setbox3(x_val + 2, y_val);
            setbox4(x_val + 3, y_val);
        }
    } else if (dir == 3) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val, y_val - 1);
        char temp2 = the_board->charAt(x_val, y_val - 2);
        char temp3 = the_board->charAt(x_val, y_val - 3);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val, y_val - 1);
            setbox3(x_val, y_val - 2);
            setbox4(x_val, y_val - 3);
        }
    } else if (dir == 4) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val + 1, y_val);
        char temp2 = the_board->charAt(x_val + 2, y_val);
        char temp3 = the_board->charAt(x_val + 3, y_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val + 1, y_val);
            setbox3(x_val + 2, y_val);
            setbox4(x_val + 3, y_val);
        }
    }
}

void Iblock::counterturn() {
    if (dir == 1) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val, y_val - 1);
        char temp2 = the_board->charAt(x_val, y_val - 2);
        char temp3 = the_board->charAt(x_val, y_val - 3);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val, y_val - 1);
            setbox3(x_val, y_val - 2);
            setbox4(x_val, y_val - 3);
        }
    } else if (dir == 2) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val + 1, y_val);
        char temp2 = the_board->charAt(x_val + 2, y_val);
        char temp3 = the_board->charAt(x_val + 3, y_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val + 1, y_val);
            setbox3(x_val + 2, y_val);
            setbox4(x_val + 3, y_val);
        }
    } else if (dir == 3) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val, y_val - 1);
        char temp2 = the_board->charAt(x_val, y_val - 2);
        char temp3 = the_board->charAt(x_val, y_val - 3);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val, y_val - 1);
            setbox3(x_val, y_val - 2);
            setbox4(x_val, y_val - 3);
        }
    } else if (dir == 4) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val + 1, y_val);
        char temp2 = the_board->charAt(x_val + 2, y_val);
        char temp3 = the_board->charAt(x_val + 3, y_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val + 1, y_val);
            setbox3(x_val + 2, y_val);
            setbox4(x_val + 3, y_val);
        }
    }
}
