#include <vector>
#include "tblock.h"

Tblock::Tblock(Board* the_board, int heaviness, bool candown, int dir):
    Block{'T', Posn{5,2}, Posn{4,2}, Posn{6,2}, Posn{5,3}, heaviness, candown, the_board}, dir{dir} {}


Tblock::~Tblock() {

}

void Tblock::clockwiseturn() {
    the_board->grid[box1.y][box1.x] = ' ';
        the_board->grid[box2.y][box2.x] = ' ';
        the_board->grid[box3.y][box3.x] = ' ';
        the_board->grid[box4.y][box4.x] = ' ';
    if (dir == 1) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val, x_val - 1);
        char temp2 = the_board->charAt(y_val - 1, x_val);
        char temp3 = the_board->charAt(y_val + 1, x_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' '
        && inrange({x_val, y_val}, {x_val - 1, y_val}, {x_val, y_val - 1}, {x_val, y_val + 1})) {
            setbox2(x_val - 1, y_val);
            setbox3(x_val, y_val - 1);
            setbox4(x_val, y_val + 1);
        }
    } else if (dir == 2) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val + 1, x_val - 1);
        char temp2 = the_board->charAt(y_val + 1, x_val);
        char temp3 = the_board->charAt(y_val + 1, x_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' '
        && inrange({x_val, y_val}, {x_val - 1, y_val + 1}, {x_val, y_val + 1}, {x_val + 1, y_val + 1})) {
            setbox2(x_val - 1, y_val + 1);
            setbox3(x_val, y_val + 1);
            setbox4(x_val + 1, y_val + 1);
        }
    } else if (dir == 3) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val - 1, x_val - 1);
        char temp2 = the_board->charAt(y_val + 1, x_val - 1);
        char temp3 = the_board->charAt(y_val, x_val - 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' '
        && inrange({x_val, y_val}, {x_val - 1, y_val - 1}, {x_val - 1, y_val + 1}, {x_val - 1, y_val})) {
            setbox2(x_val - 1, y_val - 1);
            setbox3(x_val - 1, y_val + 1);
            setbox4(x_val - 1, y_val);
        }
    } else if (dir == 4) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val, x_val - 1);
        char temp2 = the_board->charAt(y_val, x_val);
        char temp3 = the_board->charAt(y_val + 1, x_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' '
        && inrange({x_val, y_val}, {x_val - 1, y_val}, {x_val + 1, y_val}, {x_val, y_val + 1})) {
            setbox2(x_val - 1, y_val);
            setbox3(x_val + 1, y_val);
            setbox4(x_val, y_val + 1);
        }
    }
    if (the_board->owners_level->getLevel() >= 3) {
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

void Tblock::counterturn() {
    the_board->grid[box1.y][box1.x] = ' ';
        the_board->grid[box2.y][box2.x] = ' ';
        the_board->grid[box3.y][box3.x] = ' ';
        the_board->grid[box4.y][box4.x] = ' ';
    if (dir == 1) {
        dir = 4;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val - 1, x_val - 1);
        char temp2 = the_board->charAt(y_val + 1, x_val - 1);
        char temp3 = the_board->charAt(y_val, x_val - 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' '
        && inrange({x_val, y_val}, {x_val - 1, y_val - 1}, {x_val - 1, y_val + 1}, {x_val - 1, y_val})) {
            setbox2(x_val - 1, y_val - 1);
            setbox3(x_val - 1, y_val + 1);
            setbox4(x_val - 1, y_val);
        }
    } else if (dir == 2) {
        dir = 1;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val + 1, x_val - 1);
        char temp2 = the_board->charAt(y_val + 1, x_val);
        char temp3 = the_board->charAt(y_val + 1, x_val + 1);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' '
        && inrange({x_val, y_val}, {x_val - 1, y_val + 1}, {x_val, y_val + 1}, {x_val + 1, y_val + 1})) {
            setbox2(x_val - 1, y_val + 1);
            setbox3(x_val, y_val + 1);
            setbox4(x_val + 1, y_val + 1);
        }
    } else if (dir == 3) {
        dir = 2;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val, x_val - 1);
        char temp2 = the_board->charAt(y_val - 1, x_val);
        char temp3 = the_board->charAt(y_val + 1, x_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' '
        && inrange({x_val, y_val}, {x_val - 1, y_val}, {x_val, y_val - 1}, {x_val, y_val + 1})) {
            setbox2(x_val - 1, y_val);
            setbox3(x_val, y_val - 1);
            setbox4(x_val, y_val + 1);
        }
    } else if (dir == 4) {
        dir = 3;
        int x_val = box1.x;
        int y_val = box1.y;
        char temp1 = the_board->charAt(y_val, x_val - 1);
        char temp2 = the_board->charAt(y_val, x_val + 1);
        char temp3 = the_board->charAt(y_val + 1, x_val);
        if (temp1 == ' ' && temp2 == ' ' && temp3 == ' '
        && inrange({x_val, y_val}, {x_val - 1, y_val}, {x_val + 1, y_val}, {x_val, y_val + 1})) {
            setbox2(x_val - 1, y_val);
            setbox3(x_val + 1, y_val);
            setbox4(x_val, y_val + 1);
        }
    }
    if (the_board->owners_level->getLevel() >= 3) {
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


