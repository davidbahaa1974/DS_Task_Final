#ifndef STACK_H
#define STACK_H
#include "Node.h"

// ============================================
// Stack using Array (Dynamic Resizing)
// ============================================
class StackArr {
private:
    int top;
    int* array;
    int capacity;

public:
    StackArr(int size = 10);
    ~StackArr();
    void push(int val);
    bool isEmpty();
    void pop();
    void pop(int& val);
    void peek();
    void peek(int& val);
    int getSize();
    void print();
};

// ============================================
// Stack using Linked List (LIFO)
// ============================================
class StackLL {
private:
    Node* top;
    int length;

public:
    StackLL();
    ~StackLL();
    bool isEmpty();
    void push(int value);
    int pop();
    int peek();
    int getSize();
    void print();
};

#endif // STACK_H