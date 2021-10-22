
#include "process.h"
process::process(int ID) {
    id = ID;
    arrival = 0;
    waitTime = 0;
    exitTime = 0;
    io =new Queue;
    cpu =new Queue;

}
int process::getID() {return id;}
Queue* process::getCPU() {return cpu;}
Queue* process::getIO() {return io;}
int process:: getArrival(){return arrival;}
int process:: getWait(){return waitTime;}
int process:: getExit(){return exitTime;}
void process:: setWait(int value){ waitTime =value;}
void process::setExit(int value){ exitTime = value;}
void process::setArrival(int value) { arrival = value;}
int process::compareTo(ListItem *other) {return -1;}
