#include "CompleteIO.h"
#include <sstream>
startIO::startIO(int theT, process* theP, Simulation* si) :theTime(theT),theProcess(theP){sim = si;}
int startIO::getTime() {return this->theTime;}
void startIO::setTime(int append){theTime = theTime+append;}
void startIO::handleEvent() {

    cout<< "Time   " << theTime << ": Process  " << theProcess->getID() << " begins I/O burst of length "<<theProcess->getIO()->getFront()->getInt()<<endl;
    setTime(theProcess->getIO()->getFront()->getInt());
    sim->setIOstate(true);
    Event* event = new CompleteIO(theTime,theProcess,sim);
    sim->getEvent()->insert(event);



}
