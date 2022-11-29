#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "displayobserver.h"
#include "board.h"

class TextDisplay: public DisplayObserver{
    Board* subject;
    Player* control;
    
    public:
    TextDisplay(Board* subject, Player* control);
    void notify() override;
    ~TextDisplay();
};

#endif