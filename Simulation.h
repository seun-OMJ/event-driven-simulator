#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "process.h"

#include "Event.h"
#include "Queue.h"
#include "priorityQueue.h"

using namespace std;

class Simulation {
private:
    int burst;
    Queue* IO;
    Queue* CPU;
    priorityQueue* events;
    int lineNo;
    bool IObusy;


	// you will need to add fields
        // including: Queues for CPU and IO, and priority queues for Events 	
public:
	Simulation();

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName); 

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();
	Queue* getCPU();
	Queue* getIO();
	int getBurst();
	void setBurst(int item);
	int getLineNo();
	void setLineNo(int n);
	string get(ifstream& file);
	priorityQueue* getEvent();
	process* processLine(string line);
	fstream& getF();
	Queue* getProQ();
	void setIOstate(bool val);
	bool checkIO();

	// you may need to add more methods

};// class Simulation
