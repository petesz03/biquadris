#include <vector>
#include "oblock.h"

Oblock::Oblock(Board* the_board, int heaviness, bool candown, int dir):
    Block{'O', Posn{4,2}, Posn{5,2}, Posn{4,1}, Posn{5,1}, heaviness, candown, the_board}, dir{dir} {}



Oblock::~Oblock() {

}

void Oblock::clockwiseturn() {

}

void Oblock::counterturn() {

}

