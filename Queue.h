#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

// ============================================
// Queue using Circular Array
// ============================================
class QueueArr {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    QueueArr(int size = 10);
    ~QueueArr();
    void enqueue(int value);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    int getSize();
    void display();
};

// ============================================
// Queue using Linked List
// ============================================
class QueueLL {
private:
    Node* front;
    Node* rear;
    int size;

public:
    QueueLL();
    ~QueueLL();
    void enqueue(int value);
    int dequeue();
    int peek();
    bool isEmpty();
    int getSize();
    void display();
};

#endif // QUEUE_H