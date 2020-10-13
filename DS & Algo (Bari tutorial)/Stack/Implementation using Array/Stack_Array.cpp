#include<iostream>

using namespace std;

class Stack {

    private:

    int size;
    int top;
    int *ptr;

    public:

    Stack(int size);
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    int stackTop();
    int peek(int position);
    ~Stack();
};

Stack :: Stack(int size) {

    this -> size = size;
    this -> top = -1;

    this -> ptr = new int[size];
}

bool Stack :: isEmpty() {

    return this -> top == -1 ? 1 : 0;
}

bool Stack :: isFull() {

    return this -> top == size - 1 ? 1 : 0;
}

void Stack :: push(int data) {

    if (this -> isFull())
        cout << "Stack overflow. Couldn't store " << data << endl;
    
    else {
        
        top++;
        ptr[top] = data;
    }
}

int Stack :: pop() {

    int res = -1;

    if (this -> isEmpty())
        cout << "Stack underflow ";

    else
        res = ptr[top--];

    return res;
}

int Stack :: stackTop() {

    int res = -1;

    if (this -> isEmpty())
        cout << "Stack is empty ";

    else
        res = ptr[top];
    
    return res;
}

int Stack :: peek(int position) {

    int res = -1;

    if (this -> isEmpty())
        cout << "Stack is empty ";

    else if (position > (top + 1) || top - (position - 1) < 0)
        cout << "Invalid position ";

    else 
        res = ptr[top - (position - 1)];

    return res;
}

Stack :: ~Stack() {
    
    delete[] ptr;
}