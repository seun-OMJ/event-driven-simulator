#include "CompleteCPU.h"
#include <sstream>
CompleteCPU::CompleteCPU(int theT, class process *theP, Simulation *si):theTime(theT), theProcess(theP) {
    sim = si;
}

int CompleteCPU::getTime() {return this->theTime;}
void CompleteCPU::setTime(int append){theTime = theTime+append;}
void CompleteCPU::handleEvent() {
    theProcess->getCPU()->dequeue();
    if(theProcess->getIO()->isEmpty()){
        cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" completes CPU process" <<endl;
        Event* event = new Exit(theTime,theProcess,sim);
        sim->getEvent()->insert(event);
    }
    else if((!theProcess->getIO()->isEmpty())&&(sim->checkIO()==false)){
        cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" completes CPU burst. next I/O started"<<endl;
        Event* event = new startIO(theTime,theProcess,sim);
        sim->getEvent()->insert(event);
    }
    else if((!theProcess->getIO()->isEmpty())&&(sim->checkIO()==true)){
        cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" completes CPU burst.queuing for I/O"<<endl;
        sim->getIO()->enqueue(theProcess);
    }

    if(!sim->getCPU()->isEmpty()) {

        process *p = dynamic_cast<process *>(sim->getCPU()->dequeue());
        p->setWait(theTime - p->getWait());
        Event* event2 = new StartCPU(theTime, p, sim);
        sim->getEvent()->insert(event2);
    }
    }

