#include <vector>
#include "tblock.h"

Tblock::Tblock(Board* the_board, int heaviness, bool candown, int dir):
    Block{'T', Posn{5,1}, Posn{4,1}, Posn{6,1}, Posn{5,2}, heaviness, candown, the_board}, dir{dir} {}


Tblock::~Tblock() {

}

void Tblock::clockwiseturn() {
    if (dir == 1) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val - 1, y_val);
        char temp2 = the_board->charAt(x_val, y_val - 1);
        char temp3 = the_board->charAt(x_val, y_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val - 1, y_val);
            setbox3(x_val, y_val - 1);
            setbox4(x_val, y_val + 1);
        }
    } else if (dir == 2) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val - 1, y_val + 1);
        char temp2 = the_board->charAt(x_val, y_val + 1);
        char temp3 = the_board->charAt(x_val + 1, y_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val - 1, y_val + 1);
            setbox3(x_val, y_val + 1);
            setbox4(x_val + 1, y_val + 1);
        }
    } else if (dir == 3) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val - 1, y_val - 1);
        char temp2 = the_board->charAt(x_val - 1, y_val + 1);
        char temp3 = the_board->charAt(x_val - 1, y_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val - 1, y_val - 1);
            setbox3(x_val - 1, y_val + 1);
            setbox4(x_val - 1, y_val);
        }
    } else if (dir == 4) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val - 1, y_val);
        char temp2 = the_board->charAt(x_val + 1, y_val);
        char temp3 = the_board->charAt(x_val, y_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val - 1, y_val);
            setbox3(x_val + 1, y_val);
            setbox4(x_val, y_val + 1);
        }
    }
}

void Tblock::counterturn() {
    if (dir == 1) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val - 1, y_val - 1);
        char temp2 = the_board->charAt(x_val - 1, y_val + 1);
        char temp3 = the_board->charAt(x_val - 1, y_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val - 1, y_val - 1);
            setbox3(x_val - 1, y_val + 1);
            setbox4(x_val - 1, y_val);
        }
    } else if (dir == 2) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val - 1, y_val + 1);
        char temp2 = the_board->charAt(x_val, y_val + 1);
        char temp3 = the_board->charAt(x_val + 1, y_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val - 1, y_val + 1);
            setbox3(x_val, y_val + 1);
            setbox4(x_val + 1, y_val + 1);
        }
    } else if (dir == 3) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val - 1, y_val);
        char temp2 = the_board->charAt(x_val, y_val - 1);
        char temp3 = the_board->charAt(x_val, y_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val - 1, y_val);
            setbox3(x_val, y_val - 1);
            setbox4(x_val, y_val + 1);
        }
    } else if (dir == 4) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(x_val - 1, y_val);
        char temp2 = the_board->charAt(x_val + 1, y_val);
        char temp3 = the_board->charAt(x_val, y_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' ') {
            setbox2(x_val - 1, y_val);
            setbox3(x_val + 1, y_val);
            setbox4(x_val, y_val + 1);
        }
    }
}


