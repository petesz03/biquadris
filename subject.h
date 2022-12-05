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
    void attach(DisplayObserver* ob);
    void detach(DisplayObserver* ob);
    virtual ~Subject() = default;

};

#endif
