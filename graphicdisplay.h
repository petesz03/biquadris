#ifndef _GRAPHICDISPLAY_H_
#define _GRAPHICDISPLAY_H_
#include "displayobserver.h"
#include "board.h"
#include "window.h"

class GraphicDisplay: public DisplayObserver{
    Board* subject;
    Player* control;
    
    public:
    GraphicDisplay(Board* subject, Player* control);
    void notify() override;
    ~GraphicDisplay();
}