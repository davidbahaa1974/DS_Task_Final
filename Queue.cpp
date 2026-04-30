#include "Queue.h"
#include <iostream>
using namespace std;

// ============================================
//           QueueArr Implementation
// ============================================

QueueArr::QueueArr(int size) {
    capacity = size;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    count = 0;
}

QueueArr::~QueueArr() {
    delete[] arr;
    cout << "QueueArr destroyed, memory freed.\n";
}

void QueueArr::enqueue(int value) {
    if (isFull()) {
        // resize the array
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        // copy elements in order from front to rear
        for (int i = 0; i < count; i++)
            newArr[i] = arr[(front + i) % capacity];
        delete[] arr;
        arr = newArr;
        front = 0;
        rear = count - 1;
        capacity = newCapacity;
        cout << "QueueArr resized to " << capacity << "\n";
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;
}

int QueueArr::dequeue() {
    if (isEmpty()) {
        cout << "QueueArr is empty!\n";
        return -1;
    }
    int value = arr[front];
    front = (front + 1) % capacity;
    count--;
    return value;
}

int QueueArr::peek() {
    if (isEmpty()) {
        cout << "QueueArr is empty!\n";
        return -1;
    }
    return arr[front];
}

bool QueueArr::isEmpty() {
    return count == 0;
}

bool QueueArr::isFull() {
    return count == capacity;
}

int QueueArr::getSize() {
    return count;
}

void QueueArr::display() {
    if (isEmpty()) {
        cout << "QueueArr is empty!\n";
        return;
    }
    cout << "Front -> ";
    for (int i = 0; i < count; i++) {
        cout << arr[(front + i) % capacity];
        if (i < count - 1) cout << " -> ";
    }
    cout << " <- Rear";
    cout << "  (size: " << count << ")\n";
}


// ============================================
//           QueueLL Implementation
// ============================================

QueueLL::QueueLL() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

QueueLL::~QueueLL() {
    while (!isEmpty())
        dequeue();
    cout << "QueueLL destroyed, memory freed.\n";
}

void QueueLL::enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

int QueueLL::dequeue() {
    if (isEmpty()) {
        cout << "QueueLL is empty!\n";
        return -1;
    }
    int value = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr)
        rear = nullptr;

    size--;
    return value;
}

int QueueLL::peek() {
    if (isEmpty()) {
        cout << "QueueLL is empty!\n";
        return -1;
    }
    return front->data;
}

bool QueueLL::isEmpty() {
    return size == 0;
}

int QueueLL::getSize() {
    return size;
}

void QueueLL::display() {
    if (isEmpty()) {
        cout << "QueueLL is empty!\n";
        return;
    }
    cout << "Front -> ";
    Node* current = front;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << " <- Rear";
    cout << "  (size: " << size << ")\n";
}