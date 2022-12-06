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
#include <memory>
#include <algorithm>

class BlockObserver;


void replaceBlock(std::shared_ptr<Player> player, std::string command){
	// Create the specified block            
	std::shared_ptr<Block> newblock = nullptr;
	Board*  boardInPlay = player->getBoard().get();

	if (command == "I"){                
		newblock = std::shared_ptr<Block>(new Iblock{ boardInPlay });            
	} else if (command == "J"){                
		newblock = std::shared_ptr<Block>(new Jblock{ boardInPlay });
	} else if (command == "L"){
		newblock = std::shared_ptr<Block>(new Lblock{ boardInPlay });
	} else if (command == "S"){
		newblock = std::shared_ptr<Block>(new Sblock{ boardInPlay });
	} else if (command == "Z"){
                newblock = std::shared_ptr<Block>(new Zblock{ boardInPlay });
	} else if (command == "T"){
                newblock = std::shared_ptr<Block>(new Tblock{ boardInPlay });            
	} else if (command == "O"){
                newblock = std::shared_ptr<Block>(new Oblock{ boardInPlay });
	}            
	std::shared_ptr<Block> curBlock = boardInPlay->getCurrentBlock();            
	boardInPlay->detach(curBlock);            
	// Set currentBlock in Board            
	boardInPlay->setCurrent(newblock);
	boardInPlay->attach(newblock);
}

