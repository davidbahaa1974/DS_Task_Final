#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

// ============================================
// Test Helper Functions
// ============================================
void printSeparator(string title) {
    cout << "\n";
    cout << "============================================\n";
    cout << "   " << title << "\n";
    cout << "============================================\n";
}

void printSubTest(string title) {
    cout << "\n--- " << title << " ---\n";
}

// ============================================
// Stack Array Tests
// ============================================
void testStackArr() {
    printSeparator("STACK ARRAY TEST");

    StackArr s(3);

    printSubTest("Push 10, 20, 30, 40 (resize at 40)");
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40); // triggers resize
    s.print();  // Top -> 40 -> 30 -> 20 -> 10

    printSubTest("Peek");
    s.peek();   // Top: 40

    printSubTest("Pop one element");
    s.pop();
    s.print();  // Top -> 30 -> 20 -> 10

    printSubTest("Pop with value");
    int val;
    s.pop(val);
    cout << "Popped value: " << val << "\n";
    s.print();  // Top -> 20 -> 10

    printSubTest("Peek with value");
    int peekVal;
    s.peek(peekVal);
    cout << "Peek value: " << peekVal << "\n";

    printSubTest("Size");
    cout << "Size: " << s.getSize() << "\n";

    printSubTest("Pop all elements");
    s.pop();
    s.pop();
    s.print();  // StackArr is empty!

    printSubTest("Pop from empty stack");
    s.pop();    // StackArr is empty!
}

// ============================================
// Stack Linked List Tests
// ============================================
void testStackLL() {
    printSeparator("STACK LINKED LIST TEST");

    StackLL s;

    printSubTest("Push 10, 20, 30");
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();  // Top -> 30 -> 20 -> 10

    printSubTest("Peek");
    cout << "Peek: " << s.peek() << "\n";  // 30

    printSubTest("Pop one element");
    cout << "Popped: " << s.pop() << "\n"; // 30
    s.print();  // Top -> 20 -> 10

    printSubTest("Size");
    cout << "Size: " << s.getSize() << "\n"; // 2

    printSubTest("Pop all elements");
    s.pop();
    s.pop();
    s.print();  // StackLL is empty!

    printSubTest("Pop from empty stack");
    s.pop();    // StackLL is empty!

    printSubTest("Peek from empty stack");
    s.peek();   // StackLL is empty!
}

// ============================================
// Queue Array Tests
// ============================================
void testQueueArr() {
    printSeparator("QUEUE ARRAY TEST");

    QueueArr q(3);

    printSubTest("Enqueue 10, 20, 30, 40 (resize at 40)");
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40); // triggers resize
    q.display();   // Front -> 10 -> 20 -> 30 -> 40 <- Rear

    printSubTest("Peek");
    cout << "Peek: " << q.peek() << "\n";  // 10

    printSubTest("Dequeue two elements");
    cout << "Dequeued: " << q.dequeue() << "\n"; // 10
    cout << "Dequeued: " << q.dequeue() << "\n"; // 20
    q.display();   // Front -> 30 -> 40 <- Rear

    printSubTest("Size");
    cout << "Size: " << q.getSize() << "\n"; // 2

    printSubTest("Dequeue all elements");
    q.dequeue();
    q.dequeue();
    q.display();   // QueueArr is empty!

    printSubTest("Dequeue from empty queue");
    q.dequeue();   // QueueArr is empty!

    printSubTest("Circular behavior test");
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();   // Front -> 100 -> 200 -> 300 <- Rear
}

// ============================================
// Queue Linked List Tests
// ============================================
void testQueueLL() {
    printSeparator("QUEUE LINKED LIST TEST");

    QueueLL q;

    printSubTest("Enqueue 10, 20, 30, 40");
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();   // Front -> 10 -> 20 -> 30 -> 40 <- Rear

    printSubTest("Peek");
    cout << "Peek: " << q.peek() << "\n";  // 10

    printSubTest("Dequeue two elements");
    cout << "Dequeued: " << q.dequeue() << "\n"; // 10
    cout << "Dequeued: " << q.dequeue() << "\n"; // 20
    q.display();   // Front -> 30 -> 40 <- Rear

    printSubTest("Size");
    cout << "Size: " << q.getSize() << "\n"; // 2

    printSubTest("Dequeue all elements");
    q.dequeue();
    q.dequeue();
    q.display();   // QueueLL is empty!

    printSubTest("Dequeue from empty queue");
    q.dequeue();   // QueueLL is empty!

    printSubTest("Peek from empty queue");
    q.peek();      // QueueLL is empty!
}

// ============================================
// Main
// ============================================
int main() {
    testStackArr();
    testStackLL();
    testQueueArr();
    testQueueLL();

    cout << "\n============================================\n";
    cout << "   ALL TESTS COMPLETED\n";
    cout << "============================================\n";

    return 0;
}