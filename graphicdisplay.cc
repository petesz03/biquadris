#include "graphicdisplay.h"
#include "board.h"
#include "player.h"
#include "window.h"
#include <iostream>
#include <string>

GraphicDisplay::GraphicDisplay(Board* subject, Player* control):
    subject{subject}, control{control} {
        Xwindow *win = new Xwindow{11*15,23*15};
        w = win;
        subject->attach(this);
    }

GraphicDisplay::~GraphicDisplay(){
    delete w; // w is heap allocated
}

// Create helper fn that prints according to the character:
void GraphicDisplay::placeTile(char pattern, int row, int col){
    int multiplier = 15; // Each block is 15*15

    // Row 0 is row 3 on the graphic display.
    // x and y are the coordinates on the board:
    int y = row*15;
    int x = col*15;

    // I block: color Black
    // J block: color Red
    // L block: color Green
    // O block: color Blue
    // S block: color Yellow
    // Z block: color Orange
    // T block: color Magenta

    if (pattern == 'I'){
        w->fillRectangle(x, y, multiplier, multiplier, Xwindow::Black);
    }
    else if (pattern == 'J'){
        w->fillRectangle(x, y, multiplier, multiplier, Xwindow::Red);
    }
    else if (pattern == 'L'){
        w->fillRectangle(x, y, multiplier, multiplier, Xwindow::Green);
    }
    else if (pattern == 'O'){
        w->fillRectangle(x, y, multiplier, multiplier, Xwindow::Blue);
    }
    else if (pattern == 'S'){
        w->fillRectangle(x, y, multiplier, multiplier, Xwindow::Yellow);
    }
    else if (pattern == 'Z'){
        w->fillRectangle(x, y, multiplier, multiplier, Xwindow::Orange);
    }
    else if (pattern == 'T'){
        w->fillRectangle(x, y, multiplier, multiplier, Xwindow::Magenta);
    }
    else{ return; }
}

void GraphicDisplay::notify(){
    int level = (control->getLevel())->level;
    int score = (control->getScore());
    w.drawString(0,12,"    Level:   "+level);
    w.drawString(0,28,"    Score:   "+score);
    for (int i = 0; i <= 17; i++){
        for (int j = 0; j <= 10; j++){
            // row 0 on board is row 2 on display:
            char pattern = subject->charAt(i+2, j);
            placeTile(pattern, i, j);
        }
    }
    // If it is not our term currently, we do not see extra blocks below "Next:"
    if (!control->turn){
        std::cout << std::endl << std::endl;
        return;
    }
    
    char nextChar = (subject->getNextBlock())->getItem();
    int nextBlockStart = 21; // Row that nextblock starts at.
    
    // Prints next block on the bottom:
    // Must hard code since charAt will not call onto the next:
    if (nextChar == 'I'){
        placeTile(nextChar, nextBlockStart+1, 0);
        placeTile(nextChar, nextBlockStart+1, 1);
        placeTile(nextChar, nextBlockStart+1, 2);
        placeTile(nextChar, nextBlockStart+1, 3);
    }
    else if (nextChar == 'J'){
        placeTile(nextChar, nextBlockStart, 0);
        placeTile(nextChar, nextBlockStart+1, 0);
        placeTile(nextChar, nextBlockStart+1, 1);
        placeTile(nextChar, nextBlockStart+1, 2);
    }
    else if (nextChar == 'L'){
        placeTile(nextChar, nextBlockStart, 2);
        placeTile(nextChar, nextBlockStart+1, 0);
        placeTile(nextChar, nextBlockStart+1, 1);
        placeTile(nextChar, nextBlockStart+1, 2);
    }
    else if (nextChar == 'O'){
        placeTile(nextChar, nextBlockStart, 0);
        placeTile(nextChar, nextBlockStart, 1);
        placeTile(nextChar, nextBlockStart+1, 0);
        placeTile(nextChar, nextBlockStart+1, 1);
    }
    else if (nextChar == 'S'){
        placeTile(nextChar, nextBlockStart, 1);
        placeTile(nextChar, nextBlockStart, 2);
        placeTile(nextChar, nextBlockStart+1, 0);
        placeTile(nextChar, nextBlockStart+1, 1);
    }
    else if (nextChar == 'Z'){
        placeTile(nextChar, nextBlockStart, 0);
        placeTile(nextChar, nextBlockStart, 1);
        placeTile(nextChar, nextBlockStart+1, 1);
        placeTile(nextChar, nextBlockStart+1, 2);
    }
    else if (nextChar == 'T'){
        placeTile(nextChar, nextBlockStart, 0);
        placeTile(nextChar, nextBlockStart, 1);
        placeTile(nextChar, nextBlockStart, 2);
        placeTile(nextChar, nextBlockStart+1, 1);
    }
}
