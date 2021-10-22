#include "Simulation.h"
#include "Timeout.h"
#include "StartCPU.h"
Timeout::Timeout(int theT, process *theP, Simulation *si):theTime(theT),theProcess(theP) {sim = si;}
int Timeout::getTime() {return this->theTime;}
void Timeout::setTime(int append){theTime = theTime+append;}
void Timeout::handleEvent(){
    cout<< "Time   " << theTime << ": Process  " << theProcess->getID() << " times out (needs "<<theProcess->getCPU()->getFront()->getInt()<<" units more)."<<endl;

    process* p = dynamic_cast<process*>(sim->getCPU()->dequeue());
    p->setWait(theTime - p->getWait());
    Event* event = new StartCPU(theTime,p,sim);
    sim->getEvent()->insert(event);
    }

