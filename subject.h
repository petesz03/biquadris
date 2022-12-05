#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class Block;

class DisplayObserver;

class Subject{
public:
    std::vector<DisplayObserver*> displayobservers;
    std::vector<Block*> blocks;
    std::vector<std::vector<char>> grid;
public:
    Subject();
    void notifyObservers();
    virtual void attach(DisplayObserver* ob);
    virtual void attach(Block* newBlock) = 0;
    virtual void detach(DisplayObserver* ob);
    virtual void detach(Block* newBlock) = 0;
    virtual ~Subject() = default;

};

#endif
