#include "graphicdisplay.h"
#include "board.h"
#include "player.h"
#include "window.h"
#include <iostream>
#include <string>
#include <vector>

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
    int level = control->getLevel();
    int score = control->getScore();
    w->drawString(0,12,"    Level:   "+level);
    w->drawString(0,28,"    Score:   "+score);

   Block* currentBlock = subject->getCurrentBlock(); 

   std::vector<Posn> vec;
   char currentChar;

   if (currentBlock != nullptr){
	   currentChar = currentBlock->getItem();
	   vec = {currentBlock->box1, currentBlock->box2, currentBlock->box3, currentBlock->box4};
   }
    for (int i = 0; i <= 17; i++){
        for (int j = 0; j <= 10; j++){
            // row 0 on board is row 2 on display:
            char pattern;
	    bool printed = false;
	    for (auto it = vec.begin(); it != vec.end(); it++){
		    if ((*it).x == j && (*it).y == i){
		    	pattern = currentChar;
		    	printed = true;
		    }
	    }
	    if (!printed){ pattern = subject->charAt(i, j); }
            placeTile(pattern, i+2 , j);
        }
    }
    // If it is not our turn currently, we do not see extra blocks below "Next:"
    w->drawString(0,21*15-2, "           Next:");

    if (!control->getMyTurn()){
        return;
    }

    if (subject->getNextBlock() == nullptr){ return; }
    
    char nextChar = toupper((subject->getNextBlock())->getItem());
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
