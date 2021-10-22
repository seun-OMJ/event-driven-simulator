#pragma once
#include "Event.h"
#include <iostream>
#include <sstream>
#include <string>
#include "startIO.h"
#include "Exit.h"
#include "StartCPU.h"
#include "Simulation.h"
#include "process.h"
class process;
class CompleteCPU: public Event {
private:
    int theTime;
    class process *theProcess;

public:
    CompleteCPU(int theTime, class process *theProcess, Simulation *sim);
    void handleEvent();
    virtual int getTime();
    virtual void setTime(int append);

};



