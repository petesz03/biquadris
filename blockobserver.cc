#include "subject.h"
#include "displayobserver.h"

void BlockObserver::rowRemove(int row) = 0;
void BlockObserver::rowIntFull() = 0;
bool BlockObserver::colFull(int col) = 0;