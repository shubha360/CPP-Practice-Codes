#include<iostream>
#include<vector>

using namespace std;

class Node {

    public:
    int data;
    Node * next;
};

class LinkedList{

    private:
    Node * head;

    public:

    // Constructor
    LinkedList(vector<int> vec);

    //Accessor
    Node * getHead() {
        return head;
    }

    // Functions
    void display();
    int countNode();
    int sumData();
    int maxData();
    int minData();
    Node * linearSearch(int key);
    Node * improved_linearSearch(int key);
    void insertNode(int position, int data);
    void insertNode_at_last(int data);
    void insertNode_sorted(int data);
    void deleteNode(int position);
    bool isSorted();
    void removeDuplicate();
    void reverse_using_array();
    void reverseList();
    void concatenate(LinkedList *obj);
    void merge(LinkedList *obj);
    const bool isLoop();

    // Distructor
    ~LinkedList();
};

// Constructor
LinkedList :: LinkedList(vector<int> vec) {

    head = new Node;

    head -> data = vec[0];
    head -> next = nullptr;

    Node * last = head;

    for (int i = 1; i < vec.size(); i++) {

        Node * temp = new Node;

        temp -> data = vec[i];
        temp -> next = nullptr;

        last -> next = temp;
        last = temp;
    }
}

// Function for displaying a linked list
void LinkedList :: display() {

    Node * ptr = head;

    if (this -> countNode() == 0) {
        cout << "Head is empty." << endl;
        return;
    }

    while (ptr) {

        cout << ptr -> data << " -> ";
        ptr = ptr -> next;
    }
}

// Function for counting nodes
int LinkedList :: countNode() {

    int count = 0;
    Node * ptr = head;

    while (ptr) {

        count++;
        ptr = ptr -> next;
    }
    return count;
}

// Function for suming up the values of nodes
int LinkedList :: sumData() {

    int sum = 0;
    Node * ptr = head;

    while(ptr) {

        sum += ptr -> data;
        ptr = ptr -> next;
    }
    return sum;
}

// Function finding max value
int LinkedList :: maxData() {

    int max = INT32_MIN;
    Node * ptr = head;

    while(ptr) {

        if (ptr -> data > max)
            max = ptr -> data;

        ptr = ptr -> next;
    }
    return max;
}

// Function finding min value
int LinkedList :: minData() {

    int min = INT32_MAX;
    Node * ptr = head;

    while(ptr) {

        if (ptr -> data < min)
            min = ptr -> data;

        ptr = ptr -> next;
    }
    return min;
}

// Function for linear searching a data
Node * LinkedList :: linearSearch(int key) {

    Node * ptr = head;

    while (ptr) {

        if (ptr -> data == key) {
            
            cout << key << " is found at ";
            return ptr;
        }
        ptr = ptr -> next;
    }
    cout << "Data not found ";
    return nullptr;
}

// Function for improved linear search
Node * LinkedList :: improved_linearSearch(int key) {

    Node * ptr = head;
    Node * temp = nullptr;

    int i = 0;

    while (ptr) {

        i++;
        if (ptr -> data == key) {

            if (i == 1) {

                cout << key << " is found at ";
                return ptr;
            }
            
            else {

                temp -> next = ptr -> next;
                ptr -> next = head;
                head = ptr;
                cout << key << " is found at ";
                return head;
            }
        }
        temp = ptr;
        ptr = ptr -> next;
    }
    cout << "Data not found." << endl;
    return head;
}

// Inserting to linked list
void LinkedList :: insertNode(int position, int data) {

    if (position == 0) {

        Node * newNode = new Node;
        newNode -> data = data;
        newNode -> next = head;
        head = newNode;
        return;
    }
    else if (position > 0) {

        Node * ptr = head;

        for (int i = 1; i < position && ptr; i++)
            ptr = ptr -> next;

        if (ptr) {

            Node * newNode = new Node;
            newNode -> data = data;
            newNode -> next = ptr -> next;
            ptr -> next = newNode;
            return;
        }
    }
}

// Always inserting node at last
void LinkedList :: insertNode_at_last(int data) {

    Node * ptr = head;
    
    while (ptr -> next != nullptr)
        ptr = ptr -> next;
    
    Node * newNode = new Node;
    newNode -> data = data;
    newNode -> next = nullptr;

    ptr -> next = newNode;
}

// Insert node in a sorted position
void LinkedList :: insertNode_sorted(int data) {

    Node * p = head;
    Node * q = nullptr;

    Node * newNode = new Node;
    newNode -> data = data;
    newNode -> next = nullptr;
    
    while (p && p -> data < data) {

        q = p;
        p = p -> next;
    }
    
    newNode -> next = q -> next;
    q -> next = newNode;
}

// Delete node in a specified position
void LinkedList :: deleteNode(int position) {

    if (position == 0) {

        Node * ptr = head;
        head = head -> next;
        delete ptr;
        return;
    }
    
    Node * p = head;
    Node * q = nullptr;

    for (int i = 1; i < position && p; i++) {

        q = p;
        p = p -> next;
    }
    
    q -> next = p -> next;
    delete p;
}

// Check if the list is sorted
bool LinkedList :: isSorted() {

    int temp = INT32_MIN;
    Node * ptr = head;

    while (ptr) {

        if (temp > ptr -> data)
            return 0;

        temp = ptr -> data;
        ptr = ptr -> next;
    }
    return 1;
}

