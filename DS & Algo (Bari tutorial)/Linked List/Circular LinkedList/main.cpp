#include<iostream>
#include<vector>

using namespace std;

class Node {

    public:
    int data;
    Node *next;
};

class CircularLinkedList {

    public:
    Node *head;
    int size;

    CircularLinkedList(vector<int> vec);
    void display();
    void insertNode(int position, int data);
    void deleteNode(int position);
    ~CircularLinkedList();
};

// Constructor
CircularLinkedList :: CircularLinkedList(vector<int> vec) {

    this -> size = vec.size();

    Node *ptr = new Node;

    ptr -> data = vec[0];
    ptr -> next = nullptr;

    head = ptr;

    for (int i = 1; i < vec.size(); i++) {

        Node *temp = new Node;
        temp -> data = vec[i];
        temp -> next = nullptr;

        ptr -> next = temp;
        ptr = ptr -> next;
    }
    ptr -> next = head;
}

void CircularLinkedList :: display() {

    Node *ptr = head;

    do {
        cout << ptr -> data << " -> ";
        ptr = ptr -> next;
    } while (ptr != head);
    cout << "linked to head";
}

//Function for inserting a node
void CircularLinkedList :: insertNode(int position, int data) {

    if (position < 0 || position > this -> size) {

        cout << "Invalid position credentials";
        return;
    }

    if (position == 0) {

        Node *temp = new Node;
        temp -> data = data;
        temp -> next = nullptr;

        if (head == nullptr) {

            head = temp;
            head -> next = head;
            this -> size++;
            return;
        }

        Node *ptr = head;

        while (ptr -> next != head)
            ptr = ptr -> next;

        temp -> next = head;

        ptr -> next = temp;
        head = temp;
    }
    else {

        Node *ptr = head;
        
        for (int i = 0; i < position-1; i++)
            ptr = ptr -> next;

        Node *temp = new Node;
        temp -> data = data;
        temp -> next = ptr -> next;

        this -> size++;
        ptr -> next = temp;
    }
}

// Function deleting a node
void CircularLinkedList :: deleteNode(int position) {

    if (position < 1 || position > this -> size) {

        cout << "Invalid position credentials";
        return;
    }
    
    if (position == 1) {

        Node *ptr = head;
        
        while (ptr -> next != head)
            ptr = ptr-> next;

        if (ptr == head) {
            
            delete head;
            head = nullptr;
            this -> size--;
            return;
        }

        head = head -> next;
        
        delete ptr -> next;
        ptr -> next = head;
        this -> size--;
    }
    else {

        Node *ptr = head;

        for (int i = 1; i < position-1; i++)
            ptr = ptr -> next;
        
        Node *q = ptr -> next;
        ptr -> next = q -> next;
        delete q;
        this -> size--;
    }
}


// Destrustor
CircularLinkedList :: ~CircularLinkedList() {

    Node *ptr = head;

    do {
        
        head = head -> next;
        delete ptr;
        ptr = head;
    } while (ptr != head);
}

// Global functions

Node * createCircularLinkedList(vector<int> vec) {

    Node *head;

    Node *ptr = new Node;

    ptr -> data = vec[0];
    ptr -> next = nullptr;
    head = ptr;

    for (int i = 0; i < vec.size(); i++) {

        Node *temp = new Node;
        temp -> data = vec[i];
        temp -> next = nullptr;

        ptr -> next = temp;
        ptr = ptr -> next;
    }
    ptr -> next = head;
    return head;
}

void rec_display(Node *head, Node *nextOfHead) {

    static int flag = 0;

    if (nextOfHead != head || flag == 0) {

        flag = 1;
        cout << nextOfHead -> data << " -> ";
        rec_display(head, nextOfHead -> next);
    }
    else
         cout << "linked to head";
         
    flag = 0;
} 

int main() {

    vector<int> vec1;

    for (int i = 1; i <= 10; i++)
        vec1.push_back(i);

    CircularLinkedList cl1(vec1);

    cl1.display();
    cout << endl;
    
    cl1.deleteNode(10);

    cl1.display();
    cout << endl;

    // Node * head = createCircularLinkedList(vec1);

    // rec_display(head, head->next);

    return 0;
}