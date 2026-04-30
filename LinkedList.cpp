#include "LinkedList.h"      // we need the class definition but we don't need Node.h here because it's included in LinkedList.h
#include <iostream>
using namespace std;

LinkedList::LinkedList() {          //make sure to initialize the head pointer to nullptr in the constructor
    head = nullptr; 
}

LinkedList::~LinkedList() {         //make sure to free all the memory allocated for the nodes in the destructor to prevent memory leaks
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;       //save the current node to delete it later
        current = current->next;    //go next before deleting the current node
        delete temp;                //delete the current node to free memory
    }

    head = nullptr;                 
}

//insertAtHead function

void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node;   //create a new node
    newNode->data = value;      //put the value in the node
    newNode->next = head;       //new node now points to the current head
    head = newNode;             //head now points to the new node, making it the new head of the list
}


// insertAtEnd function

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node;   //create a new node
    newNode->data = value;      //put the value in the node
    newNode->next = nullptr;    //last node doesn't point to anything

    // if the list is empty, the new node becomes the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // otherwise, find the last node and link it to the new node
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;    // link the last node to the new node
}


// deleteValue: for deleting a node with a specific value from the linked list

void LinkedList::deleteValue(int value) {
    // if the list is empty
    if (head == nullptr) {
        cout << "the list is empty!" << endl;
        return;
    }

    // if the node to delete is the first node
    if (head->data == value) {
        Node* temp = head;      // save the first node
        head = head->next;      // head now points to the second node
        delete temp;            // delete the first node
        return;
    }

    // iterate through the rest of the list to find the node to delete
    Node* current = head;
    Node* prev = nullptr;       // save the previous node

    while (current != nullptr) {
        if (current->data == value) {
            prev->next = current->next; // skip the node to delete
            delete current;             // free the memory of the deleted node
            return;
        }
        prev = current;
        current = current->next;
    }

    // if we reach here, it means the value is not found
    cout << "the value " << value << " is not found in the list!" << endl;
}

// display: for printing the elements of the linked list

void LinkedList::display() {
    if (head == nullptr) {
        cout << "the list is empty!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data;          // print the value of the current node
        if (current->next != nullptr)   // if it's not the last node, print an arrow to indicate the link
            cout << " -> ";             
        current = current->next;
    }
    cout << endl;
}