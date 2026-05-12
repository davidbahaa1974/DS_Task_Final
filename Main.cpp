#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main() {

    // ==================== Stack with Array ====================
    cout << "\n========== Stack with Array ==========\n";
    stackArr sa;

    sa.push(10);
    sa.push(20);
    sa.push(30);
    sa.push(40);

    cout << "Stack after pushing 10, 20, 30, 40:\n";
    sa.print();
    cout << endl;

    cout << "Peek top: ";
    sa.peek();
    cout << endl;

    int poppedValue;
    sa.pop(poppedValue);
    cout << "After pop:\n";
    sa.print();
    cout << endl;
    sa.pop(); 

    cout << "Stack after second pop:\n";
    sa.print();
    cout << endl;

    sa.pop();
    sa.pop();   

    cout << "Stack after popping all elements:\n"; 

    sa.print();
    cout << endl;

    cout << "Popped value: " << poppedValue << endl;
    sa.pop();        // popping from empty stack to test underflow handling

    // ==================== Stack with Linked List ====================
    cout << "\n========== Stack with Linked List ==========\n";
    StackLL sl;

    sl.push(10);
    sl.push(20);
    sl.push(30);
    sl.push(40);

    cout << "Peek top: " << sl.peek() << endl;

    sl.print();

    cout << "Popped: " << sl.pop() << endl;
    cout << "Popped: " << sl.pop() << endl;

    cout << "Stack after two pops:\n";
    sl.print();

    cout << "Peek after two pops: " << sl.peek() << endl;
    sl.print();

    sl.pop();
    sl.pop();
    cout << "Stack after popping all elements:\n";
    sl.print();
    cout << "Popping from empty stack: " << sl.pop() << endl; // popping from empty stack to test underflow handling


    // ==================== Queue with Circular Array ====================
    cout << "\n========== Queue with Circular Array ==========\n";
    QueueCircularArray qca(5);

    qca.enqueue(10);
    qca.enqueue(20);
    qca.enqueue(30);
    qca.enqueue(40);

    cout << "Queue after enqueuing 10, 20, 30, 40:\n";
    qca.display();

    cout << "Dequeued: " << qca.dequeue() << endl;
    cout << "Dequeued: " << qca.dequeue() << endl;

    cout << "Queue after two dequeues:\n";
    qca.display();
    qca.enqueue(50);
    qca.enqueue(60); // this should fill the queue to capacity
    cout << "Queue after enqueuing 50 and 60:\n";
    qca.display();
    qca.enqueue(70);
    qca.display();
    qca.enqueue(80); // this should trigger overflow handling again
    qca.dequeue();
    qca.dequeue();
    qca.display();
    qca.dequeue();
    qca.dequeue();
    qca.display();
    qca.dequeue();
    qca.display();
    qca.dequeue(); // this should trigger underflow handling
    qca.display();
    // ==================== Queue with Linked List ====================
    cout << "\n========== Queue with Linked List ==========\n";
    QueueLinkedList qll;

    qll.enqueue(10);
    qll.enqueue(20);
    qll.enqueue(30);
    qll.enqueue(40);

    cout << "Queue after enqueuing 10, 20, 30, 40:\n";
    qll.display();

    cout << "Peek front: " << qll.peek() << endl;

    cout << "Dequeued: " << qll.dequeue() << endl;
    cout << "Dequeued: " << qll.dequeue() << endl;

    cout << "Queue after two dequeues:\n";
    qll.display();
    cout << "Peek after two dequeues: " << qll.peek() << endl;
    qll.dequeue();
    qll.dequeue();
    cout << "Queue after dequeuing all elements:\n";    
    qll.display();
    cout << "Dequeuing from empty queue: " << qll.dequeue() << endl;

    return 0;
}