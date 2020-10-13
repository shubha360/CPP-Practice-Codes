#include<iostream>

using namespace std;

class Node {

    public:

    int data;
    Node *next;
};

class Stack {

    private:
    Node *top;
    int count;

    public:
    
    Stack();
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    int stackTop();
    int peek(int position);
    ~Stack();
};

Stack :: Stack() {
    
    this -> top = nullptr;
    this -> count = 0;
}

bool Stack :: isEmpty() {

    return top == nullptr ? 1 : 0;
}

bool Stack :: isFull() {

    Node *temp = new Node;
    
    bool r = temp ? 0 : 1;
    delete temp;
    return r;
}

void Stack :: push(int data) {

    if (this -> isFull())
        cout << "Stack overflow. Couldn't store " << data << endl;
    
    else {

        Node *temp = new Node;
        temp -> data = data;
        temp -> next = top;
        top = temp;
        count++;
    }
}

int Stack :: pop() {

    int res = -1;

    if (this -> isEmpty())
        cout << "Stack underflow ";

    else {

        Node *ptr = top;
        top = top -> next;
        res = ptr -> data;
        delete ptr;
        count--;
    }
    return res;
}

int Stack :: stackTop() {

    int res = -1;

    if (this -> isEmpty())
        cout << "Stack is empty ";

    else
        res = top -> data;

    return res; 
}

int Stack :: peek(int position) {

    int res = -1;

    if (this -> isEmpty())
        cout << "Stack is empty ";
    else if (position < 1 || position > count)
        cout << "Invalid position ";
    else {
        
        Node *ptr = top;
        
        for (int i = 1; i < position; i++)
            ptr = ptr -> next;
        
        res = ptr -> data;
    }
    return res;
}

Stack :: ~Stack() {

    if (!this -> isEmpty()) {

        Node *ptr = top;

        while (ptr) {
        
            top = top -> next;
            delete ptr;
            ptr = top;
        }
    }
}