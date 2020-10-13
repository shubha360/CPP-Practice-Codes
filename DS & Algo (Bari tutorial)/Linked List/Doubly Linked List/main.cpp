#include<iostream>
#include<vector>

using namespace std;

class D_Node {
    
    public:
    int data;
    D_Node *prev;
    D_Node *next;
};

class DoublyLinkedList {

    private:
    D_Node *head;
    int size;

    public:
    DoublyLinkedList(vector<int> vec);
    void display();
    void insertNode(int position, int data);
    void deleteNode(int position);
    void reverse();
    ~DoublyLinkedList();
};

// Constructor
DoublyLinkedList :: DoublyLinkedList(vector<int> vec) {

    this -> size = vec.size();

    D_Node *last = new D_Node;

    last -> data = vec[0];
    last -> prev = last -> next = nullptr;
    
    head = last;

    for (int i = 1; i < vec.size(); i++) {

        D_Node *temp = new D_Node;
        temp -> data = vec[i];
        temp -> prev = last;
        temp -> next = nullptr;
        last -> next = temp;
        last = temp;
    }
}

// Display function
void DoublyLinkedList :: display() {

    D_Node *ptr = head;

    while (ptr) {

        cout << "<- " << ptr -> data << " -> ";
        ptr = ptr -> next;
    }
}

// Insert function
void DoublyLinkedList :: insertNode(int position, int data) {

    if (position < 0 || position > size) {
        
        cout << "Invalid position credentials" << endl;
        return;
    }

    if (position == 0) {

        D_Node * temp = new D_Node;
        temp -> data = data;
        temp -> prev = temp -> next = nullptr;

        if (head == nullptr) {
            head = temp;
            this -> size++;
            return;
        }

        this -> size++;
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    else {

        D_Node *p = head;

        for (int i = 1; i < position; i++)
            p = p -> next;

        D_Node *temp = new D_Node;
        temp -> data = data;
        temp -> prev = p;
        temp -> next = p -> next;

        if (p -> next == nullptr) {
            p -> next = temp;
            return;
        }

        p -> next -> prev = temp;
        p -> next = temp;

        this -> size++;
    }
}

// Delete function
void DoublyLinkedList :: deleteNode(int position) {

    if (position < 1 || position > size) {
        
        cout << "Invalid position credentials" << endl;
        return;
    }

    if (position == 1) {

        if (head -> next == nullptr) {
            
            delete head;
            head = nullptr;
            this -> size--;
        }

        D_Node *ptr = head;
        head = head -> next;
        delete ptr;
        head -> prev = nullptr;
        this -> size--;
    }
    else {

        D_Node *p = head -> next;

        for (int i = 2; i < position; i++)
            p = p -> next;

        p -> prev -> next = p -> next;
        
        if (p -> next == nullptr) {

            delete p;
            return;
        }
        p -> next -> prev = p -> prev;

        delete p;
        this -> size--;
    }
}

// Reverse list
void DoublyLinkedList :: reverse() {

    D_Node *p = head;

    while (p) {
        
        D_Node *temp = p -> next;
        p -> next = p -> prev;
        p -> prev = temp;
        p = p -> prev;

        if (p && p -> next == nullptr)
            head = p;
    }
}

// Destructor
DoublyLinkedList :: ~DoublyLinkedList() {

    while (head) {

        D_Node *p = head;
        head = head -> next;
        delete p;
        p = head;
    }
}

int main() {

    vector<int> vec;

    for (int i = 1; i <= 7; i++)
        vec.push_back(i);

    DoublyLinkedList dl1(vec);
    dl1.display();
    cout << endl;

    dl1.reverse();
    dl1.display();
    cout << endl;

    return 0;
}