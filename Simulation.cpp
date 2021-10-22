#include "Simulation.h"
#include "arrival.h"

Simulation::Simulation(){

    events = new priorityQueue();
    CPU = new Queue();
    IO = new Queue();
    burst = 0;
    lineNo = 0;
    IObusy =false;

}
priorityQueue* HOLDER = new priorityQueue();
static int id = 1;

Queue* proQ= new Queue();
fstream inFile;

Queue* Simulation::getCPU(){
    return CPU;
}
Queue* Simulation::getIO(){
    return IO;
}
Queue* Simulation::getProQ() {
    return proQ;
}
void Simulation::setIOstate(bool val) {IObusy = val;}
bool Simulation::checkIO() {return IObusy;}
int Simulation::getBurst(){
    return burst;
}
void Simulation::setBurst(int item){
    burst = item;
}
priorityQueue* Simulation::getEvent(){
    return events;
}
int Simulation::getLineNo() {
    return lineNo;}
void Simulation::setLineNo(int n) {
    lineNo = n;
}
fstream& Simulation::getF(){
    return inFile;
}
void Simulation::runSimulation(char *fileName) {

    inFile.open(fileName);
    string x;
    getline(inFile,x);
    int i = 0;

    istringstream val(x);
    val >> i;

    setBurst(i);
    setLineNo(1);



    string line = get((ifstream &) inFile);
    process* proc = processLine(line);
    proQ->enqueue(proc);

    Event *arr = new class arrival(proc->getArrival(), proc, this);
    arr->handleEvent();
    //events->insert(arr);
   while(!(events->isEmpty())){
       events->getHead()->handleEvent();
       this->getEvent()->extractHead();
          }
    }
void Simulation::summary(){
    cout<<"  process#   Arrival-Time  Exit-Time  Wait-Time"<<endl;
    cout<<"----------------------------------------------------"<<endl;
        while(!proQ->isEmpty()){
            process* proc = dynamic_cast<process *>(proQ->dequeue());
            cout<<proc->getID()<<"            "<<proc->getArrival()<<"             "<<
            proc->getExit()<<"            "<<proc->getWait()<<endl;
            cout.flush();
    }

}

string Simulation::get(ifstream& file) {
    string line;
    getline(file, line);
    return line;
}
process* Simulation::processLine(string line) {
    process* proc;
         proc = new process(id++);
        istringstream iss(line);
        string stuff;
        int i = 0;
        while (iss >> stuff) {
            int x = 0;
            istringstream val(stuff);
            val >> x;
            if (i == 0) {
                proc->setArrival(x);
                i++;
            }
            else if (x > 0) {
                burstHolder *b = new burstHolder(x);
                proc->getCPU()->enqueue(b);
            } else if (x < 0) {
                ListItem *b = new burstHolder(x * (-1));
                proc->getIO()->enqueue(b);
            }
        }

    return proc;}

