#include<iostream>

using namespace std;

class Node {

    public:

    int data;
    Node *next;
};

class Dequeue {

    private:

    Node *front;
    Node *rear;

    public:

    Dequeue();
    const bool isEmpty();
    const bool isFull();
    virtual void enqueueFront(int data);
    void enqueueRear(int data);
    void dequeueFront();
    virtual void dequeueRear();
    const int first();
    const int last();
    const void display();
    ~Dequeue();
};

Dequeue :: Dequeue() {

    this -> front = this -> rear = nullptr;
}

const bool Dequeue :: isEmpty() {
    
    return this -> rear == nullptr ? 1 : 0;
}

const bool Dequeue :: isFull() {

    bool b = true;
    Node *t = new Node;
    if (t)
        b = false;
    delete t;
    return b;
}

void Dequeue :: enqueueFront(int data) {

    if (this -> isFull())
        cout << "Heap is full!" << endl;
    
    else {

        Node *temp = new Node;
        temp -> data = data;
        temp -> next = nullptr;

        if (this -> isEmpty())
            front = rear = temp;

        else {

            temp -> next = front;
            front = temp;
        }
    }
}

void Dequeue :: enqueueRear(int data) {

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

void Dequeue :: dequeueFront() {

    if (this -> isEmpty())
        cout << "Dequeue is empty." << endl;
    
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

void Dequeue :: dequeueRear() {

    if (this -> isEmpty())
        cout << "Dequeue is empty." << endl;

    else {

        if (front == rear) {

            delete front;
            front = rear = nullptr;
        }
        else {
            
            Node *p = front;
            while (p -> next != rear)
                p = p-> next;
            
            rear = p;
            p = p -> next;
            delete p;
            rear -> next = nullptr;
        }
    }
}

const int Dequeue :: first() {

    if (this -> isEmpty()) {
        
        cout << "Dequeue is empty ";
        return -1;
    }

    return front -> data;
}

const int Dequeue ::  last() {

    if (this -> isEmpty()) {
        
        cout << "Dequeue is empty ";
        return -1;
    }

    return rear -> data;
}

const void Dequeue :: display() {

    if (this -> isEmpty()) {
        cout << "Dequeue is empty." << endl;
        return;
    }

    Node *p = front;

    while (p) {

        cout << p -> data << " ";
        p = p -> next;
    }
}

Dequeue :: ~Dequeue() {

    Node *p = front;

    while (p) {

        front = front -> next;
        delete p;
        p = front;
    }
}

// int main() {

//     Deque dq;

//     dq.enqueueRear(3);
//     dq.enqueueRear(4);
//     dq.enqueueRear(7);
//     dq.enqueueRear(8);

//     dq.enqueueFront(2);
//     dq.enqueueFront(6);

//     dq.dequeueFront();

//     dq.dequeueRear();
//     dq.dequeueRear();

//     cout << "First : " << dq.first() << endl;
//     cout << "Last : " << dq.last() << endl;

//     dq.display();

//     return 0;
// }