// Remove nodes containing duplicate data
void LinkedList :: removeDuplicate() {

    Node * p = head;
    Node * q = head -> next;

    while (q) {

        if (p -> data == q -> data) {

            p -> next = q ->next;
            delete q;
            q = p -> next;
        }
        else {
            p = q;
            q = q -> next;
        }
    }
}

// Reversing list using array
void LinkedList :: reverse_using_array() {

    Node * ptr = head;

    vector<int> temp;

    while (ptr) {
        
        temp.push_back(ptr -> data);
        ptr = ptr -> next;
    }
    
    ptr = head;
    int i = temp.size() - 1;

    while(ptr) {
        
        ptr -> data = temp[i];
        i--;
        ptr = ptr -> next;
    }
}

// Reversing list
void LinkedList :: reverseList() {

    Node * p = head;
    Node * q = nullptr;
    Node * r = nullptr;

    while (p) {

        r = q;
        q = p;
        p = p -> next;
        q -> next = r;
    }
    head = q;
}

// Concatenate two lists
void LinkedList :: concatenate(LinkedList *obj) {

    Node * first = head;

    while (first -> next != nullptr)
        first = first -> next;

    first -> next = obj -> getHead();
    obj -> ~LinkedList();
}

// Merging two lists
void LinkedList :: merge(LinkedList *obj) {

    Node *result, *last;
    Node * second = obj -> getHead();

    if (head -> data <= second -> data) {

        result = last = head;
        head = head -> next;
        last -> next = nullptr;
    }
    else {

        result = last = second;
        second = second -> next;
        last -> next = nullptr;
    }

    while (head && second) {

        if (head -> data <= second -> data) {
        
            last -> next = head;
            head = head -> next;
            last = last -> next;
            last -> next = nullptr;
        }
        else {

            last -> next = second;
            second = second -> next;
            last = last -> next;
            last -> next = nullptr;
        }
    }
    
    last -> next = head ? head : second;

    obj -> ~LinkedList();
    head = result;
}

// Check if a linked list is looped
const bool LinkedList :: isLoop() {
    
    Node *p, *q;
    p = q = head;
    bool res;

    do {
        p = p -> next;
        q = q -> next;
        if (q)
            q = q -> next;
        else 
            return 0;
    } while ((p && q) && (p != q));

    if (p == q)
        return 1;

    return 0;
}

// Destructor
LinkedList :: ~LinkedList() {

    Node *ptr = head;

    while(ptr) {
        
        head = head -> next;
        delete ptr;
        ptr = head;
    }
}

// Global function for creating a linked list
Node * createLinkedList(vector<int> vec) {

    Node * head = new Node;

    head -> data = vec[0];
    head -> next = nullptr;

    Node * last = head;

    for (int i = 1; i < vec.size(); i++) {

        Node * temp = new Node;

        temp -> data = vec[i];
        temp -> next = nullptr;

        last -> next = temp;
        last = temp;
    }
    return head;
}

// Display function using recursion
void rec_display(Node * head) {

    if (!head)
        return;

    cout << head -> data << " -> ";
    return rec_display(head -> next);
}

// countNode function using recursion
int rec_countNode(Node * head) {

    if (!head)
        return 0;
    return rec_countNode(head -> next) + 1;
}

// sumData function using recursion
int rec_sumData(Node * head) {

    if (!head)
        return 0;

    return rec_sumData(head -> next) + head -> data;
}


// maxData function using recursion
int rec_maxData(Node * head) {

    int max = 0;

    if (!head)
        return INT32_MIN;
    
    max = rec_maxData(head -> next);

    return max > head -> data ? max : head -> data;
}

// minData function using recursion
int rec_minData(Node * head) {

    int min = 0;

    if (!head)
        return INT32_MAX;
    
    min = rec_maxData(head -> next);

    return min < head -> data ? min : head -> data;
}


// linearSearch function using recursion
Node * rec_linearSearch(Node * head,int key) {

    if (!head) {

        cout << "Data not found ";
        return nullptr;
    }

    else if (head -> data == key)
        return head;
    return rec_linearSearch(head -> next, key);
}

// Check if a list is looped
const bool isLoop(Node * head) {
    
    Node *p, *q;
    p = q = head;

    do {
        
        p = p -> next;
        q = q -> next;
        q = q ? q -> next : q;
    } while ((p && q) && (p != q));

    if (p == q)
        return 1;

    return 0;
}

int main() {

    vector<int> vec;
    vector<int> vec2;

    // for (int i = 1; i <= 15; i++)
    //     vec.push_back(i);

    // for (int i = 16; i <= 25; i++)
    //     vec2.push_back(i);

    // vec.push_back(1);
    // vec.push_back(3);
    // vec.push_back(4);
    // vec.push_back(7);
    // vec.push_back(8);
    // vec.push_back(14);

    vec2.push_back(2);
    vec2.push_back(5);
    vec2.push_back(6);
    vec2.push_back(9);

    // Node * head1 = createLinkedList(vec);
    // Node * head2 = createLinkedList(vec2);

    // LinkedList l1(vec);
    LinkedList l2(vec2);

    l2.display();
    cout << endl;

    l2.insertNode_sorted(10);

    l2.display();
    cout << endl;

    return 0;
}