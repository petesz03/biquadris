#include "subject.h"
#include "displayobserver.h"
#include "block.h"
#include "posn.h"

Subject::Subject() {
    grid.resize(18);
    for (int i = 0; i < 18; i++) {
        grid[i].resize(11, ' ');
    }
}


void Subject::attach(DisplayObserver* ob){
    displayobservers.emplace_back(ob);
}

void Subject::detach(DisplayObserver* ob){
    for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
        if (*it == ob){
            displayobservers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers(){
    for (auto ob : displayobservers){
        ob->notify();
    }
}
