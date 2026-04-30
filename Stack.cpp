#include "Stack.h"
#include <iostream>
using namespace std;

// ============================================
// StackArr Implementation
// ============================================

StackArr::StackArr(int size) {
    capacity = size;
    top = -1;
    array = new int[capacity];
}

StackArr::~StackArr() {
    delete[] array;
    cout << "StackArr destroyed, memory freed.\n";
}

void StackArr::push(int val) {
    // resize if full
    if (top >= capacity - 1) {
        int newCapacity = capacity * 2;
        int* newArray = new int[newCapacity];
        for (int i = 0; i <= top; i++)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
        capacity = newCapacity;
        cout << "StackArr resized to " << capacity << "\n";
    }
    array[++top] = val;
}

bool StackArr::isEmpty() {
    return top == -1;
}

void StackArr::pop() {
    if (isEmpty()) {
        cout << "StackArr is empty!\n";
        return;
    }
    top--;
}

void StackArr::pop(int& val) {
    if (isEmpty()) {
        cout << "StackArr is empty!\n";
        return;
    }
    val = array[top];
    top--;
}

void StackArr::peek() {
    if (isEmpty()) {
        cout << "StackArr is empty!\n";
        return;
    }
    cout << "Top: " << array[top] << "\n";
}

void StackArr::peek(int& val) {
    if (isEmpty()) {
        cout << "StackArr is empty!\n";
        return;
    }
    val = array[top];
}

int StackArr::getSize() {
    return top + 1;
}

void StackArr::print() {
    if (isEmpty()) {
        cout << "StackArr is empty!\n";
        return;
    }
    cout << "Top -> ";
    for (int i = top; i >= 0; i--) {
        cout << array[i];
        if (i > 0) cout << " -> ";
    }
    cout << "\n";
}


// ============================================
// StackLL Implementation
// ============================================

StackLL::StackLL() {
    top = nullptr;
    length = 0;
}

StackLL::~StackLL() {
    while (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    cout << "StackLL destroyed, memory freed.\n";
}

bool StackLL::isEmpty() {
    return top == nullptr;
}

void StackLL::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    length++;
}

int StackLL::pop() {
    if (isEmpty()) {
        cout << "StackLL is empty!\n";
        return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    length--;
    return val;
}

int StackLL::peek() {
    if (isEmpty()) {
        cout << "StackLL is empty!\n";
        return -1;
    }
    return top->data;
}

int StackLL::getSize() {
    return length;
}

void StackLL::print() {
    if (isEmpty()) {
        cout << "StackLL is empty!\n";
        return;
    }
    cout << "Top -> ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << "\n";
}