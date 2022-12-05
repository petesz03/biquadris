#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "displayobserver.h"
#include "board.h"

class TextDisplay: public DisplayObserver{
    Board* b1;
    Board* b2;
    
    public:
    TextDisplay(Board* b1, Board* b2);
    void notify() override;
    void setBlind(int player, bool blind);
    ~TextDisplay();
};

#endif
