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


    // If the filePlayer fields are not empty, we have to replace level0's file:


    // Creating player1 and player2's text displays:

    GraphicDisplay* graphicDisplay = nullptr;
    if (graphics){
        graphicDisplay = new GraphicDisplay{player1Board, player2Board};
    }

    // Since player1's opponent's pointer is nullptr, change the pointer:
    player1->setOpponent(player2);

    player1->setTurn(true);
    player2->setTurn(false);
    player1Board->render();
    /***** Input *****/
    std::string command;
    std::string file;
    bool readFromFile = false;
    std::fstream commandfile;
    int repetition = 0;
    while (true){
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
	if (repetition == 0){
        	if (!readFromFile){
            		if (std::cin >> command){}
            		else{ return 0;}
        	}
        	else{
            		if (commandfile >> command){}
            		else{ std::cin >> command; }
		}
		// Read for input and call functions in playerInPlay,
        	//   WHILE checking for similar commands:

        	// We check for similar commands that "command" matches to:
        	int commandsMatched = 0;
        	std::string commandToExecute = "";

        	int commandDigit = 0;
        	for (size_t i = 0; i <= command.size(); i++){
        	        if (isdigit(command[i])){
                	        commandDigit++;
                	}
               		 else{ break; }
        	}
		if (commandDigit == 0){
			repetition = 1;
		}
		else{
			repetition = stoi(command.substr(0, commandDigit));
        		command = command.substr(commandDigit, command.size() - 1);	
		}
		std::vector<std::string> listOfCommands = {"left", "right", "down", "clockwise",            "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random",            "sequence", "I", "J", "L", "restart"};
		// Check how many different types of command that "command" matches to:
		for (auto it = listOfCommands.begin(); it != listOfCommands.end(); it++){            
			size_t matched = (*it).find(command);
			if (matched != std::string::npos){
				commandsMatched++;
				commandToExecute = (*it);
	    		}
		}
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
		boardInPlay->detach(curBlock);
            	// Delete the old "currentBlock" in Board:
	    	delete curBlock;
	    	// Create new Block
	    	Block* newblock = new Iblock{boardInPlay};
		boardInPlay->attach(curBlock);
	    	// Set currentBlock in Board
	    	boardInPlay->setCurrent(newblock); 
        }
	else if (command == "J"){                
		Block* curBlock = boardInPlay->getCurrentBlock();
		boardInPlay->detach(curBlock);
		// Delete the old "currentBlock" in Board:
		delete curBlock;
		// Create new Block
		Block* newblock = new Jblock{boardInPlay};	
            	boardInPlay->attach(curBlock);
		// Set currentBlock in Board                
		boardInPlay->setCurrent(newblock);
	    }
	else if (command == "L"){
		Block* curBlock = boardInPlay->getCurrentBlock();
		boardInPlay->detach(curBlock);
		// Delete the old "currentBlock" in Board:
            	delete curBlock;
            	// Create new Block
            	Block* newblock = new Lblock{boardInPlay};
		boardInPlay->attach(curBlock);
            	// Set currentBlock in Board
            	boardInPlay->setCurrent(newblock);
        }
        else if (command == "restart"){
		// Delete old displays in main to avoid
		//   multiple deletes of the same displays
		(player1->getBoard())->detach(graphicDisplay);
		(player1->getBoard())->detach(textDisplay);
		delete graphicDisplay;
		delete textDisplay;

		// Get new boards for player1 and player2:
		player1->restart();
		player2->restart();

		// Build new displays:
		GraphicDisplay* newGraphics = new GraphicDisplay{player1->getBoard(), player2->getBoard()};
		TextDisplay* newText = new TextDisplay{player1->getBoard(), player2->getBoard()};
		// Reassign the textDisplay and graphicDisplay
		textDisplay = newText;
		graphicDisplay = newGraphics;

		// Call the restart function to get new boards for player 1 and 2.

		// Attach the new displays:
		(player1->getBoard())->attach(newGraphics);
		(player2->getBoard())->attach(newGraphics);
		(player1->getBoard())->attach(newText);
		(player2->getBoard())->attach(newText);
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
	repetition--;
	boardInPlay->render();
		
    }

    /***** Free Memory: *****/
    // Deleting players will delete its corresponding level and board, which
    //   will delete all the attached blocks:
    delete player1;
    delete player2;

    // Must delete graphic observers since they are not deleted:
    delete textDisplay;
    if (graphics){
        delete graphicDisplay;
    }
}
