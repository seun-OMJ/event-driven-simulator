#pragma once
#include "Event.h"
#include <string>
#include <sstream>
#include "ListItem.h"

class process;
class Simulation;
class arrival:public Event {
private:
    int theTime;
    class process* theProcess;

public:
    arrival(int theTime, class process* theProcess,Simulation* sim);

    void handleEvent();
    virtual int getTime();
    virtual void setTime(int append);

};



