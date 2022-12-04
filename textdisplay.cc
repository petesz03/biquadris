#include "textdisplay.h"
#include "board.h"
#include "posn.h"
#include "player.h"
#include <iostream>
#include <string>
#include <vector>

TextDisplay::TextDisplay(Board* subject, Player* control):
    subject{subject}, control{control} {}

TextDisplay::~TextDisplay(){
    subject->detach( this );
}

void TextDisplay::notify(){
    // Space have to change weith number of digits in score:
    std::cout << "Level:    " << control->getLevel()<< std::endl;
    std::cout << "Score:    " << (control->getScore()) << std::endl;
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << std::endl;

    Block* currentBlock = subject->getCurrentBlock();

    std::vector<Posn> vec;
    char currentChar = ' ';
  
    if (currentBlock != nullptr){
	currentChar = currentBlock->getItem();  
    	vec = {currentBlock->box1, currentBlock->box2, currentBlock->box3, currentBlock->box4};
    }
    for (int i = 0; i <= 17; i++){
        for (int j = 0; j <= 10; j++){
            // i is row, j is column. Call the getCurrentBlock and get its pattern
	    	bool printed = false;
		// This is to check if row and row is in currentBlock:
		for (auto it = vec.begin(); it != vec.end(); it++){
			if ((*it).x == j && (*it).y == i){
			       	std::cout << currentChar;
				printed = true;
			}
		}	
		if (!printed){ std::cout << subject->charAt(i,j); }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 11; ++i) std::cout << '-';
    std::cout << std::endl;
    std::cout <<"Next:" << std::endl;
    // If it is not our term currently, we do not see extra blocks below "Next:"
	    

    if (!(control->getMyTurn())){
        std::cout<< "Not my turn yet!"  << std::endl << std::endl;
        return;
    }
    if (subject->getNextBlock() == nullptr){
	    std::cout << "No more blocks!"  <<  std::endl << std::endl;
	    return;
    }

    // Print according to nextblock's item:
    char nextChar = (subject->getNextBlock())->getItem();
    if (toupper(nextChar) == 'I'){ std::cout << std::endl << "IIII"; }
    else if (toupper(nextChar) == 'J'){ std::cout << 'J' << std::endl << "JJJ"; }
    else if (toupper(nextChar) == 'L'){ std::cout << "  L" << std::endl << "LLL"; }
    else if (toupper(nextChar) == 'O'){ std::cout << "OO" << std::endl << "OO "; }
    else if (toupper(nextChar) == 'S'){ std::cout << " SS" << std::endl << "SS "; }
    else if (toupper(nextChar) == 'Z'){ std::cout << "ZZ" << std::endl << " ZZ"; }
    else if (toupper(nextChar) == 'T'){ std::cout << "TTT" << std::endl << " T "; }
    else{ std::cout << nextChar << std::endl; }
    std::cout << std::endl;
}
