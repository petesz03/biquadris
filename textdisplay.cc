#include "textdisplay.h"
#include "board.h"
#include "posn.h"
#include "player.h"
#include <iostream>
#include <string>

TextDisplay::TextDisplay(Board* subject, Player* control):
    subject{subject}, control{control} {}

TextDisplay::~TextDisplay(){
    subject->detach( this );
}

void TextDisplay::notify(){
	std::cout << "we are here" << std::endl;
    // Space have to change weith number of digits in score:
    std::cout << "Level:    " << control->getLevel()<< std::endl;
    std::cout << "Score:    " << (control->getScore()) << std::endl;
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << std::endl;
    for (int i = 0; i <= 17; i++){
        for (int j = 0; j <= 10; j++){
            // i is row, j is column. Call the getCurrentBlock and get its pattern.
            std::cout << subject->charAt(i,j);
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << std::endl;
    std::cout <<"Next:" << std::endl;
    // If it is not our term currently, we do not see extra blocks below "Next:"
    if (!control->getMyTurn()){
        std::cout << std::endl << std::endl;
        return;
    }

    // Print according to nextblock's item:
    char nextChar = (subject->getNextBlock())->getItem();
    if (nextChar == 'I'){ std::cout << std::endl << "IIII"; }
    else if (nextChar == 'J'){ std::cout << 'J' << std::endl << "JJJ"; }
    else if (nextChar == 'L'){ std::cout << "  L" << std::endl << "LLL"; }
    else if (nextChar == 'O'){ std::cout << "OO" << std::endl << "OO "; }
    else if (nextChar == 'S'){ std::cout << " SS" << std::endl << "SS "; }
    else if (nextChar == 'Z'){ std::cout << "ZZ" << std::endl << " ZZ"; }
    else if (nextChar == 'T'){ std::cout << "TTT" << std::endl << " T "; }
    std::cout << std::endl;
}
