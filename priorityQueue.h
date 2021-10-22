#pragma once
class Node;
class Event;

class priorityQueue {
private:
    int size;
    Node* head;

public:
    priorityQueue();
    void insert(Event* event);
    int getSize();
    bool isEmpty();
     Event* getHead();
     Event* extractHead();
     Event* remove(Event* event);
     Event* iterator();


};


