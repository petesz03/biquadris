#include "board.h"
#include <vector>
#include "subject.h"


Board::Board(Player* owner, Level* owners_level):
    owner{owner}, owners_level{owners_level} {
    currentBlock = nullptr;
    nextBlock = nullptr;

    // This will initiate w.r.t to the constants initialized in level:
    isblind = false;
    isforce = false;
    isheavy = false;

}

Block* Board::createBlock() {
    if (owners_level->level == 1) {
        int value = rand() % 12;
        if (value == 0) {
            currentBlock = new Sblock{0, true, 1};
        } else if (value == 1) {
            currentBlock = new Zblock{0, true, 1};
        } else if (value == 2) {
            currentBlock = new Iblock{0, true, 1};
        } else if (value == 3) {
            currentBlock = new Iblock{0, true, 1};
        } else if (value == 4) {
            currentBlock = new Jblock{0, true, 1};
        } else if (value == 5) {
            currentBlock = new Jblock{0, true, 1};
        } else if (value == 6) {
            currentBlock = new Lblock{0, true, 1};
        } else if (value == 7) {
            currentBlock = new Lblock{0, true, 1};
        } else if (value == 8) {
            currentBlock = new Oblock{0, true, 1};
        } else if (value == 9) {
            currentBlock = new Oblock{0, true, 1};
        } else if (value == 10) {
            currentBlock = new Tblock{0, true, 1};
        } else if (value == 11) {
            currentBlock = new Tblock{0, true, 1};
        }
    }
    if (owners_level->level == 2) {
        int value = rand() % 7;
        if (value == 0) {
            currentBlock = new Iblock{0, true, 1};
        } else if (value == 1) {
            currentBlock = new Jblock{0, true, 1};
        } else if (value == 2) {
            currentBlock = new Lblock{0, true, 1};
        } else if (value == 3) {
            currentBlock = new Oblock{0, true, 1};
        } else if (value == 4) {
            currentBlock = new Sblock{0, true, 1};
        } else if (value == 5) {
            currentBlock = new Zblock{0, true, 1};
        } else if (value == 6) {
            currentBlock = new Tblock{0, true, 1};
        }
    }

    if (owners_level->level == 3) {
        int value = rand() % 9;
        if (value == 0) {
            currentBlock = new Sblock{0, true, 1};
        } else if (value == 1) {
            currentBlock = new Sblock{0, true, 1};
        } else if (value == 2) {
            currentBlock = new Zblock{0, true, 1};
        } else if (value == 3) {
            currentBlock = new Zblock{0, true, 1};
        } else if (value == 4) {
            currentBlock = new Iblock{0, true, 1};
        } else if (value == 5) {
            currentBlock = new Jblock{0, true, 1};
        } else if (value == 6) {
            currentBlock = new Lblock{0, true, 1};
        } else if (value == 7) {
            currentBlock = new Oblock{0, true, 1};
        } else if (value == 8) {
            currentBlock = new Tblock{0, true, 1};
        }
    }

    if (owners_level->level == 4) {
        int value = rand() % 9;
        if (value == 0) {
            currentBlock = new Sblock{0, true, 1};
        } else if (value == 1) {
            currentBlock = new Sblock{0, true, 1};
        } else if (value == 2) {
            currentBlock = new Zblock{0, true, 1};
        } else if (value == 3) {
            currentBlock = new Zblock{0, true, 1};
        } else if (value == 4) {
            currentBlock = new Iblock{0, true, 1};
        } else if (value == 5) {
            currentBlock = new Jblock{0, true, 1};
        } else if (value == 6) {
            currentBlock = new Lblock{0, true, 1};
        } else if (value == 7) {
            currentBlock = new Oblock{0, true, 1};
        } else if (value == 8) {
            currentBlock = new Tblock{0, true, 1};
        }
    }
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
            if (charAt(i,j) == ' '){
                // One block is empty inside row i:
                rowfull = false;
            }
        }
        if (rowfull){ clearRow(i); } // since row full, call clearRow on row i
    }
}

void Board::clearRow(int row){
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
    for (auto it = blocks.begin(); it != blocks.end(); it++){
        std::vector<Posn> vec{(*it)->box1, (*it)->box2, (*it)->box3, (*it)->box4};
        // iterate through all 4 Posns:
        for (auto vecIt = vec.begin(); vecIt != vec.end(); vecIt++){
            if ((vecIt)->x == col && (vecIt)->y == row){ return (*it)->getItem(); }
        }
    }
    return ' ';
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
		(*it)->notify;
	}
}

// Left, right, down, turn should bring in heaviness
void Board::moveLeft(){
	std::vector<Posn> vec = {currentBlock.box1, currentBlock.box2, currentBlock.box3, currentBlock.box4};
	// Set row1Index and row2Index to out of bounds boundaries:
	int row1Index = 20;
	int row2Index = 20;
	// Get row1Index and row2Index:
	for (auto it = vec.begin(); it != vec.end(); it++){
		if (row1Index == 20){ row1Index = (*it).y; }
		else if (row1Index != 20 && (*it).y != row1Index){
			row2Index == (*it).y;
			break;
		}
	}
	int row1Left = 20;
	int row2Left = 20;
	for (auto it = vec.begin(); it != vec.end(); it++){
		if ((*it).y == row1Index && (*it).x <= row1Left){ row1Left == (*it).x; }
		else if ((*it).y == row2Index && (*it).x <= row2Left){ row2Left == (*it).y; }
	}
	if (charAt(row1Index, row1Left - 1) == ' ' && charAt(row2Index, row2Left - 1) == ' '){
		currentBlock.moveLeft();
	}
}



