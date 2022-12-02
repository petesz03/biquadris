#ifndef _BLOCK_OBSERVER_H_
#define _BLOCK_OBSERVER_H_
class Subject;

class BlockObserver{
    public:
    void rowRemove(int row); // Block's clearRow should call this
    int rowIntFull();
    bool colFull(int col);
    virtual ~BlockObserver() = default;
};

#endif