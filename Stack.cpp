#include "Stack.h"
#include <iostream>
using namespace std;

// ==================== Stack with Array ====================

stackArr::stackArr(){                               //to intialize the memory
cout << "Please enter the starting stack size: ";
cin >> capacity;
top =-1;
array=new int[capacity];
}

stackArr::~stackArr(){                              //cleans the memory
    delete[] array;
}

void stackArr::push (int val){                      //add element on top

    if (top>=capacity-1){                           //resize the array
    int newcapacity = capacity*2;
    int* newArray = new int[newcapacity];
    for (int i = 0; i <= top; i++) {                //coping the old array to the new one
        newArray[i] = array[i];
}   
        delete[] array;                             // deleting the old array
        array = newArray;       
        capacity = newcapacity; 
    }
    
    top++;
    array[top]=val;

}

bool stackArr::isempty(){                           //to check if the stack is empty
    return top==-1;
}

void stackArr::pop(){                               //delete element on top
if (isempty()){
    cout<<"stack is empty";
}    
else {
    top--;
}}

void stackArr::pop(int&val)                         //to return the value of the deleted element
{
    if (isempty()){
    cout<<"stack is empty";
}    
    else {
    val = array[top];
    top--;
}
    
}

void stackArr::peek(){                            //to print the value of the top element
    if (isempty()){
        cout<<"stack is empty";
    }
    else {
       cout<<array[top]; 
    } 
}

void stackArr::peek(int&val){                      //to return the value of the top
    if (isempty()){
        cout<<"stack is empty";
    }
    else {
         val=array[top];
    }
}

void stackArr::print(){                          //print all the element to check the implemntation is right
    for (int i = top; i >= 0; i--){
        cout<<array[i]<<" ";
    }
}


// ==================== Stack with Linked List ====================

StackLL::StackLL(){                         //constructor
    top = nullptr;
    length = 0;
}

StackLL::~StackLL(){                        //Destructor to free the memory used by the stack
    while(!isEmpty()){
        Node* temp = top;
        top = top->next;
        delete temp;
    }

}

//this retuen true if the stack is empty and false if it is not empty
bool StackLL::isEmpty(){
return !length;
}


//to apply LIFO principle i will make it with prepend and removefirst to make O(1)

void StackLL::push(int value ){                  //to add an item to the stack from first
Node* newnode= new Node;                            
newnode->next = top ;                            
newnode->data = value;
top= newnode;
length++;
}


int StackLL::pop(){                           //to remove an item from the stack and return its value
if(isEmpty()){                              
cout<<"Error :the stack is Empty "<<endl;
return -1;
}

else {   
Node* temp= top;
int val = temp->data;
top= top->next;
delete temp;
length--;
return val;
}
}


int StackLL::peek(){                         //to return the value of the top item without removing it
if(isEmpty()){
cout<<"Error :the stack is Empty "<<endl;
return -1;
}
else
    return top->data;

}

void StackLL::print(){                     //to print the elements of the stack from top to bottom
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Top -> ";
    Node* current = top;
    while(current != nullptr){
        cout << current->data;
        if(current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}