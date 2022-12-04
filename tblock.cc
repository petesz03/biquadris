#include <vector>
#include "tblock.h"

Tblock::Tblock(int heaviness, bool candown, int dir, Board* the_board):
    Block{'T', Posn{5,1}, Posn{4,1}, Posn{6,1}, Posn{5,2}, heaviness, candown, the_board}, dir{dir} {}


Tblock::~Tblock() {

}

void Tblock::clockwiseturn() {
    if (dir == 1) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        setbox2(x_val - 1, y_val);
        setbox3(x_val, y_val - 1);
        setbox4(x_val, y_val + 1);
    } else if (dir == 2) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        setbox2(x_val - 1, y_val + 1);
        setbox3(x_val, y_val + 1);
        setbox4(x_val + 1, y_val + 1);
    } else if (dir == 3) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        setbox2(x_val - 1, y_val - 1);
        setbox3(x_val - 1, y_val + 1);
        setbox4(x_val - 1, y_val);
    } else if (dir == 4) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        setbox2(x_val - 1, y_val);
        setbox3(x_val + 1, y_val);
        setbox4(x_val, y_val + 1);
    }
}

void Tblock::counterturn() {
    if (dir == 1) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        setbox2(x_val - 1, y_val - 1);
        setbox3(x_val - 1, y_val + 1);
        setbox4(x_val - 1, y_val);
    } else if (dir == 2) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        setbox2(x_val - 1, y_val + 1);
        setbox3(x_val, y_val + 1);
        setbox4(x_val + 1, y_val + 1);
    } else if (dir == 3) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        setbox2(x_val - 1, y_val);
        setbox3(x_val, y_val - 1);
        setbox4(x_val, y_val + 1);
    } else if (dir == 4) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        setbox2(x_val - 1, y_val);
        setbox3(x_val + 1, y_val);
        setbox4(x_val, y_val + 1);
    }
}


