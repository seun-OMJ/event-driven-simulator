#pragma once
#include "Event.h"
class Simulation;
class process;
class startIO : public Event{
private:
    int theTime;
    process *theProcess;
public:
    startIO(int theTime, process *theProcess, Simulation* sim);
    void handleEvent();
    virtual int getTime();
    virtual void setTime(int append);


};



