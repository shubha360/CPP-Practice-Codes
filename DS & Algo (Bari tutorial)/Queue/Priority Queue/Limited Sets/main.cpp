// Smaller number - Higher priority

#include<iostream>
#include<queue>

using namespace std;

class Priority_Queue {

    private:

    queue<char> array[3];

    public:

    bool input_invalidation(char c);
    bool isEmpty();
    int getPriority(char c);
    void enqueue(char c);
    void dequeue();
    void display();
};

bool Priority_Queue :: input_invalidation(char c) {

    return c >= 'A' && c <= 'I' ? 0 : 1;
}

bool Priority_Queue :: isEmpty() {

    return array[0].empty() && array[1].empty() && array[0].empty() ? 1 : 0;
}

int Priority_Queue :: getPriority(char c) {

    if (c == 'E' || c == 'G' || c == 'H' || c == 'I')
        return 1;
    else if (c == 'A' || c == 'D' || c == 'F')
        return 2;
    else if (c == 'B' || c == 'C')
        return 3;
        
    return -1;
}

void Priority_Queue :: enqueue(char c) {

    if (input_invalidation(c))
        cout << "Invalid input." << endl;

    else {
    
        int priority = getPriority(c);

        array[priority - 1].push(c);
    }
}

void Priority_Queue :: dequeue() {
    
    if (this -> isEmpty())
        cout << "All queues are empty" << endl;
    
    else {

        if (!array[0].empty())
            array[0].pop();
        
        else if (!array[1].empty())
            array[1].pop();
        
        else if (!array[2].empty())
            array[2].pop();
    }
}

void Priority_Queue :: display() {
    
    if (this -> isEmpty())
        cout << "All queues are empty" << endl;
    
    else {

        // if (!array[0].empty()) {

            cout << "1 : ";

            while (!array[0].empty()) {

                cout << array[0].front();
                array[0].pop();
            }
            cout << endl;
        // }
        
        // else if (!array[1].empty()) {
            
            cout << "2 : ";

            while (!array[1].empty()) {

                cout << array[1].front();
                array[1].pop();
            }
            cout << endl;
        // }
        
        // else if (!array[2].empty()) {

            cout << "3 : ";

            while (!array[2].empty()) {

                cout << array[2].front();
                array[2].pop();
            }
            
        // }
    }
}

int main() {

    Priority_Queue pq;

    for (char c = 'A'; c <= 'I'; c++)
        pq.enqueue(c);

    pq.dequeue();
    pq.dequeue();

    pq.display();

    return 0;
}