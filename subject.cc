#include "subject.h"
#include "displayobserver.h"
#include "block.h"

Subject::Subject():
            displayobservers{displayobservers}, blocks{blocks}{}


void Subject::attach(DisplayObserver* ob){
    displayobservers.emplace_back(ob);
}
void Subject::attach(Block* ob){
    blocks.emplace_back(ob);
}
void Subject::detach(DisplayObserver* ob){
    for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
        if (*it == ob){
            displayobservers.erase(it);
            break;
        }
    }
}
void Subject::detach(Block* ob){
    for (auto it = blocks.begin(); it != blocks.end(); it++){
        if (*it == ob){
            blocks.erase(it);
            break;
        }
    }
}
void Subject::notifyObservers(){
    for (auto ob : displayobservers){
        ob->notify();
    }
}