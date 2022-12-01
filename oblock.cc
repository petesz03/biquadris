#include <vector>
#include "oblock.h"

Oblock::Oblock(int heaviness = 0, bool candown = true, int dir = 1):
    Block{'O', Posn{4,2}, Posn{5,2}, Posn{4,1}, Posn{5,1}, heaviness, candown}, dir{dir} {}



Oblock::~Oblock() {

}

void Oblock::clockwiseturn() {

}

void Oblock::counterturn() {

}

