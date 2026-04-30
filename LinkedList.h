#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"  // need Node definition

class LinkedList {
private:
    Node* head;  // pointer to the first node in the list

public:
    LinkedList();                   // Constructor
    ~LinkedList();                  // Destructor

    void insertAtHead(int value);   // insert at the beginning
    void insertAtEnd(int value);    // insert at the end
    void deleteValue(int value);    // delete a value from the list
    void display();                 // print the list
};

#endif