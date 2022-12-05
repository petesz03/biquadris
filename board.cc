#include "board.h"
#include <vector>
#include "subject.h"
#include "displayobserver.h"
#include "level.h"
#include <iostream>
#include "posn.h"

Board::Board(Player* owner, Level* owners_level):
    owner{owner}, owners_level{owners_level},
    isblind{false},
    isforce{false},
    isheavy{false} {
    currentBlock = createBlock();
    nextBlock = createBlock();
    attach(currentBlock);
    render();
}

Block* Board::createBlock() {
    Block* newBlock;

    if (owner->israndom) {

        newBlock = owners_level->randomNextBlock(this);
    } else {

        newBlock = owners_level->fileNextBlock(this);
    }
    return newBlock;
}

// CLEARING THE BOARD CLEARS ALLLLLL THE BLOCKS (NOT THE PLAYER AND LEVEL):
Board::~Board(){
    for (auto it = blocks.begin(); it != blocks.end(); it++){
        delete *it;
    }
    delete currentBlock;
    delete nextBlock;
    // Note that owner and owners_level should be deleted in player when it returns.
    // We cannot delete it twice.
}

void Board::checkfullrow(){
    // We need to check every row!
    for (int i = 3; i <= 17; i++){
        // board starts at row 3, ends at 17 (rows 0 - 3 is for showing currentblock)
        bool rowfull = true;
        for (int j = 0; j <= 10; j++){
            // board starts at col 0, ends at 10
            if (charAt(i, j) == ' '){
                // One block is empty inside row i:
                rowfull = false;
            }
        }
        if (rowfull){
	       	clearRow(i); 
            int score = (owner->getLevel() + 1) * (owner->getLevel() + 1);
            owner->updateScore(score);
       	} 
    }
}

// Add score additions in here somehow!!
void Board::clearRow(int row){
	std::cout << row << std::endl;
    for (int i = 0; i < 11; i++) {
        grid[row][i] = ' ';
    }
    for (int i = row; i > 0; i--) {
        for (int a = 0; a < 11; a++) {
            grid[i][a] = grid[i - 1][a];
        }
    }

///////////////////////////////////////////////////////////////////    
    for (auto it = blocks.begin(); it != blocks.end(); it++){
        Posn box1 = (*it)->box1;
        Posn box2 = (*it)->box2;
        Posn box3 = (*it)->box3;
        Posn box4 = (*it)->box4;
        std::vector<Posn> vec{box1, box2, box3, box4};
        // iterate through all 4 Posns:
        for (auto vecIt = vec.begin(); vecIt != vec.end(); vecIt++){
            if ((vecIt)->y == row){
                // This means that the position is in row.
                // Therefore, we must remove this by assigning it to -1, -1
                vecIt->x = -1;
                vecIt->y = -1;
            }
            else if ((vecIt)->y < row){
                // This means that the position is above row.
                // Since row is clearing, each block above will fall by one block:
                (vecIt->y)--;
            }
        }
        // Check this part!! Remove if needed:
        
        if (box1.x < 0 && box1.y < 0 && box2.x < 0 && box2.y < 0 && box3.x < 0 &&
        box3.y < 0 && box4.x < 0 && box4.y < 0){
            // This means that "it" is fully empty, we will remove it while we can
            //   to improve efficiency as the game progresses.
            auto temp = it;
            (*it)--; // SINCE WE ARE DELETING THIS CURRENT OBSERVER
            detach(*temp); // We have to detach temp first from the list of blockobs.
            delete *temp;
        }
    }
}

char Board::charAt(int row, int col){
    /*
    for (auto it = blocks.begin(); it != blocks.end(); it++){
        std::vector<Posn> vec{(*it)->box1, (*it)->box2, (*it)->box3, (*it)->box4};
        // iterate through all 4 Posns:
        for (auto vecIt = vec.begin(); vecIt != vec.end(); vecIt++){
            if ((vecIt)->x == col && (vecIt)->y == row){ return (*it)->getItem(); }
        }
    }
    return ' ';
    */
   return grid[row][col];
}

Block* Board::getCurrentBlock() {
    return currentBlock;
}
Block* Board::getNextBlock(){
    return nextBlock;
}

void Board::setCurrent(Block* newBlock){
    currentBlock = newBlock;
    return;
}
void Board::render(){
	for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
		(*it)->notify();
	}
}

void Board::moveLeft(){ currentBlock->moveleft(); }

void Board::moveRight(){ currentBlock->moveright(); }

void Board::moveDown(){ currentBlock->movedown(); }

void Board::drop(){
	// switching player's turn will be implemented in player
	//    for stylistic sense.
    	currentBlock->drop();
	// After dropped, check if any row is full and clear it.
	checkfullrow();

	// Create new blocks:
	currentBlock = nextBlock;
	nextBlock = createBlock();
    	attach(currentBlock);
}

void Board::clockwiseTurn(){ currentBlock->clockwiseturn();}

void Board::counterClockwiseTurn(){ currentBlock->counterturn(); }

void Board::setPlayer(Player* newPlayer){
	owner = newPlayer;
}

void Board::setLevel(Level* newLevel){
	owners_level = newLevel;
}

void Board::setNext(Block* newBlock){
	nextBlock = newBlock;
}

bool Board::checkLose(){
	for (int i = 0; i <= 10; i++){
		if (charAt(i,2) != ' '){ return true; }
	}
	return false;
}

void Board::attach(Block* newBlock){
	Posn boxA = newBlock->box1;
	Posn boxB = newBlock->box2;
	Posn boxC = newBlock->box3;
	Posn boxD = newBlock->box4;
	std::vector<Posn> posnVec = {boxA, boxB, boxC, boxD};
	char item = newBlock->getItem();

	for (auto it = posnVec.begin(); it != posnVec.end(); it++){
		grid[(*it).y][(*it).x] = item;
	}
}

void Board::detach(Block* oldBlock){
	Posn boxA = oldBlock->box1;
	Posn boxB = oldBlock->box2;
	Posn boxC = oldBlock->box3;
	Posn boxD = oldBlock->box4;
	std::vector<Posn> posnVec = {boxA, boxB, boxC, boxD};

	for (auto it = posnVec.begin(); it != posnVec.end(); it++){
		grid[(*it).y][(*it).x] = ' ';
	}
}

void Board::attach(DisplayObserver* ob){
    displayobservers.emplace_back(ob);
}

void Board::detach(DisplayObserver* ob){
    for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
        if (*it == ob){
            displayobservers.erase(it);
            break;
        }
    }
}

