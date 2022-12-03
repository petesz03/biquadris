#include "player.h"
#include "block.h"
#include "level.h"
#include "board.h"
#include <string>
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

Player::Player(
    int pid,
    Level* myLevel,
    Board* myBoard,
    Player* opponent,
    std::string fileForLevel0): 
        israndom{true},
        pid{pid},
        count{0},
        score{0},
        maxScore{0},
        isOver{false},
        isMyTurn{false},
        currLevel{0},
        myLevel{myLevel},
        myBoard{myBoard},
        opponent{opponent},
        fileForLevel0{fileForLevel0} {}

Player::~Player() {
    delete myLevel;
    delete myBoard;
}

void Player::setOpponent(Player* opponent){ this->opponent = opponent; }

void Player::setTurn(bool turn){ isMyTurn = turn; }

void Player::setFileForLevel0(std::string file){
    fileForLevel0 = file;
}

// retrieve player information
int Player::getPid() { return pid; }

int Player::getScore() { return score; }

int Player::getMaxScore() { return maxScore; }

int Player::getLevel() { return currLevel; }

bool Player::getMyTurn() { return isMyTurn; }

bool Player::getIsOver() { return isOver; }

std::string Player::getFileForLevel0(){ return fileForLevel0; };

// methods to increase and decrease level
void Player::levelUp() {
    if (currLevel < 4) {
        delete myLevel;
        currLevel++;
        switch (currLevel)
        {
        case 1:
            myLevel = new Level1{};
            break;
        case 2:
            myLevel = new Level2{};
            break;
        case 3:
            myLevel = new Level3{};
            break;
        case 4:
            myLevel = new Level4{};
            break;
        default:
            break;
        }
    }
}

void Player::levelDown() {
    if (currLevel > 0) {
        delete myLevel;
        currLevel--;
        switch (currLevel)
        {
        case 0:
            myLevel = new Level0(fileForLevel0);
            break;
        case 1:
            myLevel = new Level1();
            break;
        case 2:
            myLevel = new Level2();
            break;
        case 3:
            myLevel = new Level3();
            break;
        default:
            break;
        }
    }
}

// method to restart the current game
void Player::restart() {
    delete myLevel;
    currLevel = 0;
    myLevel = new Level0{fileForLevel0};
    delete myBoard;
    myBoard = new Board(this, myLevel);
    count = 0;
    score = 0;
}

// method to perform speical action
void Player::doSpecialAction(int type, char blockType) {
    // here used int type for special action type:
    // 1 is use Blind on opponent
    // 2 is use Heavy on opponent
    // 3 is use Force on opponent, is type = 3, use char blockType to set
    switch (type)
    {
    case 1:
        opponent->setBlind();
        break;
    case 2:
        opponent->setHeavy();
        break;
    case 3:
        // opponent->setForce(blockType);
	break;
    }
}

void Player::setBlind() {
    myBoard->isblind = true;
}

void Player::setHeavy() {
    myBoard->isheavy = true;
}

/*
void Player::setCurrBlockchar(char blockType) {
    isForce = true;
    delete currBlcok;
    
    switch (blockType) {
        case "I":
            currBlock = new IBlock();
            break;
        case "J":
            currBlock = new JBlock();
            break;
        case "L":
            currBlock = new LBlock();
            break;
        case "O":
            currBlock = new OBlock();
            break;
        case "S":
            currBlock = new SBlock();
            break;
        case "Z":
            currBlock = new ZBlock();
            break;
        case "T":
            currBlock = new TBlock();
            break;
        default:
            currBlock = new IBlock();
    }
}
*/

void Player::unsetBlind() {
    myBoard->isblind = false;
}

void Player::unsetHeavy() {
    myBoard->isheavy = false;
}

void Player::unsetForce() {
    myBoard->isforce = false;
}

// method to update the current score and the max score
void Player::updateScore(int n) {
    score += n;
    this->updateMaxScore();
}
void Player::updateMaxScore() {
    if (score > maxScore){
        maxScore = score;
    }
}

// methods to perform moves to the current blocks
void Player::makeMoveLeft() {
	myBoard->moveLeft();
	myBoard->render();
}

void Player::makeMoveRight() {
    myBoard->moveRight();
    myBoard->render();
}

void Player::makeMoveDown() {
    myBoard->moveDown();
    myBoard->render();
}

void Player::makeClockwiseTurn() {
    myBoard->currentBlock->clockwiseturn();
    myBoard->render();
}

void Player::makeCounterTurn() {
    myBoard->currentBlock->counterturn();
    myBoard->render();
}

void Player::makeDrop() {
    myBoard->drop();
    myBoard->render();
    
    unsetBlind();
    unsetHeavy();
    unsetForce();
    // Create new block:
    Block* newBlock = myBoard->createBlock();
    // Move next to current:
    myBoard->setCurrent(myBoard->getNextBlock());
    myBoard->attach(myBoard->getCurrentBlock());
    myBoard->setNext(newBlock);
    setTurn(false);
    opponent->setTurn(true);
}

// Only used upon initiation: !!!
void Player::setBoard(Board* newBoard){
	myBoard = newBoard;
}
