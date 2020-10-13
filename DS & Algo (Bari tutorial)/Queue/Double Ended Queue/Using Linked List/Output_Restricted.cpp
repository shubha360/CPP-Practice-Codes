#include<iostream>
#include "Dequeue.cpp"

class OP_Restricted_Dequeue : public Dequeue {

    public:

    void dequeueRear() override {

        cout << "Output restricted. Sorry can't pop from rear!" << endl;
    }
};

// int main() {

//     OP_Restricted_Deque dq;

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