/* Old:
Board::Board(Player* owner, Level* owners_level):
    owner{owner}, owners_level{owners_level} {
        isblind = false;
        isheavy = false;
        isforce = false;
        current = nullptr;
        max_height = 0;
        num_of_full = 0;
        start_action = false;

    }

Board::~Board() {
    
}


void Board::checkfullrow() {
    std::vector<int> v;
    for (auto a : row2) {
        if (a->box1.y == 0) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 0) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 0) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 0) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(0);
    }
    v.clear();
    for (auto a : row1) {
        if (a->box1.y == 1) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 1) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 1) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 1) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(1);
    }
    v.clear();
    for (auto a : row2) {
        if (a->box1.y == 2) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 2) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 2) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 2) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(2);
    }
    v.clear();
    for (auto a : row3) {
        if (a->box1.y == 3) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 3) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 3) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 3) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(3);
    }
    v.clear();
    for (auto a : row4) {
        if (a->box1.y == 4) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 4) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 4) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 4) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(4);
    }
    v.clear();
    for (auto a : row5) {
        if (a->box1.y == 5) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 5) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 5) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 5) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(5);
    }
    v.clear();
    for (auto a : row6) {
        if (a->box1.y == 6) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 6) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 6) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 6) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(6);
    }
    v.clear();
    for (auto a : row7) {
        if (a->box1.y == 7) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 7) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 7) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 7) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(7);
    }
    v.clear();
    for (auto a : row8) {
        if (a->box1.y == 8) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 8) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 8) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 8) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(8);
    }
    v.clear();
    for (auto a : row9) {
        if (a->box1.y == 9) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 9) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 9) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 9) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(9);
    }
    v.clear();
    for (auto a : row10) {
        if (a->box1.y == 10) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 10) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 10) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 10) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(10);
    }
    v.clear();
    for (auto a : row11) {
        if (a->box1.y == 11) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 11) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 11) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 11) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(11);
    }
    v.clear();
    for (auto a : row12) {
        if (a->box1.y == 12) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 12) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 12) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 12) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(12);
    }
    v.clear();
    for (auto a : row13) {
        if (a->box1.y == 13) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 13) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 13) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 13) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(13);
    }
    v.clear();
    for (auto a : row14) {
        if (a->box1.y == 14) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 14) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 14) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 14) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(14);
    }
    v.clear();
    for (auto a : row15) {
        if (a->box1.y == 15) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 15) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 15) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 15) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(15);
    }
    v.clear();
    for (auto a : row16) {
        if (a->box1.y == 16) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 16) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 16) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 16) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(16);
    }
    v.clear();
    for (auto a : row17) {
        if (a->box1.y == 17) {
            v.push_back(a->box1.x);
        }
        if (a->box2.y == 17) {
            v.push_back(a->box2.x);
        }
        if (a->box3.y == 17) {
            v.push_back(a->box3.x);
        }
        if (a->box4.y == 17) {
            v.push_back(a->box4.x);
        }
    }
    if (v.size() == 11) {
        to_free.push_back(17);
    }
    v.clear();
}


void Board::clearrow() {
    for (auto a : to_free) {
        if (a == 0) {
            for (auto b : row0) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 0);
                }
            }
        }
        if (a == 1) {
            for (auto b : row1) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 1);
                }
            }
        }
        if (a == 2) {
            for (auto b : row2) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 2);
                }
            }
        }
        if (a == 3) {
            for (auto b : row3) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 3);
                }
            }
        }
        if (a == 4) {
            for (auto b : row4) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 4);
                }
            }
        }
        if (a == 5) {
            for (auto b : row5) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 5);
                }
            }
        }
        if (a == 6) {
            for (auto b : row6) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 6);
                }
            }
        }
        if (a == 7) {
            for (auto b : row7) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 7);
                }
            }
        }
        if (a == 8) {
            for (auto b : row8) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 8);
                }
            }
        }
        if (a == 9) {
            for (auto b : row9) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 9);
                }
            }
        }
        if (a == 10) {
            for (auto b : row10) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 10);
                }
            }
        }
        if (a == 11) {
            for (auto b : row11) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 11);
                }
            }
        }
        if (a == 12) {
            for (auto b : row12) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 12);
                }
            }
        }
        if (a == 13) {
            for (auto b : row13) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 13);
                }
            }
        }
        if (a == 14) {
            for (auto b : row14) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 14);
                }
            }
        }
        if (a == 15) {
            for (auto b : row15) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 15);
                }
            }
        }
        if (a == 16) {
            for (auto b : row16) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 16);
                }
            }
        }
        if (a == 17) {
            for (auto b : row17) {
                for (int i = 0; i < 11; i++) {
                    b->clean(i, 17);
                }
            }
        }
    }
}


*/






