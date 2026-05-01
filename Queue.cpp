#include "Queue.h"
#include <iostream>
using namespace std;

// ==================== Queue with Circular Array ====================

// note: the code rear = (rear + 1) % capacity; adds the circular functionality
// to the queue. as if the rear or front or any other indicator reaches the end
// of the array, it will go back to the beginning because the modulus will be
// zero.

QueueCircularArray::QueueCircularArray(int size) {
  capacity = size;
  arr = new int[capacity];
  front = 0;
  // note: rear starts at -1 because in the enqueue function, we increment rear
  // first so -1 + 1 = 0, and the first element will be added at index 0.
  rear = -1;
  // note: tracking the count of elements makes checking for full/empty states
  count = 0;
}

// the destructor
QueueCircularArray::~QueueCircularArray() { delete[] arr; }

void QueueCircularArray::enqueue(int value) {
  if (isFull()) {
    cout << "Queue is full! there is no space to add new element." << endl;
    return;
  }

  // move the rear pointer circularly, then insert the new value
  rear = (rear + 1) % capacity;
  arr[rear] = value;
  count++;
}

int QueueCircularArray::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty! there is no element to remove." << endl;
    return -1;
  }
  // save the value first to return it before moving the front pointer
  // circularly
  int value = arr[front];
  front = (front + 1) % capacity;
  count--;
  return value;
}

bool QueueCircularArray::isEmpty() {
  if (count == 0) {
    return true;
  } else {
    return false;
  }
}

bool QueueCircularArray::isFull() {
  if (count == capacity) {
    return true;
  } else {
    return false;
  }
}

void QueueCircularArray::display() {
  if (isEmpty()) {
    cout << "Queue is empty." << endl;
  } else {
    cout << "Queue: ";
    // note: we use 'i' to count the exact number of elements we printed (from 0
    // to count -1 "i < count"), and we use 'current' to traverse the array
    // circularly starting from the front element
    for (int i = 0, current = front; i < count;
         i++, current = (current + 1) % capacity) {
      cout << arr[current] << ',' << ' ';
    }
      cout << endl;
  }
}


// ==================== Queue with Linked List ====================

// Constructor - initialize front and rear to null
QueueLinkedList::QueueLinkedList() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

// Destructor - free all nodes from memory
QueueLinkedList::~QueueLinkedList() {
    while (!isEmpty()) {
        dequeue();
    }
    cout << "Queue destroyed, memory freed.\n";
}

// Enqueue - always add to the rear
void QueueLinkedList::enqueue(int value) {
    // create a new node
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // check (if queue is empty, both front and rear point to new node)
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        // link new node after the current rear
        rear->next = newNode;
        // move rear pointer to the new node
        rear = newNode;
    }

    size++;
    cout << value << " enqueued successfully.\n";
}

// Dequeue - always remove from the front
int QueueLinkedList::dequeue() {
    // check if queue is empty (underflow)
    if (isEmpty()) {
        cout << "Queue is empty! (Underflow)\n";
        return -1;
    }

    // save front value to return it
    int value = front->data;

    // move front pointer to the next node
    Node* temp = front;
    front = front->next;
    delete temp; // free the old front node from memory

    // if queue became empty, set rear to null as well
    if (front == nullptr) {
        rear = nullptr;
    }

    size--;
    return value;
}

// Peek - return front value without removing it
int QueueLinkedList::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return front->data;
}

// isEmpty - check if queue has no elements
bool QueueLinkedList::isEmpty() {
    return front == nullptr;
}

// Display - print all elements from front to rear
void QueueLinkedList::display() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Front -> ";
    Node* current = front;

    // traverse all nodes and print them
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << " <- Rear\n";
}