#include "posn.h"
#include "graphicdisplay.h"
#include "board.h"
#include "player.h"
#include "window.h"
#include <iostream>
#include <string>

GraphicDisplay::GraphicDisplay(Board* subject, Player* control):
    subject{subject}, control{control} {
        Xwindow *win = new Xwindow{,25*10}

