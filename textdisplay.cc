#include "textdisplay.h"
#include "board.h"
#include "displayobserver.h"
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
            std::cout << (subject->getCurrentBlock(i,j))->pattern;
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << std::endl;
    std::cout <<"Next:" << std::endl;
    // How does this blockCreator work??
    // Need to somehow get the position vectors in the block. Private?
    Block* nextBlock(...)
}