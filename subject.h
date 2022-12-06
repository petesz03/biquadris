#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>

class Block;

class DisplayObserver;

class Subject{
public:
    std::vector<std::shared_ptr<DisplayObserver>> displayobservers;
    std::vector<std::shared_ptr<Block>> blocks;
    std::vector<std::vector<char>> grid;
public:
    Subject();
    void notifyObservers();
    virtual void attach(std::shared_ptr<DisplayObserver> ob);
    virtual void attach(std::shared_ptr<Block> newBlock) = 0;
    virtual void detach(DisplayObserver* ob);
    virtual void detach(std::shared_ptr<Block> newBlock) = 0;
    virtual ~Subject() = default;

};

#endif
