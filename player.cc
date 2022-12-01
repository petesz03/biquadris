#include "player.h"
#include "block.h"

Player::Player(
    int pid,
    int count = 0,
    int score = 0,
    int maxScore = 0,
    bool isOver = false,
    bool isMyTurn = false;
    int currLevel = 0,
    Level* myLevel,
    Board* myBoard,
    Block* currBlock,
    Block* nextBlock,
    Player* opponent,
    bool isBlind = false,
    bool isHeavy = false,
    bool isForce = false): 
        pid{pid},
        count{0},
        score{0},
        maxScore{0},
        isOver{false},
        isMyTurn{false},
        currLevel{0},
        myLevel{myLevel},
        myBoard{myBoard},
        currBlock{nullptr},
        nextBlock{nullptr},
        opponent{opponent},
        isBlind{false},
        isHeavy{false},
        isForce{false} {}

Player::~Player() {
    delete myLevel;
    delete myBoard;
    delete currBlock;
    delete nextBlock;
}

// pointer to the special action, specialAction class
SpecialAction* Player::specialAction() {

}

void Player::setOpponent(Player* opponent){ this->opponent = opponent; }

void Player::setTurn(bool turn){ isMyTurn = turn; }

// retrieve player information
int Player::getPid() { return pid; }

int Player::getScore() { return score; }

int Player::getMaxScore() { return maxScore; }

int Player::getLevel() { return currLevel; }

bool Player::getMyTurn() { return isMyTurn; }

bool Player::getIsOver() { return IsOver; }

// generate punish block if in level 4
Block* Player::level4punish() {
    // NEED TO KNOW THE IMPLEMENTATION OF THIS BLOCK
    // TO IMPLEMENT THIS METHOD
}

// methods to increase and decrease level
void Player::levelUp() {
    if (currLevel < 4) {
        delete myLevel;
        currLevel++;
        switch (currLevel)
        {
        case 1:
            myLevel = new Level1();
            break;
        case 2:
            myLevel = new Level2();
            break;
        case 3:
            myLevel = new Level3();
            break;
        case 4:
            myLevel = new Level4();
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
            myLevel = new Level0();
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
    myLevel = new Level0;
    delete myBoard;
    myBoard = new Board();
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
        opponent->setForce(blockType);
    }
}

void Player::setBlind() {
    isBlind = true;
    myBoard.isBlind = true;
}

void Player::setHeavy() {
    isHeavy = true;
    currBlock.heaviness = 2;
}

void Player::setCurrBlockchar blockType) {
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

void Player::unsetBlind() {
    isBlind = false;
}

void Player::unsetHeavy() {
    isHeavy = false;
}

void Player::unsetForce() {
    isForce = false;
}

// method to update the current score and the max score
int Player::updateScore(int n) {
    score += n;
    updateMaxScore();
}
int Player::updateMaxScore() {
    if (score > maxScore){
        maxScore = score;
    }
}

// methods to perform moves to the current blocks
void Player::makeMoveLeft(Block& currBlock) {
    if (isHeavy) {
        currBlock.heaviness = 2;
    }
    currBlock->moveLeft(*this);
    myBoard->render();
}

void Player::makeMoveRight(Block& currBlock) {
    if (isHeavy) {
        currBlock.heaviness = 2;
    }
    currBlock->moveRight(*this);
    myBoard->render();
}

void Player::makeMoveDown(Block& currBlock) {
    if (isHeavy) {
        currBlock.heaviness = 2;
    }
    currBlock->moveDown(*this);
    if (myBoard->checkColFull()) {
        isOver = true;
    }
    myBoard->render();
    if (myBoard->numRowFull > 0) {

    }
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
    int fullRow = myBoard->numRowFull;
    if ( fullRow > 0) {
        count = 0;
        myBoard->clearRow();
        updateScore(currLevel + fullRow);
    }
    
    unsetBlind();
    unsetHeavy();
    unsetForce();
}