// We currently do not support seed
int main(int argc, char** args) {
    // vector of commands
    std::vector<std::string> listOfCommands = {
        "left", "right", "down", "clockwise","counterclockwise", "drop", "levelup", "leveldown", 
        "norandom", "random","sequence", "I", "J", "L", "S", "Z", "T", "O", "restart", "list", "rename"
    };

    // set the given seed value
	srand((unsigned) time(NULL));
    // Default is that we have a graphical display
    bool graphics = true;
    // The following two files are to replace level0's file:
    // The default is "sequencex.txt"
    std::string filePlayer1 = "sequence1.txt";
    std::string filePlayer2 = "sequence2.txt";
    int levelInitiated = 0;
    for (int i = 1; i < argc; i++) {
        std::string argument = args[i];
        if (argument == "-text") { 
            graphics = false; 
        } else if (argument == "-seed") {
            i++;
            srand(atoi(args[i]));
        }
        else if (argument == "-scriptfile1") {
            i++;
            filePlayer1 = args[i];
        } else if (argument == "-scriptfile2") {
            i++;
            filePlayer2 = args[i];
        } else if (argument == "-startlevel") {
            i++;
            argument = args[i];
            levelInitiated = stoi(argument);
        }
    }
    /***** Setup *****/
    // Set up a level according to levelInitiated:
    std::shared_ptr<Level> player1Level;
    std::shared_ptr<Level> player2Level;

    if (levelInitiated == 0) {
        player1Level = std::shared_ptr<Level>(new Level0{ filePlayer1 });
        player2Level = std::shared_ptr<Level>(new Level0{ filePlayer2 });
    } else if (levelInitiated == 1) {
        player1Level = std::shared_ptr<Level>(new Level1{});
        player2Level = std::shared_ptr<Level>(new Level1{});
    } else if (levelInitiated == 2) {
        player1Level = std::shared_ptr<Level>(new Level2{});
        player2Level = std::shared_ptr<Level>(new Level2{});
    } else if (levelInitiated == 3) {
        player1Level = std::shared_ptr<Level>(new Level3{});
        player2Level = std::shared_ptr<Level>(new Level3{});
    } else {
        player1Level = std::shared_ptr<Level>(new Level4{});
        player2Level = std::shared_ptr<Level>(new Level4{});
    }

    /*** Don't touch: ***/
    std::shared_ptr<Player> player1 = std::shared_ptr<Player>(new Player{ 1, player1Level, nullptr, nullptr, filePlayer1 });
    std::shared_ptr<Board> player1Board = std::shared_ptr<Board>(new Board{ player1, player1Level });
    player1->setBoard(player1Board);
    std::shared_ptr<Player> player2 = std::shared_ptr<Player>(new Player{ 2, player2Level, nullptr, player1, filePlayer2 });
    std::shared_ptr<Board> player2Board = std::shared_ptr<Board>(new Board{ player2, player2Level }); // Change depending on constructor of board
    player2->setBoard(player2Board);
    /******/

    // Creating player1's text displays:
    std::shared_ptr<TextDisplay> textDisplay = std::shared_ptr<TextDisplay>(new TextDisplay{ player1Board, player2Board });


    // If the filePlayer fields are not empty, we have to replace level0's file:


    // Creating player1 and player2's text displays:

    std::shared_ptr<GraphicDisplay> graphicDisplay = nullptr;
    if (graphics) {
        graphicDisplay = std::shared_ptr<GraphicDisplay>(new GraphicDisplay{ player1Board, player2Board });
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
    while (true) {
        // Set who is moving for future commands:
        std::shared_ptr<Player> playerInPlay;
        std::shared_ptr<Board> boardInPlay;
        if (player1->getMyTurn()) {
            playerInPlay = player1;
            boardInPlay = player1->getBoard();
        } else {
            playerInPlay = player2;
            boardInPlay = player2->getBoard();
        }
        // If either's turn is finished, it is other's term	
        if (player1->getIsOver() && player2->getIsOver()) {
            break;
        } else if (player1->getIsOver()) {
            playerInPlay = player2;
            boardInPlay = player2->getBoard();
        } else if (player2->getIsOver()) {
            playerInPlay = player1;
            boardInPlay = player1->getBoard();
        }

        if (repetition == 0) {
            if (!readFromFile) {
                if (std::cin >> command) {} else { break; }
            } else {
                if (commandfile >> command) {} else { std::cin >> command; }
            }
            // Read for input and call functions in playerInPlay,
                //   WHILE checking for similar commands:

                // We check for similar commands that "command" matches to:
            int commandsMatched = 0;
            std::string commandToExecute = "";

            int commandDigit = 0;
            for (size_t i = 0; i <= command.size(); i++) {
                if (isdigit(command[i])) {
                    commandDigit++;
                } else { break; }
            }
            if (commandDigit == 0) {
                repetition = 1;
            } else {
                repetition = stoi(command.substr(0, commandDigit));
                command = command.substr(commandDigit, command.size() - 1);
            }
            // Check how many different types of command that "command" matches to:
            for (auto it = listOfCommands.begin(); it != listOfCommands.end(); it++) {
                if ((*it).rfind(command, 0) != std::string::npos) {
                    commandsMatched++;
                    commandToExecute = (*it);
                }
            }
            if (commandsMatched == 1) {
                command = commandToExecute;
            } else {
                std::cout << "Invalid Command" << std::endl;
                repetition = 0;
                continue;
            }
        }
        if (command == listOfCommands[0]) {
            playerInPlay->makeMoveLeft();
        } else if (command == listOfCommands[1]) {
            playerInPlay->makeMoveRight();
        } else if (command == listOfCommands[2]) {
            playerInPlay->makeMoveDown();
        } else if (command == listOfCommands[3]) {
            playerInPlay->makeClockwiseTurn();
        } else if (command == listOfCommands[4]) {
            playerInPlay->makeCounterTurn();
        } else if (command == listOfCommands[5]) {
            playerInPlay->makeDrop();
	    if (boardInPlay->getRowsCleared() >= 2){
		    std::cout << "Congratulation! Player " << playerInPlay->getPid() << ", you have a special action! Please type in Blind, Heavy, or Force (followed by a blockType)" << std::endl;
		    std::string specialAction = "";
		    std::cin >> specialAction;
		    if (specialAction == "Force" || specialAction == "force"){
			    std::string blockToDrop;
			    std::cin >> blockToDrop;
			    if (playerInPlay->getPid() == 1){
				    replaceBlock(player2, blockToDrop);
			    }
			    else{
				    replaceBlock(player1, blockToDrop);
			    }
		    }
		    else if (specialAction == "blind" || specialAction == "Blind"){
			    boardInPlay->blind();
		    } else if (specialAction == "heavy" || specialAction == "Heavy") {
                if (playerInPlay->getPid() == 1){
				    player2->getBoard()->isheavy = true;
                    std::cout << "main:" <<player2->getBoard()->isheavy << std::endl;
			    }
			    else{
				    player1->getBoard()->isheavy = true;
			    }
            }
	    }
	    boardInPlay->setRowsCleared(0);
        } else if (command == listOfCommands[6]) {
            playerInPlay->levelUp();
        } else if (command == listOfCommands[7]) {
            playerInPlay->levelDown();
        } else if (command == listOfCommands[8]) {
            playerInPlay->setIsRandom(false);
            std::string file;
            std::cin >> file;
            (playerInPlay->myLevel)->useFile(file);
        } else if (command == listOfCommands[9]) {
            playerInPlay->setIsRandom(true);
        } else if (command == listOfCommands[10]) {
            std::string file;
            if (!readFromFile) { std::cin >> file; } else {
                // If we are currently already reading from a file,
                //   need to close it before before opening a new one:
                commandfile >> file;
                commandfile.close();
            }
            readFromFile = true;
            commandfile.open(file, std::fstream::in);
        } else if (command == listOfCommands[11]) {
            // Delete displays, detach done in destructors

            // Get new boards for player1 and player2:
            player1->restart();
            player2->restart();

            // Build new displays, attach done in constructors:
            if (graphics) {
                graphicDisplay = std::shared_ptr<GraphicDisplay>(new GraphicDisplay{ player1->getBoard(), player2->getBoard() });
            }
            textDisplay = std::shared_ptr<TextDisplay>(new TextDisplay{ player1->getBoard(), player2->getBoard() });
        } else if (command == listOfCommands[12]) {
		    replaceBlock(playerInPlay, "I");
            // Create the specified block
            std::shared_ptr<Block> newblock = nullptr;
        } else if (command == listOfCommands[13]) {
		    replaceBlock(playerInPlay, "J");
            // Create the specified block
            std::shared_ptr<Block> newblock = nullptr;
        } else if (command == listOfCommands[14]) {
		    replaceBlock(playerInPlay, "L");
            // Create the specified block
            std::shared_ptr<Block> newblock = nullptr;
        } else if (command == listOfCommands[15]) {
		    replaceBlock(playerInPlay, "S");
            // Create the specified block
            std::shared_ptr<Block> newblock = nullptr;
        } else if (command == listOfCommands[16]) {
		    replaceBlock(playerInPlay, "Z");
            // Create the specified block
            std::shared_ptr<Block> newblock = nullptr;
        } else if (command == listOfCommands[17]) {
		    replaceBlock(playerInPlay, "T");
            // Create the specified block
            std::shared_ptr<Block> newblock = nullptr;
        } else if (command == listOfCommands[18]) {
		    replaceBlock(playerInPlay, "O");
            // Create the specified block
            std::shared_ptr<Block> newblock = nullptr;
        } else if (command == listOfCommands[19]) {
            for (auto cmd: listOfCommands) {
                std::cout << cmd << " ";
            }
            std::cout << "\n" << std::endl;
        } else if (command == "rename") {
            std::string oldName, newName;
            std::cin >> oldName >> newName;
            auto it = std::find(listOfCommands.begin(), listOfCommands.end(), oldName);
            if (oldName != "rename" && it != listOfCommands.end() && std::find(listOfCommands.begin(), listOfCommands.end(), newName) == listOfCommands.end()){
                int index = it - listOfCommands.begin();
                listOfCommands[index] = newName;
            } else {
                std::cout << "Invalid Command" << std::endl;
                repetition = 0;
                continue;
            }
        }
        // Render
        (player1->getBoard())->render();

        repetition--;
    }
    int player1HighScore = player1->getMaxScore();
    int player2HighScore = player2->getMaxScore();
    std::cout << "Player 1's High Score is: " << player1HighScore << std::endl;
    std::cout << "Player 2's High Score is: " << player2HighScore << std::endl;
    if (player1HighScore > player2HighScore) {
        std::cout << "Player 1 win!" << std::endl;
    } else if (player2HighScore > player1HighScore) {
        std::cout << "Player 2 win!" << std::endl;
    } else {
        std::cout << "Tie!" << std::endl;
    }

    /***** Free Memory: *****/
    // Deleting players will delete its corresponding level and board, which
    //   will delete all the attached blocks:
    //delete player1;
    //delete player2;

    // Must delete graphic observers since they are not deleted:
    // delete textDisplay;
    // if (graphics){
       // delete graphicDisplay;
    //}
}
