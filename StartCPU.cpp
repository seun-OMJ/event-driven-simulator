#include <algorithm>
#include "StartCPU.h"
#include "process.h"
#include "Timeout.h"
#include "CompleteCPU.h"

StartCPU::StartCPU(int theT, process *theP, Simulation *si):theTime(theT),theProcess(theP){sim = si;}
std::ostringstream a;
std::string aa;
int StartCPU::getTime() {return this->theTime;}
void StartCPU::setTime(int append){theTime = theTime+append;}
void StartCPU::handleEvent() {

    if((!theProcess->getCPU()->isEmpty())&&(theProcess->getCPU()->getFront()->getInt() ) > (sim->getBurst())){
        cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" "
     "begins CPU burst (will time out; needs "<<theProcess->getCPU()->getFront()->getInt()<<" units in total)."<<endl;
        setTime(sim->getBurst());
        sim->getCPU()->enqueue(theProcess);
        theProcess->getCPU()->getFront()->setInt((theProcess->getCPU()->getFront()->getInt()) - (sim->getBurst()));
        Event* event = new Timeout(theTime,theProcess,sim);
        sim->getEvent()->insert(event);

    }
    else if((!theProcess->getCPU()->isEmpty())&&(theProcess->getCPU()->getFront()->getInt() ) <= (sim->getBurst())){
        cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" begins CPU burst (will complete all "<<theProcess->getCPU()->getFront()->getInt()<<" remaining unit)."<<endl;
        setTime(theProcess->getCPU()->getFront()->getInt());
        Event* event = new CompleteCPU(theTime,theProcess,sim);
        sim->getEvent()->insert(event);


    }

}
