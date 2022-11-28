#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class BlockObserver;

class DisplayObserver;

class Subject{
    std::vector<DisplayObserver*> displayobservers;
    std::vector<BlockObserver*> blockobservers;
    public:
    void notifyObservers();
    void attach(DisplayObserver* ob);
    void attach(BlockObserver* ob);
    void detach(DiplayObserver* ob);
    void detach(DisplayObserver* ob);
    virtual ~Subject() = default;

}

#endif
