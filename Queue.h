#pragma once
#include "Node.h"

// ==================== Queue with Circular Array ====================
// Queue class based on circular array
class QueueCircularArray {
private:
  int *arr;
  int front;
  int rear;
  int capacity;
  int count;

public:
  QueueCircularArray(int size); // Constructor
  ~QueueCircularArray();        // Destructor to free memory used by the queue
  void enqueue(int value);      // add element to rear
  int dequeue();                // remove element from front
  bool isEmpty();               // check if the queue is empty
  bool isFull();                // check if the queue is full
  void display();               // display all elements in the queue
};

// ==================== Queue with Linked List ====================
class QueueLinkedList {
private:
    Node* front;  // points to the first element (dequeue from here)
    Node* rear;   // points to the last element (enqueue from here)
    int size;

public:
    QueueLinkedList();        // Constructor
    ~QueueLinkedList();       // Destructor to free memory used by the queue

    void enqueue(int value);  // add element to rear
    int dequeue();            // remove element from front
    int peek();               // return front value without removing it
    bool isEmpty();           // check if the queue is empty
    void display();           // display all elements in the queue
};