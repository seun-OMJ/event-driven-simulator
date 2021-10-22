#include "priorityQueue.h"
#include "Event.h"
#include "Node.h"

priorityQueue::priorityQueue() :head(nullptr),size(0){}
int priorityQueue::getSize() {return size;}
bool priorityQueue::isEmpty() {
    return size==0;
}
Event *priorityQueue::getHead() {
    if (head==nullptr){
        return nullptr;
    }
    else{
    return (dynamic_cast<Event *>(head->getItem()));}
}
Event *priorityQueue::extractHead() {
    if(size == 0)
        return nullptr;
    else
    {
    Event *event = dynamic_cast<Event *>(head->getItem());
    head = head->getNext();
    size--;
    return event;}
}
void priorityQueue::insert(Event *event) {
    if (head== nullptr){//||dynamic_cast<Event*>(head->getItem())->compareTo(event)==1) {
        head = new Node(event,nullptr);
        size++;
    } else {
        Node* curr = head;
        while (curr->getNext()!= nullptr&&(dynamic_cast<Event*>(curr->getNext()->getItem())->compareTo(event)<=0)){
            curr = curr->getNext();
        }

        Node* newNode = new Node(event,curr->getNext());
        curr->setNext(newNode);
        size++;


    }
}
    Event *priorityQueue::remove(Event *input) {
        Node *temp = nullptr;
        Node *curr = head;
        while (curr != nullptr && curr->getItem() != input) {
            curr = curr->getNext();
        }
        if (curr->getItem() == input) {
            temp = curr;
            curr = curr->getNext();
            size--;
        }
        return dynamic_cast<Event *>(temp->getItem());
    }
    Event *priorityQueue::iterator(){
        return dynamic_cast<Event *>(head->getNext()->getItem());

}


