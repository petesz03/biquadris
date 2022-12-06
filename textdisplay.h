#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "displayobserver.h"
#include "board.h"
#include <memory>

class TextDisplay: public DisplayObserver{
    std::shared_ptr<Board> b1;
    std::shared_ptr<Board> b2;
    
    public:
    TextDisplay(std::shared_ptr<Board> b1, std::shared_ptr<Board> b2);
    void notify() override;
    void setBlind(int player, bool blind);
    ~TextDisplay();
};

#endif
