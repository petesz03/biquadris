#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Level;
class Board;
class SpecialAction;
class Block;

class Player {
    // the player's id, 1 or 2
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
    int currLevel;
    Level* myLevel;

    // pointer to my board, Board object
    Board* myBoard;

    // current and next Block objects for the player
    Block* currBlock;
    Block* nextBlock;

    // pointer to the opponent player, player Opponent
    Player* opponent;

    // whether special action is triggered
    bool isBlind = false;
    bool isHeavy = false;
    bool isForce = false;

    // pointer to the special action, specialAction class
    SpecialAction* specialAction;

    // Add file for input in level0:
    std::string fileForLevel0;

public:
    // ctor and dtor
    Player(
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
        bool isForce = false);
    ~Player();

    // function to change the status:
    void setOpponent(Player* opponent);
    void setTurn(bool turn);
    void setFileForLevel0(std::string file);

    // pointer to the special action, specialAction class
    SpecialAction* specialAction();

    // retrieve player information
    int getPid();
    int getScore();
    int getMaxScore();
    int getLevel();
    bool getMyTurn();
    bool getIsOver();
    std::string getFileForLevel0();


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

    // method to update the current score and the max score
    int updateScore(int n);
    int updateMaxScore();
    
    // methods to perform moves to the current blocks
    void makeMoveLeft(Block& currBlock);
    void makeMoveRight(Block& currBlock);
    void makeMoveDown(Block& currBlock);
    void makeClockwiseTurn(Block& currBlock);
    void makeCounterTurn(Block& currBlock);
    void makeDrop(Block& currBlock);

};


#endif
