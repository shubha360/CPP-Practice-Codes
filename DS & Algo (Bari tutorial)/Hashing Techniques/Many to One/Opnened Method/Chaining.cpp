#include<iostream>
#include<vector>

using namespace std;

class Node {

    public:

    int data;
    Node* next;

    Node (int data) {

        this -> data = data;
        this -> next = nullptr;
    }
};

void insertNode(vector<Node*> &ht, int data) {

    int hash = data % 10;

    Node* temp = new Node(data);


    if (!ht[hash])
        ht[hash] = temp;

    else {

        Node* p = ht[hash];

        while (p -> next)
            p = p -> next;

        p -> next = temp;
    }
}

bool hash_search(vector<int> vec, int key) {

    vector<Node*> hashTable(10, nullptr);

    for (int i : vec)
        insertNode(hashTable, i);

    int hash = key % 10;

    Node* p = hashTable[hash];

    while (p) {

        if (p -> data == key)
            return 1;
        p = p -> next;
    }
    return 0;
}

void initVec(vector<int> &vec, int *arr, int n) {

    for (int i = 0; i < n; i++)
        vec.push_back(arr[i]);
}

int main() {

    vector<int> vec;

    int arr[12] = {56,23,85,75,596,458,121,45,79,331,333,994};

    initVec(vec, arr, 12);

    hash_search(vec,994) == 1 ? cout << "Element is found." << endl : cout << "Element is not found." << endl;

    return 0;
}