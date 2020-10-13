//      1   2   3   4   5

// 1    2   2   2   2   2
// 2    2   3   3   3   3
// 3    2   3   4   4   4
// 4    2   3   4   5   5
// 5    2   3   4   5   6

#include<iostream>

using namespace std;

class Symmetric {

    private:

    int n;
    int * ptr;

    public:

    Symmetric(int n);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Symmetric();
};

Symmetric :: Symmetric(int n) {

    this -> n = n;

    int size = n*(n+1)/2;
    this -> ptr = new int[size];

    for (int i = 0; i < size; i++)
        ptr[i] = 0;
}

void Symmetric :: set(int i, int j, int x) {

    if ((i >= 1 && i <= n) && (j >= 1 && j <= n)) {

        if (i >= j)
        ptr[i*(i-1)/2 + (j-1)] = x;
        else
        cout << "Invalid index for symmetric." << endl;
    }
}

int Symmetric :: get(int i, int j) {

    if ((i >= 1 && i <= n) && (j >= 1 && j <= n) && (i >= j))
        return ptr[i*(i-1)/2 + (j-1)];

    cout << "Invalid index." << endl;
    return -1;
}

void Symmetric :: display() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i >= j)
            cout << ptr[i*(i-1)/2 + (j-1)] << " ";
            else
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

Symmetric :: ~Symmetric() {
    delete[] ptr;
}

int main() {

    Symmetric s(5);

    s.set(1,1,2);
    s.set(2,1,2);
    s.set(2,2,3);
    s.set(3,1,2);
    s.set(3,2,3);
    s.set(3,3,4);
    s.set(4,1,2);
    s.set(4,2,3);
    s.set(4,3,4);
    s.set(4,4,5);
    s.set(5,1,2);
    s.set(5,2,3);
    s.set(5,3,4);
    s.set(5,4,5);
    s.set(5,5,6);

    s.display();

    return 0;
}