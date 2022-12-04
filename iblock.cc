#include <vector>
#include "iblock.h"
#include "posn.h"

Iblock::Iblock(Board* the_board, int heaviness, bool candown, int dir):
    Block{'I', Posn{3,2}, Posn{4,2}, Posn{5,2}, Posn{6,2}, heaviness, candown, the_board}, dir{dir} {}


Iblock::~Iblock() {

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
