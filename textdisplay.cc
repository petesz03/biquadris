#include "textdisplay.h"
#include "board.h"
#include "posn.h"
#include "player.h"
#include <iostream>
#include <string>
#include <vector>

TextDisplay::TextDisplay(Board* b1, Board* b2):
    b1{b1}, b2{b2} {
    b1->attach(this);
    b2->attach(this);
    }

TextDisplay::~TextDisplay(){
    b1->detach( this );
    b2->detach( this );
}

void TextDisplay::notify(){
    // Space have to change weith number of digits in score:
    // level and score
    std::cout << "Level:    " << b1->owner->getLevel() << "\t" << "Level:    " << b2->owner->getLevel() << std::endl;
    std::cout << "Score:    " << b1->owner->getScore() << "\t" << "Score:    " << b2->owner->getScore() << std::endl;

    // first divider
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << "\t";
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << std::endl;

    // print board
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            std::cout << b1->grid[i][j];
        }
        std::cout << "\t";
        for (int j = 0; j < 11; j++) {
            std::cout << b2->grid[i][j];
        }
        std::cout << std::endl;
    }

    // second divider
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << "\t";
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << std::endl;

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
