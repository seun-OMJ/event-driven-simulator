#pragma  once
#include "ListItem.h"
#include "Queue.h"
#include "burstHolder.h"
class process: public ListItem {
private:
    int arrival;
    int waitTime;
    int exitTime;
    int id;
    Queue* io;
    Queue* cpu;


public:
process(int id);
int getID();
Queue* getIO();
Queue* getCPU();
int getArrival();
int getWait();
int getExit();
void setWait(int value);
void setExit(int value);
void setArrival(int value);
int compareTo(ListItem *other);




};
