#include "level.h"
#include "player.h"
#include "block.h"
#include "board.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include <iostream>
#include <string>
#include <fstream>
#include "blockobserver.h"
#include "displayobserver.h"
#include "graphicdisplay.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "posn.h"
#include "sblock.h"
#include "subject.h"
#include "tblock.h"
#include "textdisplay.h"
#include "window.h"
#include "zblock.h"   

class BlockObserver;

// We currently do not support seed
int main(int argc, char** args){
    // Default is that we have a graphical display
    bool graphics = true;
    // The following two files are to replace level0's file:
    // The default is "sequencex.txt"
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
        }
	else if (argument == "-startlevel"){
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
        player2Level = new Level3{};
    }
    else{
        player1Level = new Level4{};
        player2Level = new Level4{};
    }
    
    /*** Don't touch: ***/
    Player* player1 = new Player{1, player1Level, nullptr, nullptr, filePlayer1};
    Board* player1Board = new Board{player1, player1Level};
    player1->setBoard(player1Board);
    Player* player2 = new Player{2, player2Level, nullptr, player1, filePlayer2};
    Board* player2Board = new Board{player2, player2Level}; // Change depending on constructor of board
    player2->setBoard(player2Board);
    /******/

    // Creating player1's text displays:
    TextDisplay* textDisplay = new TextDisplay{player1Board, player2Board};
    player1Board->attach(textDisplay);
    player2Board->attach(textDisplay);


    // If the filePlayer fields are not empty, we have to replace level0's file:


    // Creating player1 and player2's text displays:

    GraphicDisplay* player1Graphics = nullptr;
    GraphicDisplay* player2Graphics = nullptr;
    if (graphics){
        player1Graphics = new GraphicDisplay{player1Board, player1};
        player1Board->attach(player1Graphics);
        player2Graphics = new GraphicDisplay{player2Board, player2};
        player2Board->attach(player2Graphics);
    }


    player1Board->render();

    // Since player1's opponent's pointer is nullptr, change the pointer:
    player1->setOpponent(player2);

    player1->setTurn(true);
    player2->setTurn(false);
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
        if (player1->getMyTurn()){
            playerInPlay = player1;
            boardInPlay = player1->getBoard(); 
        }
        else{
            playerInPlay = player2;
            boardInPlay = player2->getBoard();
        }

        // Read for input and call functions in playerInPlay,
        //   WHILE checking for similar commands:

        // We check for similar commands that "command" matches to:
        int commandsMatched = 0;
        std::string commandToExecute = "";
        std::vector<std::string> listOfCommands = {"left", "right", "down", "clockwise",
            "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random",
            "sequence", "I", "J", "L", "restart"};
        
        // Check how many different types of command that "command" matches to:
        for (auto it = listOfCommands.begin(); it != listOfCommands.end(); it++){
            size_t matched = (*it).find(command);
            if (matched != std::string::npos){
                commandsMatched++;
                commandToExecute = (*it);
		
            }
        }
        // If "command" only matches to one command, execute that command:
        if (commandsMatched == 1){
            command = commandToExecute;
	    std::cout << "The command you entered is: " << command << std::endl;
        }

        if (command == "left"){
            playerInPlay->makeMoveLeft();
        }
        else if (command == "right"){
            playerInPlay->makeMoveRight();
        }
        else if (command == "down"){
            playerInPlay->makeMoveDown();
        }
        else if (command == "clockwise"){
            playerInPlay->makeClockwiseTurn();
        }
        else if (command == "counterclockwise"){
            playerInPlay->makeCounterTurn();
        }
        else if (command == "drop"){
            playerInPlay->makeDrop();
	    if (playerInPlay->getIsOver()){
		    (player1->getBoard())->render();
		    (player2->getBoard())->render();
		    return 0;
	    }
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
                commandfile.close();
                }
            readFromFile = true;
            commandfile.open(file, std::fstream::in);
        }
        else if (command == "I"){
            	Block* curBlock = boardInPlay->getCurrentBlock();
            	// Delete the old "currentBlock" in Board:
	    	delete curBlock;
	    	// Create new Block
	    	Block* newblock = new Iblock{boardInPlay};
	    	// Set currentBlock in Board
	    	boardInPlay->setCurrent(newblock); 
        }
	else if (command == "J"){                
		Block* curBlock = boardInPlay->getCurrentBlock();
		// Delete the old "currentBlock" in Board:
		delete curBlock;
		// Create new Block
		Block* newblock = new Jblock{boardInPlay};     
            	// Set currentBlock in Board                
		boardInPlay->setCurrent(newblock);
	    }
	else if (command == "L"){
		Block* curBlock = boardInPlay->getCurrentBlock();          
		// Delete the old "currentBlock" in Board:
            	delete curBlock;
            	// Create new Block
            	Block* newblock = new Lblock{boardInPlay};
            	// Set currentBlock in Board
            	boardInPlay->setCurrent(newblock);
        }
        else if (command == "restart"){
            player1->restart();
            player2->restart();
        }
	// Testing functions: (delete in end)
	else if (command == "newblock"){
		Block* newblock = new Iblock{};
	}
	else if (command == "render"){
		if (player1->getMyTurn()){ std::cout << "Player 1 moving" << std::endl; }
		else if (player2->getMyTurn()){ std::cout << "Player2 moving" << std::endl; }
		else{ std::cout << "What is going on" << std::endl; }
		(player1->getBoard())->render();
		(player2->getBoard())->render();
	}
		
    }

    /***** Free Memory: *****/
    // Deleting players will delete its corresponding level and board, which
    //   will delete all the attached blocks:
    delete player1;
    delete player2;

    // Must delete graphic observers since they are not deleted:
    delete textDisplay;
    if (graphics){
        delete player1Graphics;
        delete player2Graphics;
    }
}
