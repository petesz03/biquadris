#include "board.h"
#include <vector>
#include "subject.h"
#include "displayobserver.h"
#include "level.h"
#include <iostream>
#include "posn.h"
 
Board::Board(std::shared_ptr<Player> owner1, std::shared_ptr<Level> owners_level1):
    currentBlock{nullptr},
    nextBlock{nullptr},
    rowsCleared{0},
    dropCounter{0},
    owner{nullptr},
    owners_level{owners_level1}, 
    isheavy{false},
    isblind{false},
    isforce{false}{
    owner = owner1.get();
    currentBlock = createBlock();
    nextBlock = createBlock();
    attach(currentBlock);
    render();
}

std::shared_ptr<Block> Board::createBlock() {
    std::shared_ptr<Block> newBlock;
    if (owner->getIsRandom()) {
        
        newBlock = owners_level->randomNextBlock(this);
    } else {

        newBlock = owners_level->fileNextBlock(this);
    }
    return newBlock;
}

// CLEARING THE BOARD CLEARS ALLLLLL THE BLOCKS (NOT THE PLAYER AND LEVEL):
Board::~Board(){
    // current block in blcoks, also deleted
    // Note that owner and owners_level should be deleted in player when it returns.
    // We cannot delete it twice.
}

void Board::checkfullrow(){
	int rowscleared = 0;
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
		rowscleared++;
            int score = (owner->getLevel() + 1) * (owner->getLevel() + 1);
            owner->updateScore(score);
       	}
       rowsCleared = rowscleared;	
    }
}

void Board::blind(){
	if (rowsCleared >= 2){
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

void Board::setRowsCleared(int rows){
	rowsCleared = rows;
}

int Board::getRowsCleared(){
	return rowsCleared;
}

void Board::unsetBlind(int pid){
	for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
		(*it)->setBlind(pid, false);
	}
}

// Add score additions in here somehow!!
void Board::clearRow(int row){
	dropCounter = 0;
    for (auto a : blocks) {
        if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {

        } else {
            if (a->box1.y == row) {
                a->box1.x = -1;
                a->box1.y = -1;
                if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {
                    int score = (a->level_when_create + 1) * (a->level_when_create + 1);
                    a->the_board->owner->updateScore(score);
                }
            }
            if (a->box2.y == row) {
                a->box2.x = -1;
                a->box2.y = -1;
                if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {
                    int score = (a->level_when_create + 1) * (a->level_when_create + 1);
                    a->the_board->owner->updateScore(score);
                }
            }
            if (a->box3.y == row) {
                a->box3.x = -1;
                a->box3.y = -1;
                if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {
                    int score = (a->level_when_create + 1) * (a->level_when_create + 1);
                    a->the_board->owner->updateScore(score);
                }
            }
            if (a->box4.y == row) {
                a->box4.x = -1;
                a->box4.y = -1;
                if (a->box1.x == -1 && a->box2.x == -1 && a->box3.x == -1 && a->box4.x == -1) {
                    int score = (a->level_when_create + 1) * (a->level_when_create + 1);
                    a->the_board->owner->updateScore(score);
                }
            }
            
        }
    }

    for (int i = 0; i < 11; i++) {
	    // Add score for punish blocks:
	    if (grid[row][i] == '*'){
		    owner->updateScore(25);
	    }
	    grid[row][i] = ' ';
    }
    for (int i = row; i > 0; i--) {
        for (int a = 0; a < 11; a++) {
            grid[i][a] = grid[i - 1][a];
        }
    }


}

char Board::charAt(int row, int col){
   return grid[row][col];
}

std::shared_ptr<Block> Board::getCurrentBlock() {
    return currentBlock;
}
std::shared_ptr<Block> Board::getNextBlock(){
    return nextBlock;
}

void Board::setCurrent(std::shared_ptr<Block> newBlock){
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
	dropCounter++;
	// Create new blocks:
	currentBlock = nextBlock;
	nextBlock = createBlock();
    attach(currentBlock);
    if (dropCounter >= 5){
	    punish();
	    dropCounter = 0;
    }
}

void Board::punish(){
	int level = owner->getLevel();
	if (level == 4){
		int centralCol = 5;
		for (int row = 4; row < 18; row++){
			if (grid[row][centralCol] != ' '){
				grid[row-1][centralCol] = '*';
				return;
			}
		}
	}
}

void Board::clockwiseTurn(){ currentBlock->clockwiseturn();}

void Board::counterClockwiseTurn(){ currentBlock->counterturn(); }

void Board::setPlayer(std::shared_ptr<Player> newPlayer){
    Player* temp = newPlayer.get();
	owner = temp;
}

void Board::setLevel(std::shared_ptr<Level> newLevel){
	owners_level = newLevel;
}

void Board::setNext(std::shared_ptr<Block> newBlock){
	nextBlock = newBlock;
}

bool Board::checkLose(){
	for (int i = 0; i <= 10; i++){
		if (charAt(i,2) != ' '){ return true; }
	}
	return false;
}

void Board::attach(std::shared_ptr<Block> newBlock){
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

void Board::detach(std::shared_ptr<Block> oldBlock){
	Posn boxA = oldBlock->box1;
	Posn boxB = oldBlock->box2;
	Posn boxC = oldBlock->box3;
	Posn boxD = oldBlock->box4;
	std::vector<Posn> posnVec = {boxA, boxB, boxC, boxD};

	for (auto it = posnVec.begin(); it != posnVec.end(); it++){
		grid[(*it).y][(*it).x] = ' ';
	}
}

void Board::attach(std::shared_ptr<DisplayObserver>  ob){
    displayobservers.emplace_back(ob);
}

void Board::detach(DisplayObserver* ob){
    for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
        if ((*it).get() == ob){
            displayobservers.erase(it);
            break;
        }
    }
}

