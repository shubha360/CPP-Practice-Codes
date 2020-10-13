#include<iostream>
#include<stack>

using namespace std;

class Queue {

    private:

    stack<int> st1, st2;

    public:

    const bool isEmpty();
    void enqueue(int data);
    void dequeue();
    const int first();
    const int last();
    const void display();
};

const bool Queue :: isEmpty() {

    return st1.empty() && st2.empty() ? 1 : 0;
}

void Queue :: enqueue(int data) {

    st1.push(data);
}

void Queue :: dequeue() {

    if (this -> isEmpty())
        cout << "Queue is empty." << endl;
    
    else {

        if (!st2.empty())
            st2.pop();

        else {

            while (!st1.empty()) {
                
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
    }
}

const int Queue :: first() {

    int x = -1;

    if (this -> isEmpty())
        cout << "Queue is empty ";
    
    else {

        if (!st2.empty())
            x = st2.top();

        else {

            while (!st1.empty()) {
                
                st2.push(st1.top());
                st1.pop();
            }
            x = st2.top();
        }
    }
    return x;
}

const int Queue :: last() {
    
    int x = -1;

    if (this -> isEmpty())
        cout << "Queue is empty ";
    
    else {

        if (!st1.empty())
            x = st1.top();

        else {

            while (!st2.empty()) {
                
                st1.push(st2.top());
                st2.pop();
            }
            x = st1.top();
        }
    }
    return x;
}

const void Queue :: display() {

    if (this -> isEmpty())
        cout << "Queue is empty." << endl;

    else {

        if (st1.empty() && !st2.empty()) {

            while (!st2.empty()) {

                cout << st2.top() << " ";
                st2.pop();
            }
        }

        else if (!st1.empty() && st2.empty()) {

            while (!st1.empty()) {
                
                st2.push(st1.top());
                st1.pop();
            }

            while (!st2.empty()) {

                cout << st2.top() << " ";
                st2.pop();
            }
        }

        else {

            while (!st2.empty()) {

                cout << st2.top() << " ";
                st2.pop();
            }

            while (!st1.empty()) {
                
                st2.push(st1.top());
                st1.pop();
            }

            while (!st2.empty()) {

                cout << st2.top() << " ";
                st2.pop();
            }
        }
    }
}

int main() {

    Queue q;

    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(2);
    q.enqueue(5);

    cout << "First : " << q.first() << endl;
    cout << "Last : " << q.last() << endl;

    q.dequeue();

    q.enqueue(10);
    
    cout << "First : " << q.first() << endl;
    cout << "Last : " << q.last() << endl;

    q.display();

    return 0;
}