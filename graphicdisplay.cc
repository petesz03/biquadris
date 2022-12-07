#include "graphicdisplay.h"
#include "board.h"
#include "player.h"
#include "window.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

GraphicDisplay::GraphicDisplay(std::shared_ptr<Board> b1, std::shared_ptr<Board> b2):
    DisplayObserver{}, b1{b1}, b2{b2} {
    std::shared_ptr<Xwindow> win = std::shared_ptr<Xwindow>(new Xwindow{30*15,24*15});
    w = std::shared_ptr<Xwindow>(win);
    std::shared_ptr<DisplayObserver> temp = std::shared_ptr<GraphicDisplay>(this);

	b1->attach(temp);
	b2->attach(temp);
    }

GraphicDisplay::~GraphicDisplay(){ 
	b1->detach(this);
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
    else if (pattern == '*'){
        w->fillRectangle(x, y, multiplier, multiplier, Xwindow::Brown);
    }
    else{
	    w->fillRectangle(x,y,multiplier, multiplier, Xwindow::White);
    }
}

void GraphicDisplay::notify(){
	Player* player1 = b1->owner;
	Player* player2 = b2->owner;

    // Row 0 is player's name, 1 is Level, 2 is Score. Player2's board is column 19 to 29.
	int rowStart = 3; 
	int p2ColStart = 19;
	
	// Initiating Board:
	w->drawString(0,12,"Player 1");
	w->drawString(p2ColStart*15,12,"Player 2");

    // clear level and score
    w->fillRectangle(0,15,15*6, 15*4, Xwindow::White);
    w->fillRectangle(p2ColStart*15,15,15*6, 15*4, Xwindow::White);

    // draw new level and score
    std::stringstream ss;
    ss << "Level:" << std::setw(5) << std::setfill(' ') << player1->getLevel();
	w->drawString(0,28,ss.str());
    ss.str(std::string());
    ss << "Score:" << std::setw(5) << std::setfill(' ') << player1->getScore();
	w->drawString(0,43,ss.str());
    ss.str(std::string());
    ss << "Level:" << std::setw(5) << std::setfill(' ') << player2->getLevel();
	w->drawString(p2ColStart*15,28,ss.str());
    ss.str(std::string());
    ss << "Score:" << std::setw(5) << std::setfill(' ') << player2->getScore();
	w->drawString(p2ColStart*15,43,ss.str());

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
	w->drawString(0,22*15 - 1,"Next:");	
	w->drawString(p2ColStart*15,22*15 - 1, "Next:");

	// Define constants:
	int nextRowStart = 22;
	int nextColStart = 0;
	std::shared_ptr<Board> boardInPlay;
	char nextItem = ' ';

	// set boardInPlay and boardInPlay:
	if (player1->getMyTurn()){
		boardInPlay = b1;
	}
	else{
		boardInPlay = b2;
		nextColStart = p2ColStart;
	}


	// Set nextItem, keep ' ' if nextBlock is nullptr:
	if (boardInPlay->getNextBlock() != nullptr){
		nextItem = (boardInPlay->getNextBlock())->getItem();
	}
	placeTile(' ', nextRowStart, nextColStart);
	placeTile(' ', nextRowStart, nextColStart+1);
	placeTile(' ', nextRowStart, nextColStart+2);
	placeTile(' ', nextRowStart, nextColStart+3);
	placeTile(' ', nextRowStart+1, nextColStart);
	placeTile(' ', nextRowStart+1, nextColStart+1);
	placeTile(' ', nextRowStart+1, nextColStart+2);
	placeTile(' ', nextRowStart+1, nextColStart+3);

	
    // clear level and score
    w->fillRectangle(0,nextRowStart*15,15*4, 15*2, Xwindow::White);
    w->fillRectangle(p2ColStart*15,nextRowStart*15,15*4, 15*2, Xwindow::White);

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

