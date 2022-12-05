#ifndef _GRAPHICDISPLAY_H_
#define _GRAPHICDISPLAY_H_
#include "displayobserver.h"
#include "window.h"

class Board;
class Player;

class GraphicDisplay: public DisplayObserver{
	Board* b1;
	Board* b2;
	Xwindow* w;

	public:
	GraphicDisplay(Board* b1, Board* b2);
	void notify() override;
	~GraphicDisplay();

	// placeTile:
	// Given a row, col and pattern, input it onto the board:
	void placeTile(char pattern, int row, int col);
};
/*
class GraphicDisplay: public DisplayObserver{
    Board* subject;
    Player* control;
    Xwindow* w;

    public:
    GraphicDisplay(Board* subject, Player* control);
    void notify() override;
    ~GraphicDisplay();
    
    // placeTile: 
    // Given a row, col, and pattern, input it onto the board:
    void placeTile(char pattern, int row, int col);
};
*/
#endif
