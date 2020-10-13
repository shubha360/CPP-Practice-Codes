#include<iostream>

using namespace std;

class Node {

    public:

    int data;
    Node *next;
};

class Queue {

    private:

    Node *front;
    Node *rear;

    public:
    Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    void dequeue();
    int first();
    int last();
    void display();
    ~Queue();
};

Queue :: Queue() {

    this -> front = this -> rear = nullptr;
}

bool Queue :: isEmpty() {

    return this -> rear == nullptr ? 1 : 0;
}

bool Queue :: isFull() {

    bool b = true;
    Node *t = new Node;
    if (t)
        b = false;
    
    delete t;
    return b;
}

void Queue :: enqueue(int data) {

    if (this -> isFull())
        cout << "Heap is full!" << endl;

    else {

        Node *temp = new Node;
        temp -> data = data;
        temp -> next = nullptr;

        if (this -> isEmpty())
            front = rear = temp;

        else {
            rear -> next = temp;
            rear = temp;
        }
    }
}

void Queue :: dequeue() {

    if (this -> isEmpty())
        cout << "Queue is empty." << endl;
    
    else {

        if (front == rear) {
            
            delete front;
            front = rear = nullptr;
        }
        else {
            
            Node *p = front;
            front = front -> next;
            delete p;
        }
    }
}

int Queue :: first() {

    if (isEmpty()) {
        cout << "Queue is empty " << endl;
        return -1;
    }
    return front -> data;
}

int Queue :: last() {
    
    if (isEmpty()) {
        cout << "Queue is empty " << endl;
        return -1;
    }
    return rear -> data;
}

void Queue :: display() {

    if (this -> isEmpty())
        cout << "Queue is empty." << endl;
    
    else {
        Node *p = front;

        while (p) {
            
            cout << p -> data << " ";
            p = p -> next;
        }
        cout << endl;
    }
}

Queue :: ~Queue() {

    Node *p = front;

    while (p) {

        front = front -> next;
        delete p;
        p = front;
    }
}

int main() {

    Queue q;

    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(2);
    q.enqueue(5);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(1);
    q.enqueue(9);

    cout << "First : " << q.first() << endl;
    cout << "Last : " << q.last() << endl;

    q.display();

    return 0;
}