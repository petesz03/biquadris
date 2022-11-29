#include "posn.h"
#include "graphicdisplay.h"
#include "board.h"
#include "player.h"
#include "window.h"
#include <iostream>
#include <string>

GraphicDisplay::GraphicDisplay(Board* subject, Player* control):
    subject{subject}, control{control} {
        Xwindow *win = new Xwindow{11*10,25*10};
        w = win;
        subject->attach(this);
    }

GraphicDisplay::~GraphicDisplay(){
    delete w; // w is heap allocated
}

void GraphicDisplay::notify(){
    for 
}
        


