//      1   2   3   4   5

// 1    2   3   0   0   0 
// 2    1   2   3   0   0
// 3    0   1   2   3   0
// 4    0   0   1   2   3
// 5    0   0   0   1   2

#include<iostream>

using namespace std;

class TriDiagonal {

    private:

    int n;
    int * ptr;

    public:

    TriDiagonal(int n);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~TriDiagonal();
};

TriDiagonal :: TriDiagonal(int n) {

    this -> n = n;

    int size = 3*n-2;
    this -> ptr = new int[size];

    for (int i = 0; i < size; i++)
        ptr[i] = 0;
}

void TriDiagonal :: set(int i, int j, int x) {
    
    if ((i >= 1 && i <= n) && (j >= 1 && j <= n)) {

        if (i - j == 1)
            ptr[j-1] = x;
        else if (i == j)
            ptr[n + j - 2] = x;
        else if (i - j == -1)
            ptr[2 * n + i - 2] = x;
    }
}

int TriDiagonal :: get(int i, int j) {

    if ((i >= 1 && i <= n) && (j >= 1 && j <= n)) {

        if (i - j == 1)
            return ptr[j-1];
        else if (i - j == 0)
            return ptr[n + j - 2];
        else if (i - j == -1)
            return ptr[2 * n + i - 2];
        else
         return 0;
    }
    cout << "Invalid index ";
    return -1;
}

void TriDiagonal :: display() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            
            if (i - j == 1)
                cout << ptr[j-1] << " ";
            else if (i - j == 0)
                cout << ptr[n + j - 2] << " ";
            else if (i - j == -1)
                cout << ptr[2 * n + i - 2]<< " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

TriDiagonal :: ~TriDiagonal() {
    delete[] ptr;
}

int main() {

    TriDiagonal tr(5);

    tr.set(1,1,2);
    tr.set(1,2,3);
    tr.set(2,1,1);
    tr.set(2,2,2);
    tr.set(2,3,3);
    tr.set(3,2,1);
    tr.set(3,3,2);
    tr.set(3,4,3);
    tr.set(4,3,1);
    tr.set(4,4,2);
    tr.set(4,5,3);
    tr.set(5,4,1);
    tr.set(5,5,2);
    
    tr.display();

    return 0;
}