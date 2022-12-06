#include "level.h"

Level::Level(int level): level{level} {}

Level::~Level(){}

int Level::getLevel() {
    return level;
}