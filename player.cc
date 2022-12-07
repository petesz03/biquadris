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
#include <iostream>
#include <memory>

Player::Player(
    int pid,
    std::shared_ptr<Level> myLevel,
    std::shared_ptr<Board> myBoard,
    std::shared_ptr<Player> opponent,
    std::string fileForLevel0): 
        israndom{true},
        pid{pid},
        count{0},
        score{0},
        maxScore{0},
        isOver{false},
        isMyTurn{false},
        myLevel{myLevel},
        myBoard{myBoard},
        opponent{opponent},
        fileForLevel0{fileForLevel0} {}

Player::~Player() {
}

void Player::setOpponent(std::shared_ptr<Player> opponent){ 
    this->opponent = opponent;
}

void Player::setTurn(bool turn){ isMyTurn = turn; }

void Player::setFileForLevel0(std::string file){
    fileForLevel0 = file;
}

// retrieve player information
int Player::getPid() { return pid; }

int Player::getScore() { return score; }

int Player::getMaxScore() { return maxScore; }

int Player::getLevel() { return myLevel->getLevel(); }

bool Player::getMyTurn() { return isMyTurn; }

bool Player::getIsOver() { return isOver; }

bool Player::getIsRandom(){ return israndom;}

std::string Player::getFileForLevel0(){ return fileForLevel0; };

Level* Player::getMyLevel(){
	return myLevel.get();
}

// methods to increase and decrease level
void Player::levelUp() {
    int currLevel = myLevel->getLevel();
    if (currLevel < 4) {
        currLevel++;
        switch (currLevel)
        {
        case 1:
            myLevel = std::shared_ptr<Level>(new Level1{});
            break;
        case 2:
            myLevel = std::shared_ptr<Level>(new Level2{});
            break;
        case 3:
            myLevel = std::shared_ptr<Level>(new Level3{});
            break;
        case 4:
            myLevel = std::shared_ptr<Level>(new Level4{});
            break;
        default:
            break;
        }
    }
    myBoard->owners_level = std::shared_ptr<Level>(myLevel);
}

void Player::levelDown() {
    int currLevel = myLevel->getLevel();
    if (currLevel > 0) {
        currLevel--;
        switch (currLevel)
        {
        case 0:
            myLevel = std::shared_ptr<Level>(new Level0(fileForLevel0));
            break;
        case 1:
            myLevel = std::shared_ptr<Level>(new Level1());
            break;
        case 2:
            myLevel = std::shared_ptr<Level>(new Level2());
            break;
        case 3:
            myLevel = std::shared_ptr<Level>(new Level3());
            break;
        default:
            break;
        }
    }
    myBoard->owners_level = std::shared_ptr<Level>(myLevel);
}

// method to restart the current game
void Player::restart() {
    myLevel = std::shared_ptr<Level>(new Level0{fileForLevel0});
    std::shared_ptr<Player> temp = std::shared_ptr<Player>(this);
    myBoard = std::shared_ptr<Board>(new Board(temp, myLevel));
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

void Player::setBlind() {}

void Player::setHeavy() {
    myBoard->isheavy = true;
}


void Player::unsetBlind() {
    myBoard->unsetBlind(pid);
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
}

void Player::makeMoveRight() {
    myBoard->moveRight();
}

void Player::makeMoveDown() {
    myBoard->moveDown();
}

void Player::makeClockwiseTurn() {
    myBoard->clockwiseTurn();
}

void Player::makeCounterTurn() {
    myBoard->counterClockwiseTurn();
}

void Player::makeDrop() {
    myBoard->drop();
    unsetBlind();
    unsetHeavy();
    unsetForce();
    // Blocks creation and row clearing is implemented in board
    //   for stylistic sense.
    setTurn(false);
    opponent->setTurn(true);
    if (myBoard->checkLose()){
	    std::cout << "player " << pid << "'s board is full" << std::endl;
	    isOver = true;
    }
}

// Only used upon initiation: !!!
void Player::setBoard(std::shared_ptr<Board> newBoard){
	myBoard = newBoard;
}

std::shared_ptr<Board> Player::getBoard(){
	return myBoard;
}

void Player::setIsOver(bool over){
	isOver = over;
}

void Player::setIsRandom(bool random){
	israndom = random;
}
