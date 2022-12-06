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
    // current block in blcoks, also deleted
    for (auto it = blocks.begin(); it != blocks.end(); it++){
        delete *it;
    }
    delete nextBlock;
    // Note that owner and owners_level should be deleted in player when it returns.
    // We cannot delete it twice.
}

void Board::checkfullrow(){
    // We need to check every row!
    for (int i = 3; i <= 17; i++){
        // board starts at row 3, ends at 17 (rows 0 - 3 is for showing currentblock)
        int rowscleared = 0;
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
		rowscleared++;
            int score = (owner->getLevel() + 1) * (owner->getLevel() + 1);
            owner->updateScore(score);
       	} 
	if (rowscleared >= 2){
	       if (owner->getPid() == 1){
		       for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
			       (*it)->setBlind(2, true);
		       }
	       }
	       else{
		       for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
                               (*it)->setBlind(1, true);
                       }
	       }
	}
    }
}

void Board::unsetBlind(int pid){
	for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
		(*it)->setBlind(pid, false);
	}
}

// Add score additions in here somehow!!
void Board::clearRow(int row){
    
    std::vector<Block*> temp;
    std::vector<Block*> to_delete;
    for (auto a : blocks) {
        if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {

        } else {
            if (a->box1.y == row) {
                a->box1.x = -1;
                a->box1.y = -1;
                if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {
                    int score = (a->level_when_create + 1) * (a->level_when_create + 1);
                    a->the_board->owner->updateScore(score);
                    to_delete.emplace_back(a);
                } else {
                    temp.emplace_back(a);
                }
            }
            if (a->box2.y == row) {
                a->box2.x = -1;
                a->box2.y = -1;
                if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {
                    int score = (a->level_when_create + 1) * (a->level_when_create + 1);
                    a->the_board->owner->updateScore(score);
                    to_delete.emplace_back(a);
                } else {
                    temp.emplace_back(a);
                }
            }
            if (a->box3.y == row) {
                a->box3.x = -1;
                a->box3.y = -1;
                if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {
                    int score = (a->level_when_create + 1) * (a->level_when_create + 1);
                    a->the_board->owner->updateScore(score);
                    to_delete.emplace_back(a);
                } else {
                    temp.emplace_back(a);
                }
            }
            if (a->box4.y == row) {
                a->box4.x = -1;
                a->box4.y = -1;
                if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {
                    int score = (a->level_when_create + 1) * (a->level_when_create + 1);
                    a->the_board->owner->updateScore(score);
                    to_delete.emplace_back(a);
                } else {
                    temp.emplace_back(a);
                }
            }
            
        }
    }
    blocks = temp;
    for (auto a : to_delete) {
        delete a;
    }
	
    for (int i = 0; i < 11; i++) {
        grid[row][i] = ' ';
    }
    for (int i = row; i > 0; i--) {
        for (int a = 0; a < 11; a++) {
            grid[i][a] = grid[i - 1][a];
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
		if (grid[(*it).y][(*it).x] != ' '){
			owner->setIsOver(true);
			return;
		}
	}
	for (auto it = posnVec.begin(); it != posnVec.end(); it++){
		grid[(*it).y][(*it).x] = item;
	}
	blocks.emplace_back(newBlock);
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

