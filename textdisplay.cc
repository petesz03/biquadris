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
            std::cout << (subject->blockAt(i,j))->pattern;
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

    // If we have characters, then if statements
    // If we do not add characters, then following process:

    // How does this blockCreator work??
    // Need to somehow get the position vectors in the block. Private?
    Block* nextbl = subject->nextblock;
    std::vector<Posn> position = nextbl->returnlocation();
    // position should always have 4 elements since new block has 4, ALWAYS.
    int top = 18;
    int left = 12;
    for (auto it = position.begin(); it != observers.end(); it++){
        // If the iterator's x value is smaller than top, replace top:
        if (it.x <= top){ top == it.x; }
        // If the iterator's y value is smaller than left, replace left:
        if (it.y <= left){ left == it.y; }
    }
    // Program reaches here once top is the start of the topmost block and
    //   left is the start of the leftmost block.


}