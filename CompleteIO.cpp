#include "CompleteIO.h"
CompleteIO::CompleteIO(int theT,class process *theP, Simulation *si):theTime(theT),theProcess(theP) {
    sim = si;
}

int CompleteIO::getTime() {return this->theTime;}
void CompleteIO::setTime(int append){theTime = theTime+append;}
void CompleteIO::handleEvent(){
    theProcess->getIO()->dequeue();
    sim->setIOstate(false);

    if((!theProcess->getCPU()->isEmpty()) &&(sim->getCPU()->isEmpty())){
        cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" completes I/O burst. starts next cpu burst"<<endl;
        if(!sim->getIO()->isEmpty()&&sim->checkIO()==false){

            process* p = dynamic_cast<process*>(sim->getIO()->dequeue());
            p->setWait(theTime - p->getWait());
            Event* ev= new startIO(theTime,p,sim);
            sim->getEvent()->insert(ev); }
            Event* event = new StartCPU(theTime,theProcess,sim);
            sim->getEvent()->insert(event);

        }

    else if((!theProcess->getCPU()->isEmpty()) &&((!sim->getCPU()->isEmpty())&&sim->checkIO()==false)){
        cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" completes I/O burst. Queueing for CPU"<<endl;
        sim->getCPU()->enqueue(theProcess);
        if(!sim->getIO()->isEmpty()&&sim->checkIO()==false){
            process* p = dynamic_cast<process*>(sim->getIO()->dequeue());
            p->setWait(theTime - p->getWait());
            Event* ev= new startIO(theTime,p,sim);
            sim->getEvent()->insert(ev);
        }}

    else if(theProcess->getCPU()->isEmpty()&&theProcess->getIO()->isEmpty()){
        Event* event = new Exit(theTime,theProcess,sim);
        sim->getEvent()->insert(event);
        cout<<"Time   "<< theTime<<": Process  "<<theProcess->getID()<<" completes processes. Exit scheduled"<<endl;
        if(!sim->getIO()->isEmpty()&&sim->checkIO()==false){
            process* p = dynamic_cast<process*>(sim->getIO()->dequeue());
            p->setWait(theTime - p->getWait());
            Event* ev= new startIO(theTime,p,sim);
            sim->getEvent()->insert(ev);
        }
    }

  }

