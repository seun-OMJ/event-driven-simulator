#pragma once
#include <string>
#include "ListItem.h"
#include <sstream>

class process;
class Simulation;
using namespace std;
class Event: public ListItem {
private:
    int eventTime;
    process *theProcess;
protected:
	Simulation *sim;

public:

	// constructor, with pointer to the process that is being handled, and the simulation.
	Event(int theTime, class process* theProcess, Simulation* sim);

    Event();

    // pure virtual method - to handle the current event when it is removed from the queue.
	virtual void handleEvent() = 0;

	// compareTo - used to order Events. 
	virtual int compareTo(ListItem *other);
	virtual int getTime();
	virtual void setTime(int append);


};// class Event
