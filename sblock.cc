#include "sblock.h"

Sblock::Sblock(Board* the_board, int heaviness, bool candown, int dir):
    Block{'S', Posn{4,2}, Posn{5,2}, Posn{5,1}, Posn{6,1}, heaviness, candown, the_board}, dir{dir} {}


Sblock::~Sblock() {

}

void Sblock::clockwiseturn() {
    if (dir == 1) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val - 1, x_val);
        char temp2 = the_board->charAt(y_val - 2, x_val);
        char temp3 = the_board->charAt(y_val - 1, x_val + 1);
        char temp4 = the_board->charAt(y_val, x_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            setbox1(x_val, y_val - 1);
            setbox2(x_val, y_val - 2);
            setbox3(x_val + 1, y_val - 1);
            setbox4(x_val + 1, y_val);
        }
    } else if (dir == 2) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val + 1, x_val);
        char temp2 = the_board->charAt(y_val + 1, x_val + 1);
        char temp3 = the_board->charAt(y_val, x_val + 1);
        char temp4 = the_board->charAt(y_val, x_val + 2);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            setbox1(x_val, y_val + 1);
            setbox2(x_val + 1, y_val + 1);
            setbox3(x_val + 1, y_val);
            setbox4(x_val + 2, y_val);
        }
    } else if (dir == 3) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val - 1, x_val);
        char temp2 = the_board->charAt(y_val - 2, x_val);
        char temp3 = the_board->charAt(y_val - 1, x_val + 1);
        char temp4 = the_board->charAt(y_val, x_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            setbox1(x_val, y_val - 1);
            setbox2(x_val, y_val - 2);
            setbox3(x_val + 1, y_val - 1);
            setbox4(x_val + 1, y_val);
        }
    } else if (dir == 4) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val + 1, x_val);
        char temp2 = the_board->charAt(y_val + 1, x_val + 1);
        char temp3 = the_board->charAt(y_val, x_val + 1);
        char temp4 = the_board->charAt(y_val, x_val + 2);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            setbox1(x_val, y_val + 1);
            setbox2(x_val + 1, y_val + 1);
            setbox3(x_val + 1, y_val);
            setbox4(x_val + 2, y_val);
        }
    }
}

void Sblock::counterturn() {
    if (dir == 1) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val - 1, x_val);
        char temp2 = the_board->charAt(y_val - 2, x_val);
        char temp3 = the_board->charAt(y_val - 1, x_val + 1);
        char temp4 = the_board->charAt(y_val, x_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            setbox1(x_val, y_val - 1);
            setbox2(x_val, y_val - 2);
            setbox3(x_val + 1, y_val - 1);
            setbox4(x_val + 1, y_val);
        }
    } else if (dir == 2) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val + 1, x_val);
        char temp2 = the_board->charAt(y_val + 1, x_val + 1);
        char temp3 = the_board->charAt(y_val, x_val + 1);
        char temp4 = the_board->charAt(y_val, x_val + 2);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            setbox1(x_val, y_val + 1);
            setbox2(x_val + 1, y_val + 1);
            setbox3(x_val + 1, y_val);
            setbox4(x_val + 2, y_val);
        }
    } else if (dir == 3) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val - 1, x_val);
        char temp2 = the_board->charAt(y_val - 2, x_val);
        char temp3 = the_board->charAt(y_val - 1, x_val + 1);
        char temp4 = the_board->charAt(y_val , x_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            setbox1(x_val, y_val - 1);
            setbox2(x_val, y_val - 2);
            setbox3(x_val + 1, y_val - 1);
            setbox4(x_val + 1, y_val);
        }
    } else if (dir == 4) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val + 1, x_val);
        char temp2 = the_board->charAt(y_val + 1, x_val + 1);
        char temp3 = the_board->charAt(y_val, x_val + 1);
        char temp4 = the_board->charAt(y_val, x_val + 2);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ' && temp4 == ' ') {
            setbox1(x_val, y_val + 1);
            setbox2(x_val + 1, y_val + 1);
            setbox3(x_val + 1, y_val);
            setbox4(x_val + 2, y_val);
        }
    }
    if (the_board->owners_level->level >= 3) {
            if (box1.y == 17 || box2.y == 17 || box3.y == 17 || box4.y == 17) {
                drop();
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
                    drop();
                    return;
                }
            }
    }
}
