#pragma once
#include "Event.h"
class Timeout: public Event {
private:
    int theTime;
    process* theProcess;
public:
    Timeout(int theTime, process *theProcess, Simulation* sim);
    void handleEvent();
    virtual int getTime();
    virtual void setTime(int append);

};



