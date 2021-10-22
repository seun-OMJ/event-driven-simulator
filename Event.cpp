#include "Event.h"
#include "arrival.h"
#include "Timeout.h"
#include "process.h"

/**** Event implementation */
Event::Event(int theTime, class process *theProcess, Simulation *theSim)
	 :eventTime(theTime), theProcess(theProcess), sim (theSim) {}


int Event::compareTo(ListItem *other){
    int result = 0;
    if((this->getTime()-other->getTime())>0){
        result =1;
    }
    if((this->getTime()-other->getTime())<0){
        result = -1;
    }
    if((this->getTime()-other->getTime())==0){
        if( dynamic_cast<arrival*>(other)){result = -1;}
        else if( dynamic_cast<arrival*>(this)){result = -1;}
        else if( dynamic_cast<Timeout*>(other)){result = 1;}
        else if( dynamic_cast<Timeout*>(this)){result = 1;}
        else{result = 1;}
    //    else if(this->getProcess()->getID()==dynamic_cast<Event*>(other)->getProcess()->getID()){result = 0;}
   //  else if(this->getProcess()->getID()>dynamic_cast<Event*>(other)->getProcess()->getID()){result = 1;}
     //   else if(this->getProcess()->getID()<dynamic_cast<Event*>(other)->getProcess()->getID()){result = -1;}


    }
	return result;

}
int Event::getTime() {return this->eventTime;}
void Event::setTime(int append){eventTime = eventTime+append;}



Event::Event() {}

