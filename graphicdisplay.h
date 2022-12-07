#ifndef _GRAPHICDISPLAY_H_
#define _GRAPHICDISPLAY_H_
#include "displayobserver.h"
#include "window.h"
#include <memory>

class Board;
class Player;

class GraphicDisplay: public DisplayObserver{
	std::shared_ptr<Board> b1;
	std::shared_ptr<Board> b2;
	std::shared_ptr<Xwindow> w;

	public:
	GraphicDisplay(std::shared_ptr<Board> b1, std::shared_ptr<Board> b2);
	void notify() override;
	~GraphicDisplay();
	void setBlind(int player, bool blind);
	// placeTile:
	// Given a row, col and pattern, input it onto the board:
	void placeTile(char pattern, int row, int col);
};

#endif
