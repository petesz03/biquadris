#include "player.h"
#include "block.h"

Player::Player(
    int pid,
    int count = 0,
    int score = 0,
    int maxScore = 0,
    bool isOver = false
    int currLevel = 0,
    Level* myLevel,
    Board* myBoard,
    Block* currBlock,
    Block* nextBlock,
    Player* opponent,
    bool isSpecialAction = false): 
        pid{pid},
        count{0},
        score{0},
        maxScore{0},
        isOver{false},
        currLevel{0},
        myLevel{myLevel},
        myBoard{myBoard},
        currBlock{currBlock},
        nextBlock{nextBlock},
        opponent{opponent},
        isSpecialAction{false} {}

Player::~Player() {
    delete myLevel;
    delete myBoard;
    delete currBlock;
    delete nextBlock;
}

// pointer to the special action, specialAction class
SpecialAction* Player::specialAction() {

}

// retrieve player information
int Player::getPid() { return pid; }

int Player::getScore() { return score; }

int Player::getMaxScore() { return maxScore; }

int Player::getLevel() { return currLevel; }

int Player::getMyTurn() { return isMyTurn; }

// generate punish block if in level 4
Block* Player::level4punish() {

}

// methods to increase and decrease level
void Player::levelUp() {

}

void Player::levelDown() {

}

// method to restart the current game
void Player::restart() {

}

// method to perform speical action
void Player::doSpecialAction() {

}

// method to return the current score and update the max score
int Player::countScore() {

}
int Player::updateMaxScore() {
    if (score > maxScore){
        maxScore = score;
    }
}

// methods to perform moves to the current blocks
void Player::makeMoveLeft(Block& currBlock) {
    currBlock->moveLeft(*this);
    myBoard->render();
}
void Player::makeMoveRight(Block& currBlock) {
    currBlock->moveRight(*this);
    myBoard->render();
}
void Player::makeMoveDown(Block& currBlock, int heaviness) {
    currBlock->moveDown(*this);
    if (myBoard->checkColFull()) {
        isOver = true;
    }
    myBoard->render();
}
void Player::makeClockwiseTurn(Block& currBlock) {
    currBlock->clockwiseTurn(*this);
    myBoard->render();
}
void Player::makeCounterTurn(Block& currBlock) {
    currBlock->counterTurn(*this);
    myBoard->render();
}
void Player::makeDrop(Block& currBlock) {
    currBlock->drop();
    if (myBoard->checkColFull()) {
        isOver = true;
    }
    myBoard->render();
}


