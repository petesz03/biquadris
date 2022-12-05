#include "graphicdisplay.h"
#include "board.h"
#include "player.h"
#include "window.h"
#include <iostream>
#include <string>
#include <vector>

GraphicDisplay::GraphicDisplay(Board* b1, Board* b2):
    DisplayObserver{}, b1{b1}, b2{b2} {
        Xwindow *win = new Xwindow{30*15,24*15};
        w = win;
	b1->attach(this);
	b2->attach(this);
    }

GraphicDisplay::~GraphicDisplay(){ 
	delete w; // w is heap allocated
	b1->detach(this);
	b2->detach(this);
}

void GraphicDisplay::setBlind(int player, bool blind){}

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
    else{
	    w->fillRectangle(x,y,multiplier, multiplier, Xwindow::White);
    }
}

void GraphicDisplay::notify(){
	Player* player1 = b1->owner;
	Player* player2 = b2->owner;

	// Define constants:
	int p1Level = player1->getLevel();
	int p2Level = player2->getLevel();
	int p1Score = player1->getScore();
	int p2Score = player2->getScore();

	int p2ColStart = 19; // player2's board is column 19 to 29.
	// Row 0 is player's name, 1 is Level, 2 is Score.
	int rowStart = 3; 
	
	// Initiating Board:
	w->drawString(0,12,"    Player 1");
	w->drawString(0,28,"    Level:     "+p1Level);
	w->drawString(0,43,"    Score:     "+p1Score);
	w->drawString(p2ColStart*15,12,"     Player 2");
	w->drawString(p2ColStart*15,28,"     Level:     "+p2Level);
	w->drawString(p2ColStart*15,43,"     Score:     "+p2Score);

	// Prints board:
	for (int row = 0; row < 18; row++){
		for (int b1col = 0; b1col < 11; b1col++){
			char pattern = b1->grid[row][b1col];
			placeTile(pattern, row + rowStart, b1col);
		}
		for (int b2col = 0; b2col < 11; b2col++){
			char pattern = b2->grid[row][b2col];
			placeTile(pattern, row + rowStart, b2col + p2ColStart);
		}
	}

	// Prints nextblock (if any):
	w->drawString(0,22*15 - 1,"     Next:");	
	w->drawString(p2ColStart*15,22*15 - 1, "     Next:");

	// Define constants:
	int nextRowStart = 22;
	int nextColStart = 0;
	Player* playerInPlay;
	Board* boardInPlay;
	char nextItem = ' ';

	// set boardInPlay and boardInPlay:
	if (player1->getMyTurn()){
		playerInPlay = player1;
		boardInPlay = b1;
	}
	else{
		playerInPlay = player2;
		boardInPlay = b2;
		nextColStart = p2ColStart;
	}

	// Set nextItem, keep ' ' if nextBlock is nullptr:
	if (boardInPlay->getNextBlock() != nullptr){
		nextItem = (boardInPlay->getNextBlock())->getItem();
	}
	
	// Place tiles accordingly:
	switch(nextItem){
		case 'I':
			placeTile(nextItem, nextRowStart+1, nextColStart);
			placeTile(nextItem, nextRowStart+1, nextColStart+1);
			placeTile(nextItem, nextRowStart+1, nextColStart+2);
			placeTile(nextItem, nextRowStart+1, nextColStart+3);
			break;
		case 'J':
			placeTile(nextItem, nextRowStart, nextColStart);
                        placeTile(nextItem, nextRowStart+1, nextColStart);
                        placeTile(nextItem, nextRowStart+1, nextColStart+1);
                        placeTile(nextItem, nextRowStart+1, nextColStart+2);
			break;
		case 'L':
			placeTile(nextItem, nextRowStart, nextColStart+2);
                        placeTile(nextItem, nextRowStart+1, nextColStart);
                        placeTile(nextItem, nextRowStart+1, nextColStart+1);
                        placeTile(nextItem, nextRowStart+1, nextColStart+2);
			break;
		case 'O':
			placeTile(nextItem, nextRowStart, nextColStart);
                        placeTile(nextItem, nextRowStart, nextColStart+1);
                        placeTile(nextItem, nextRowStart+1, nextColStart);
                        placeTile(nextItem, nextRowStart+1, nextColStart+1);
			break;
		case 'S':
			placeTile(nextItem, nextRowStart, nextColStart+1);
                        placeTile(nextItem, nextRowStart, nextColStart+2);
                        placeTile(nextItem, nextRowStart+1, nextColStart);
                        placeTile(nextItem, nextRowStart+1, nextColStart+1);
			break;
		case 'Z':
			placeTile(nextItem, nextRowStart, nextColStart);
                        placeTile(nextItem, nextRowStart, nextColStart+1);
                        placeTile(nextItem, nextRowStart+1, nextColStart+1);
                        placeTile(nextItem, nextRowStart+1, nextColStart+2);
			break;
		case 'T':
			placeTile(nextItem, nextRowStart, nextColStart);
                        placeTile(nextItem, nextRowStart, nextColStart+1);
                        placeTile(nextItem, nextRowStart, nextColStart+2);
                        placeTile(nextItem, nextRowStart+1, nextColStart+1);
			break;
		case ' ':
			break;
	}
}




/*
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

*/
