#pragma once
#include "Node.h"

// ==================== Stack with Array ====================
class stackArr {    
private:
    int top;
    int *array;
    int capacity;

public:
    stackArr();           // Constructor
    ~stackArr();          // Destructor declaration to free the memory
    void push(int val);   // to add an item to the stack
    bool isempty();       // to check if the stack is empty
    void pop();           // to remove an item from the stack
    void pop(int& val);   // to return the value if the item removed from the stack
    void peek();          // print the the value of the top 
    void peek(int& val);  // to return the value of the top
    void print();         // to print the elements of the stack
};

// ==================== Stack with Linked List ====================
//Stack class built on linked list to implement LIFO principle
class StackLL{

   private:
     Node*top;
     int length;

   public:
    StackLL();            //constructor
    ~StackLL();           //destructor to free the memory used by the stack
    bool isEmpty();       //to check if the stack is empty
    void push(int value); //to add an item to the stack
    int pop();            //to remove an item from the stack and return its value
    int peek();           //to return the value of the top item without removing it
    void print();         //to print the elements of the stack from top to bottom
};