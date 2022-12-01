#include "subject.h"
#include "displayobserver.h"
#include "blockobserver.h"

subject(std::vector<DisplayObserver*> displayobservers,
            std::vector<BlockObserver*> blockobservers):
            displayobservers{displayobservers}, blockobservers{blockobservers}{}


void attach(DisplayObserver* ob){
    displayobservers.emplace_back(ob);
}
void attach(BlockObserver* ob){
    blockobservers.emplace_back(ob);
}
void detach(DisplayObserver* ob){
    for (auto it = displayobservers.begin(); it != displayobservers.end(); it++){
        if (*it == ob){
            displayobservers.erase(it);
            break;
        }
    }
}
void detach(BlockObserver* ob){
    for (auto it = blockobservers.begin(); it != blockobservers.end(); it++){
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