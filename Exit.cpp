
#include "Exit.h"
#include "Simulation.h"
Exit::Exit(int theT, process *theP, Simulation *si):theTime(theT),theProcess(theP){sim=si;}
int Exit::getTime() {return this->theTime;}
void Exit::setTime(int append){theTime = theTime+append;}
void Exit::handleEvent() {
    theProcess->setExit(theTime);
    cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" completed. no more bursts. exiting the system"<<endl;
}
