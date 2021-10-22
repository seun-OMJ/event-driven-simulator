#pragma once
#include "Event.h"
class Exit : public Event{
private:
    int theTime;
    process* theProcess;
    Simulation* sim;
public:
    Exit(int theTime, process *theProcess, Simulation* sim);
    void handleEvent();
    virtual int getTime();
    virtual void setTime(int append);

};



