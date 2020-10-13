// Larger number - Higher priority

#include<iostream>

using namespace std;

void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

class Priority_Queue {

    private:

    int size, last, *Q;

    public:

    Priority_Queue(int size);
    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    void dequeue();
    int first();
    void display();
    ~Priority_Queue();
};

Priority_Queue :: Priority_Queue(int size) {

    this -> size = size;
    this -> last = -1;

    this -> Q = new int[size];
}

bool Priority_Queue :: isEmpty() {

    return last == -1 ? 1 : 0;
}

bool Priority_Queue :: isFull() {

    return last == size - 1 ? 1 : 0;
}

void Priority_Queue :: enqueue(int data) {

    if (this -> isFull())
        cout << "Queue is full." << endl;
    
    else {

        if (last == -1) {
            last++;
            Q[last] = data;
        }
        else {

            last++;
            Q[last] = data;
            int i = last;

            while (Q[i-1] < Q[i]) {

                swap(Q[i], Q[i-1]);
                i--;
            }
        } 
    }
}

void Priority_Queue :: dequeue() {

    if (this -> isEmpty())
        cout << "Queue is empty." << endl;

    else {

        for (int i = 0; i <= last-1; i++)   
            swap(Q[i],Q[i+1]);
        last--;
    }
}

int Priority_Queue :: first() {

    if (this -> isEmpty()) {
        cout << "Queue is empty ";
        return -1;
    }
    return Q[0];
}

void Priority_Queue :: display() {

    if (this -> isEmpty())
        cout << "Queue is empty." << endl;

    else {
    
        for (int i = 0; i <= last; i++)
            cout << Q[i] << " ";
    }
    cout << endl;
}

Priority_Queue :: ~Priority_Queue() {
    delete[] Q;
}

int main(){

    Priority_Queue pq(6);

    pq.enqueue(4);
    pq.enqueue(1);
    pq.enqueue(8);
    
    pq.display();

    cout << "First : " << pq.first() << endl;

    cout << endl;

    pq.dequeue();

    pq.display();

    cout << "First : " << pq.first() << endl;

    cout << endl;

    pq.enqueue(2);
    pq.enqueue(11);

    pq.display();

    cout << "First : " << pq.first() << endl;

    return 0;
}