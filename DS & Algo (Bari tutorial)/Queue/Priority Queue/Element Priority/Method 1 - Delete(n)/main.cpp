// Larger number - Higher priority

#include<iostream>

using namespace std;

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

        last++;
        Q[last] = data;
    }
}

void Priority_Queue :: dequeue() {

    if (this -> isEmpty())
        cout << "Queue is empty." << endl;

    else {

        int max = Q[0], index = 0;

        for (int i = 0; i <= last; i++) {
         
            if (Q[i] > max) {
                
                max = Q[i];
                index = i;
            }
        }
        
        for (int i = index; i <= last; i++)
            Q[i] = Q[i + 1];
    }
    last--;
}

int Priority_Queue :: first() {

    int max;
    if (this -> isEmpty()) {
        cout << "Queue is empty ";
        return -1;
    }

    else {
        
        int index;
        max = Q[0];

        for (int i = 0; i <= last; i++) {
            
            if (Q[i] > max)
                max = Q[i];
        }
    }
    return max;
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
    pq.enqueue(8);
    pq.enqueue(1);
    pq.enqueue(5);
    pq.enqueue(10);
    pq.enqueue(2);
    
    pq.display();

    cout << "First : " << pq.first() << endl;

    cout << endl;

    pq.dequeue();

    pq.display();

    cout << "First : " << pq.first() << endl;

    return 0;
}