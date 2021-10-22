#pragma once
#include "Event.h"
#include <string>
#include "startIO.h"
#include "Exit.h"
#include "StartCPU.h"
#include "Simulation.h"
#include "process.h"
class CompleteIO: public Event{
private:
    int theTime;
    class process *theProcess;

public:
    CompleteIO(int theTime, process *theProcess, Simulation* sim);
    void printStatus();
    void handleEvent();
    virtual int getTime();
    virtual void setTime(int append);


};



