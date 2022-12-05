#ifndef _DISPLAYOBSERVER_H_
#define _DISPLAYOBSERVER_H_

class Subject;

class DisplayObserver{
	public:
	bool p1Blind;
	bool p2Blind;
	DisplayObserver(): p1Blind{false}, p2Blind{false}{}
    virtual void notify() = 0;
    virtual ~DisplayObserver() = default;
    virtual void setBlind(int player, bool blind) = 0;
};
#endif
