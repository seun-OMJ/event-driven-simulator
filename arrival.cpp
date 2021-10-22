
#include "arrival.h"
#include "Simulation.h"
#include "StartCPU.h"

arrival::arrival(int t, class process *theP, Simulation *si) : theTime(t),theProcess(theP){
    sim =si;
}
std::ostringstream oss;
std::string var;
int arrival::getTime() {return this->theTime;}
void arrival::setTime(int append){theTime = theTime+append;}
void arrival::handleEvent() {
    if(sim->getCPU()->isEmpty()){
        cout << "Time   " << theTime << ": Process  " << theProcess->getID() << " arrives in system: CPU is free(process begins execution)."<<endl;
        Event* event = new StartCPU(theTime,theProcess,sim);
        sim->getEvent()->insert(event);

    }
    else{
        sim->getCPU()->enqueue(theProcess);
    cout << "Time   " << theTime << ": Process  " << theProcess->getID() << " arrives in system: CPU is busy(process will be queued)."<<endl;
    }
    string l = sim->get((ifstream&)sim->getF());
    if(!l.empty()){
        process* p = sim->processLine(l);
        sim->getProQ()->enqueue(p);
        Event* e = new arrival(p->getArrival(),p,sim);
        sim->getEvent()->insert(e);
    }

}
