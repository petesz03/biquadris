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
    std::cout << "Level:    " << (control->myLevel)->level << std::endl;
    std::cout << "Score:    " << (control->score) << std::endl;
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
    if (!control->turn){
        std::cout << std::endl << std::endl;
        return;
    }
    // Assuming we have nextblock as a pointer to the nextblock:
    // WE ALSO NEED getItem TO GET THE ITEM

    // Print according to nextblock's item:
    char nextchar = nextblock->getItem();
    if (nextchar == 'I'){ std::cout << std::endl << "IIII"; }
    else if (nextchar == 'J'){ std::cout << 'J' << std::endl << "JJJ"; }
    else if (nextchar == 'L'){ std::cout << "  L" << std::endl << "LLL"; }
    else if (nextchar == 'O'){ std::cout << "OO" << std::endl << "OO "; }
    else if (nextchar == 'S'){ std::cout << " SS" << std::endl << "SS "; }
    else if (nextchar == 'Z'){ std::cout << "ZZ" << std::endl << " ZZ"; }
    else if (nextchar == 'T'){ std::cout << "TTT" << std::endl << " T "; }
    std::cout << std::endl;
}