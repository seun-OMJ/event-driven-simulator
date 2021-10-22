#pragma once
#include "Event.h"
class process;
class StartCPU: public Event {
private:
    int theTime;
    process* theProcess;
public:
    StartCPU(int theTime, process* theProcess, Simulation* sim);
    void handleEvent();
    virtual int getTime();
    virtual void setTime(int append);



};



