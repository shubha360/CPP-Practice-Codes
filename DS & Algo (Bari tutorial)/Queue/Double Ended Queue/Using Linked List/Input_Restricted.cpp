#include<iostream>
#include "Dequeue.cpp"

class IP_Restricted_Dequeue : public Dequeue {

    public:

    void enqueueFront(int data) override {

        cout << "Input restricted. Sorry can't push in front!" << endl;
    }
};

// int main() {

//     IP_Restricted_Deque dq;

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