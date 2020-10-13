#include<iostream>

using namespace std;

class Dequeue {

    private:
    
    int size, front, rear;
    int *Q;

    public:

    Dequeue(int size);
    const bool isEmpty();
    const bool isFull();
    virtual void enqueueFront(int data);
    void enqueueRear(int data);
    void dequeueFront();
    virtual void dequeueRear();
    int first();
    int last();
    void display();
    ~Dequeue();
};

Dequeue :: Dequeue(int size) {

    this -> size = size;

    this -> Q = new int[size];

    this -> front = this -> rear = 0;
}

const bool Dequeue :: isEmpty() {

    return front == rear ? 1 : 0;
}

const bool Dequeue :: isFull() {

    return (rear + 1) % size == front ? 1 : 0;
}

void Dequeue :: enqueueFront(int data) {

    if (isFull())
        cout << "Dequeue is full." << endl;
    
    else {

        if (front == 0)
            front = size - 1;
        else
            front--;
        
        Q[(front + 1) % size] = data;
    }
}

void Dequeue :: enqueueRear(int data) {

    if (isFull())
        cout << "Dequeue is full." << endl;
    
    else {

        rear = (rear + 1) % size;
        Q[rear] = data;
    }
}

void Dequeue :: dequeueFront() {

    if (isEmpty())
        cout << "Dequeue is empty." << endl;
    
    else
        front = (front + 1) % size;
}

void Dequeue :: dequeueRear() {

    if (isEmpty())
        cout << "Dequeue is empty." << endl;
    
    else {
        
        if(rear == 0)
            rear = size - 1;
        else
            rear--;
    }
}

int Dequeue :: first() {

    if (isEmpty()) {
        cout << "Dequeue is empty." << endl;
        return -1;
    }

    return Q[(front+1) % size];
}

int Dequeue :: last() {

    if (isEmpty()) {
        cout << "Dequeue is empty." << endl;
        return -1;
    }

    return Q[rear];
}

void Dequeue :: display() {
    
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

Dequeue :: ~Dequeue() {
    delete Q;
}

// int main() {

//     Dequeue dq(7);

//     dq.enqueueRear(3);
//     dq.enqueueRear(4);
//     dq.enqueueRear(7);
//     dq.enqueueRear(8);

//     dq.enqueueFront(2);
//     dq.enqueueFront(6);

//     dq.enqueueRear(10);

//     dq.dequeueFront();

//     dq.dequeueRear();
//     dq.dequeueRear();

//     cout << "First : " << dq.first() << endl;
//     cout << "Last : " << dq.last() << endl;

//     dq.display();

//     return 0;
// }