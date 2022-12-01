#include "level.h"
#include "player.h"
#include "block.h"
#include "level0.h"
#include "board.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include <iostream>
#include <string>
#include <fstream>

class Block;

class BlockObserver;

int main(){

    /***** Setup *****/
    Level0* player1Level = new Level{};
    Board* player1Board = new Board{}; // Change depending on constructor of board.
    Player* player1 = new Player{1, player1Level, player1Board, nullptr};
    // Creating player1's text and graphic displays:
    TextDisplay* player1Graph = new TextDisplay{player1Board, player1};
    GraphicDisplay* player1Text = new GraphicDisplay{player1Board, player1};
    player1Board->attach(player1Graph);
    player1Board->attach(player1Text);

    Level0* player2Level = new Level{};
    Board* player2Board = new Board{}; // Change depending on constructor of board
    Player* player2 = new Player{2, player2Level, player2Board, player1};
    // Creating player2's text and graphic displays:
    TextDisplay* player2Graph = new TextDisplay{player2Board, player2};
    GraphicDisplay* player2Text = new GraphicDisplay{player2Board, player2};
    player2Board->attach(player2Graph);
    player2Board->attach(player2Text);

    // Since player1's opponent's pointer is nullptr, change the pointer:
    player1.setOpponent(player2);

    player1.setTurn(true);

    /***** Input *****/
    std::string command;
    std::string file;
    bool readFromFile = false;
    std::fstream commandfile;
    while (true){
        if (!readFromFile){
            if (std::cin >> command){}
            else{ break; }
        }
        else{
            if (commandfile >> command){}
            else{ break; }
        }
        // Set who is moving for future commands:
        Player* playerInPlay;
        Board* boardInPlay;
        if (player1.getMyTurn()){
            playerInPlay = player1;
            boardInPlay = player1Board;
        else{
            playerInPlay = player2;
            boardInPlay = player2Board;
        }


        // Read for input and call functions in playerInPlay:
        if (command == "left"){
            Block* currentBlock = boardInPlay->getCurrentBlock();
            playerInPlay->makeMoveLeft(*currentBlock);
        }
        else if (command == "right"){
            Block* currentBlock = boardInPlay->getCurrentBlock();
            playerInPlay->makeMoveRight(*currentBlock);
        }
        else if (command == "down"){
            Block* currentBlock = boardInPlay->getCurrentBlock();
            playerInPlay->makeMoveDown(*currentBlock);
        }
        else if (command == "clockwise"){
            Block* currentBlock = boardInPlay->getCurrentBlock();
            playerInPlay->makeClockwiseTurn(*currentBlock);
        }
        else if (command == "counterclockwise"){
            Block* currentBlock = boardInPlay->getCurrentBlock();
            playerInPlay->makeCounterTurn(*currentBlock);
        }
        else if (command == "drop"){
            Block* currentBlock = boardInPlay->getCurrentBlock();
            playerInPlay->makeDrop(*currentBlock);
        }
        else if (command == "levelup"){
            playerInPlay->levelUp();
        }
        else if (command == "leveldown"){
            playerInPlay->levelDown();
        }
        else if (command == "norandom"){
            // What does this mean?? 
        }
        else if (command == "random"){
            // What does this mean??
        }
        else if (command == "sequence"){
            std::string file;
            if (!readFromFile){ std::cin >> file; }
            else{
                // If we are currently already reading from a file,
                //   need to close it before before opening a new one:
                commandfile >> file;
                commandfile.close()}
            readFromFile = true;
            commandfile.open(file, std::fstream::in);
        }
        else if (command == "I"){
            Block* currentBlock = boardInPlay->getCurrentBlock();
            
        }

    }
    
}