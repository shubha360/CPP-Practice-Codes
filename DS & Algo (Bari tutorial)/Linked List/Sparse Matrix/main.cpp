

// This is incomplete

#include<iostream>

using namespace std;

class Node {

    public:

    int column;
    int value;
    Node *next;
};

class Sparse {

    private:

    int totalRow;
    int totalColumn;
    Node *storage;

    public:

    Sparse(int totalRow, int totalColumn);
    void store(int row, int column, int value);
    void display();
    void add(Sparse obj);
    ~Sparse();
};


Sparse :: Sparse(int totalRow, int totalColumn) {

    this -> totalRow = totalRow;
    this -> totalColumn = totalColumn;

    this -> storage = new Node[totalRow];

    for (int i = 0; i < totalRow; i++)
        storage[i] = nullptr;
}

void Sparse :: store(int row, int column, int value) {

    if (row < (totalRow - 1) || column < (totalColumn - 1)) {
        
        cout << "Invalid input."<< endl;
        return;
    }

    Node *temp = new Node;
    temp -> column = column;
    temp -> value = value;
    temp -> next = nullptr;

    storage[row] = temp;
}

Sparse :: ~Sparse() {
    delete[] storage;
}