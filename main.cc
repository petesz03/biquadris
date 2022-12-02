#include "level.h"
#include "player.h"
#include "block.h"
#include "board.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include <iostream>
#include <string>
#include <fstream>

class Block;

class Level0;
class Level1;
class Level2;
class Level3;
class Level4;

class BlockObserver;

// We currently do not support text.
int main(int argc, char** args){
    bool graphics = true;

    // The following two files are to replace level0's file:
    std::string filePlayer1 = "sequence1.txt"; 
    std::string filePlayer2 = "sequence2.txt";

    int levelInitiated = 0;

    for (int i = 1; i < argc; i++){
        std::string argument = args[i];
        if (argument == "-text"){ graphics = false;}
        else if (argument == "-scriptfile1"){
            i++;
            filePlayer1 = args[i];
        }
        else if (argument == "-scriptfile2"){
            i++;
            filePlayer2 = args[i];
        }else if (argument == "-startlevel"){
            i++;
            argument = args[i];
            levelInitiated = stoi(argument);
        }
    }
    
    /***** Setup *****/

    // Set up a level according to levelInitiated:
    Level* player1Level;
    Level* player2Level;

    if (levelInitiated == 0){
        player1Level = new Level0{filePlayer1};
        player2Level = new Level0{filePlayer2};
    }
    else if (levelInitiated == 1){
        player1Level = new Level1{};
        player2Level = new Level1{};
    }
    else if (levelInitiated == 2){
        player1Level = new Level2{};
        player2Level = new Level2{};
    }
    else if (levelInitiated == 3){
        player1Level = new Level3{};
        player1Level = new Level3{};
    }
    else if (levelInitiated == 4){
        player1Level = new Level4{};
        player2Level = new Level4{};
    }

    Board* player1Board = new Board{}; // Change depending on constructor of board.
    Player* player1 = new Player{1, player1Level, player1Board, nullptr, filePlayer1};
    
    Board* player2Board = new Board{}; // Change depending on constructor of board
    Player* player2 = new Player{2, player2Level, player2Board, player1, filePlayer2};

    // Creating player1's text displays:
    TextDisplay* player1Graph = new TextDisplay{player1Board, player1};
    player1Board->attach(player1Text);
    
    // Creating player2's text displays:
    TextDisplay* player2Graph = new TextDisplay{player2Board, player2};
    player2Board->attach(player2Text);
    
    // If the filePlayer fields are not empty, we have to replace level0's file:


    // Creating player1 and player2's text displays:
    if (graphics){
        GraphicDisplay* player1Text = new GraphicDisplay{player1Board, player1};
        player1Board->attach(player1Graph);
        GraphicDisplay* player2Text = new GraphicDisplay{player2Board, player2};
        player2Board->attach(player2Graph);
    }

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
            else{ std::cin >> command; }
        }
        // Set who is moving for future commands:
        Player* playerInPlay;
        Board* boardInPlay;
        if (player1.getMyTurn()){
            playerInPlay = player1;
            boardInPlay = player1Board;
        }
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

    /***** Section to free memory: *****/
    
}