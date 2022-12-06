#include "textdisplay.h"
#include "board.h"
#include "posn.h"
#include "player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

TextDisplay::TextDisplay(Board* b1, Board* b2):
    DisplayObserver{}, b1{b1}, b2{b2}{
    b1->attach(this);
    b2->attach(this);
    }

TextDisplay::~TextDisplay(){
    b1->detach( this );
    b2->detach( this );
}

void TextDisplay::setBlind(int player, bool blind){
	if (player == 1){
		p1Blind = blind;
	}
	else if (player == 2){
		p2Blind = blind;
	}
}
void TextDisplay::notify(){
    // level
    std::cout << "Level:" << std::setw(5) << std::setfill(' ') << b1->owner->getLevel() << "\t";
    std::cout << "Level:" << std::setw(5) << std::setfill(' ') << b2->owner->getLevel() << std::endl;

    // score
    std::cout << "Score:" << std::setw(5) << std::setfill(' ') << b1->owner->getScore() << "\t";
    std::cout << "Score:" << std::setw(5) << std::setfill(' ') << b2->owner->getScore() << std::endl;

    // max score
    std::cout << "Max Score:" << std::string(5, ' ') << "\t";
    std::cout << "Max Score:" << std::string(5, ' ') << std::endl;
    std::cout << std::setw(11) << std::setfill(' ') << b1->owner->getMaxScore() << "\t";
    std::cout << std::setw(11) << std::setfill(' ') << b2->owner->getMaxScore() << std::endl;

    // first divider
    std::cout << std::string(11, '-') << "\t";
    std::cout << std::string(11, '-') << std::endl;

    // print board
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
		if (p1Blind && i <= 12 && i >= 3 && j <= 9 && j >= 3){
			std::cout << '?';
		}
		else{
			std::cout << b1->grid[i][j];
		}
        }
        std::cout << "\t";
        for (int j = 0; j < 11; j++) {
		if (p2Blind && i <= 12 && i >= 3 && j <= 9 && j >= 3){
			std::cout << '?';
		}
		else{
			std::cout << b2->grid[i][j];}
        }
        std::cout << std::endl;
    }

    // second divider
    // first divider
    std::cout << std::string(11, '-') << "\t";
    std::cout << std::string(11, '-') << std::endl;

    // next block
    std::cout << "Next:      " << "\t" << "Next:      " << std::endl;
    
    std::string next1, next2;
    char item = ' ';
    
    if (b1->owner->getMyTurn()){
	    if (b1->getNextBlock() != nullptr){
		    item = (b1->getNextBlock())->getItem();
	    }
    }
    else {
	    if (b2->getNextBlock() != nullptr){
		    item = (b2->getNextBlock())->getItem();
	    }
    }

    switch (item) {
        case 'I':
            next1 = "IIII";
            next2 = "    ";
            break;
        case 'J':
            next1 = "J   ";
            next2 = "JJJ ";
            break;
        case 'L':
            next1 = "  L ";
            next2 = "LLL ";
            break;
        case 'S':
            next1 = " SS ";
            next2 = "SS  ";
            break;
        case 'T':
            next1 = "TTT ";
            next2 = " T  ";
            break;
        case 'Z':
            next1 = "ZZ  ";
            next2 = " ZZ ";
            break;
        case 'O':
            next1 = "OO  ";
            next2 = "OO  ";
            break;
	case ' ':
	    next1 = "    ";
	    next2 = "    ";
	    break;
    }

    if (b1->owner->getMyTurn()){
        std::cout << next1 << std::endl;
        std::cout << next2 << std::endl;
    }
    else {
        std::cout << "           \t" << next1 << std::endl;
        std::cout << "           \t" << next2 << std::endl;
    }

    std::cout << std::endl;
}
