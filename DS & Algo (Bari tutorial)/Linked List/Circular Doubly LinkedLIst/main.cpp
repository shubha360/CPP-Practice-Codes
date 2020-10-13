#include<iostream>
#include<vector>

using namespace std;

class D_Node {

    public:
    
    int data;
    D_Node *prev;
    D_Node *next;
};

class CircularDoublyLinkedList {

    private:
    
    D_Node *head;
    int size;

    public:

    CircularDoublyLinkedList(vector<int> vec);
    void display();
    void insertNode(int position, int data);
    void deleteNode(int position);
    void reverse();
    ~CircularDoublyLinkedList();
};

// Constructor
CircularDoublyLinkedList :: CircularDoublyLinkedList(vector<int> vec) {

    this -> size = vec.size();

    if (vec.size() == 0) {

        head = nullptr;
        return;
    }
    
    D_Node *last = new D_Node;
    last -> data = vec[0];
    last -> prev = nullptr;
    last -> next = nullptr;

    head = last;

    for (int i = 1; i < vec.size(); i++) {

        D_Node *temp = new D_Node;
        temp -> data = vec[i];
        temp -> prev = last;
        temp -> next = nullptr;

        last -> next = temp;
        last = temp;
    }
    last -> next = head;
    head -> prev = last;
}

// Display function
void CircularDoublyLinkedList :: display() {

    if (head == nullptr) {
        
        cout << "List is empty" << endl;
        return;
    }

    cout << "linked to last";

    D_Node *ptr = head;

    do {

        cout << " <- " << ptr -> data << " -> ";
        ptr = ptr -> next;
    } while (ptr != head);
    
    cout << "linked to head";
}

// Insert a node
void CircularDoublyLinkedList :: insertNode(int position, int data) {

    if (position < 0 || position > this -> size) {

        cout << "Invalid position credentials" << endl;
        return;
    }

    if (position == 0) {

        D_Node *temp = new D_Node;
        temp -> data = data;
        temp -> prev = nullptr;
        temp -> next = nullptr;

        if (head == nullptr) {

            temp -> prev = temp;
            temp -> next = temp;
            head = temp;
            this -> size++;
            return;
        }

        D_Node *ptr = head -> next;

        while (ptr -> next != head)
            ptr = ptr -> next;

        temp -> next = head;
        temp -> prev = ptr;
        ptr -> next = temp;
        head -> prev = temp;

        head = temp;
        this -> size++;
    }
    else {

        D_Node *ptr = head;

        for (int i = 1; i < position; i++)
            ptr = ptr -> next;
        
        D_Node *temp = new D_Node;

        temp -> data = data;
        temp -> prev = ptr;
        temp -> next = ptr -> next;
        ptr -> next -> prev = temp;
        ptr -> next = temp;

        this -> size++;
    }
}

// Delete a node
void CircularDoublyLinkedList :: deleteNode(int position) {

    if (position < 1 || position > this -> size) {

        cout << "Invalid position credentials" << endl;
        return;
    }

    if (position == 1) {

        if (head -> next == head) {

            delete head;
            head = nullptr;
            this -> size--;
            return;
        }

        D_Node *ptr = head;

        head -> prev -> next = head -> next;
        head -> next -> prev = head -> prev;
        head = head -> next;
        delete ptr;
        this -> size--;
    }
    else {

        D_Node *ptr = head;

        for (int i = 1; i < position; i++)
            ptr = ptr -> next;

        ptr -> prev -> next = ptr -> next;
        ptr -> next -> prev = ptr -> prev;
        delete ptr;
    }
}

// Reverse list
void CircularDoublyLinkedList :: reverse() {

    D_Node *ptr = head;

    do {
        
        D_Node *temp = head -> next;
        head -> next = head -> prev;
        head -> prev = temp;
        head = head -> prev;

    } while (head != ptr);

    head = head -> next;
}

// Destructor
CircularDoublyLinkedList :: ~CircularDoublyLinkedList() {

    if (head == nullptr)
        return;

    D_Node *ptr = head -> next;

    while (ptr != head)
        ptr = ptr -> next;

    while (head != ptr) {

        head = head -> next;
        delete head -> prev;
        head -> prev = ptr;
        ptr -> next = head;
    }

    delete head;
    head = nullptr;

    // cout << "Destructor called." << endl;
}

int main() {

    vector<int> vec;
    
    for (int i = 1; i <= 6; i++)
        vec.push_back(i);
    
    CircularDoublyLinkedList ll(vec);

    ll.display();
    cout << endl;

    ll.reverse();

    ll.display();
    cout << endl;

    return 0;
}