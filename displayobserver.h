#ifndef _DISPLAYOBSERVER_H_
#define _DISPLAYOBSERVER_H_
class Subject;

class DisplayObserver{
    public:
    virtual void notify() = 0;
    virtual ~Observer() = default;
};
#endif