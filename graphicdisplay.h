#ifndef _GRAPHICDISPLAY_H_
#define _GRAPHICDISPLAY_H_
#include "displayobserver.h"
#include "board.h"
#include "window.h"

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
}