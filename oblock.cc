#include <vector>
#include "oblock.h"

Oblock::Oblock(std::shared_ptr<Board> the_board, int heaviness, bool candown, int dir):
    Block{'O', Posn{4,3}, Posn{5,3}, Posn{4,2}, Posn{5,2}, heaviness, candown, the_board}, dir{dir} {}



Oblock::~Oblock() {

}

void Oblock::clockwiseturn() {

}

void Oblock::counterturn() {

}

