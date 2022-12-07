#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <memory>

class Level;
class Board;
class SpecialAction;
class Block;

class Player {

    // the player's id, 1 or 2
    bool israndom;
    int pid;

    // counter for how many blocks dropped without clearing one row
    int count;

    // current score and max score of the player
    int score;
    int maxScore;

    // whether the current game is ended for the player
    bool isOver;

    // whether currently is my turn
    bool isMyTurn;

    // current level number, and a pointer to the Level object
    std::shared_ptr<Level> myLevel;

    // pointer to my board, Board object
    std::shared_ptr<Board> myBoard;

    // pointer to the opponent player, player Opponent
    std::shared_ptr<Player> opponent;

    // whether special action is triggered


    // Add file for input in level0:
    std::string fileForLevel0;

public:
    // ctor and dtor
    Player(
        int pid,
        std::shared_ptr<Level> myLevel,
        std::shared_ptr<Board> myBoard,
        std::shared_ptr<Player> opponent,
	std::string fileForLevel0);
    ~Player();

    // function to change the status:
    void setOpponent(std::shared_ptr<Player> opponent);
    void setTurn(bool turn);
    void setFileForLevel0(std::string file);
    void setBoard(std::shared_ptr<Board> setBoard); // Only used during initiation
    void setIsOver(bool over);
    void setMaxScore(int n);
    
    // retrieve player information
    int getPid();
    int getScore();
    int getMaxScore();
    int getLevel();
    Level* getMyLevel();
    bool getMyTurn();
    bool getIsOver();
    bool getIsRandom();
    std::string getFileForLevel0();
    std::shared_ptr<Board> getBoard();


    // generate punish block if in level 4
    Block* level4punish();

    // methods to increase and decrease level
    void levelUp();
    void levelDown();
    void random();

    // method to restart the current game
    void restart();

    // method to perform special action
    void doSpecialAction(int type, char blockType);
    void setBlind();
    void setHeavy();
    void setForce(char blockType);
    void unsetBlind();
    void unsetHeavy();
    void unsetForce();
    void setIsRandom(bool random);


    // method to update the current score and the max score
    void updateScore(int n);
    void updateMaxScore();
    
    // methods to perform moves to the current blocks
    void makeMoveLeft();
    void makeMoveRight();
    void makeMoveDown();
    void makeClockwiseTurn();
    void makeCounterTurn();
    void makeDrop();

};


#endif
