#include<iostream>

using namespace std;

class Queue {

    private:

    int size;
    int front;
    int rear;
    int *Q;

    public:

    Queue(int size);
    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    void dequeue();
    int first();
    int last();
    void display();
    ~Queue();
};

// Constructor
Queue :: Queue(int size) {

    this -> size = size;
    this -> Q = new int[size];
    this -> front = this -> rear = 0;
}

bool Queue :: isEmpty() {

    return this -> front == this -> rear ? 1 : 0;
}

bool Queue :: isFull() {

    return (this -> rear + 1) % this -> size == front ? 1 : 0;
}

void Queue :: enqueue(int data) {

    if (this -> isFull())
        cout << "Queue overflow." << endl;
    
    else {

        this -> rear = (rear + 1) % size;
        Q[rear] = data;
    }
}

void Queue :: dequeue() {

    if (this -> isEmpty())
        cout << "Queue underflow." << endl;
    
    else
        this -> front = (front + 1) % this -> size;
}

int Queue :: first() {

    if (this -> isEmpty()) {

        cout << "Queue is empty ";
        return -1;
    }
    return Q[(front + 1) % size];
}

int Queue :: last() {

    if (this -> isEmpty()) {

        cout << "Queue is empty ";
        return -1;
    }
    return Q[rear];
}

void Queue :: display() {

    if (this -> isEmpty()) {

        cout << "Queue is empty." << endl;
        return;
    }

    int i = (front + 1) % size; 

    do {
     
        cout << Q[i] << " ";
        i = (i + 1) % size;
    }while (i != (rear + 1) % size);

    cout << endl;
}

// Destructor
Queue :: ~Queue() {
    delete[] Q;
}

int main() {

    Queue q(5);

    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(8);

    q.dequeue();
    q.dequeue();

    cout << "First : " << q.first() << endl;
    cout << "Last : " << q.last() << endl;

    q.display();
    return 0;
}