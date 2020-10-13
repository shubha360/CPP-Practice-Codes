//     1  2  3  4  5

// 1   11 00 00 00 00
// 2   00 22 00 00 00
// 3   00 00 33 00 00
// 4   00 00 00 44 00
// 5   00 00 00 00 44

#include<iostream>

using namespace std;

class Diagonal {
    
    private:
    int n;
    int * ptr;

    public:
    Diagonal(int n);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Diagonal();
};

Diagonal :: Diagonal(int n) {
    
    this -> n = n;
    this -> ptr = new int[n];

    for (int i = 0; i < n; i++)
        ptr[i] = 0;
}

void Diagonal :: set(int i, int j, int x) {

    if (((i >= 1 && i <= n) && (j >= 1 && j <= n)) && i == j)
        ptr[i-1] = x;

    else
        cout << "Invalid index error code " << endl;
}

int Diagonal :: get(int i, int j) {
    
    if (((i >= 1 && i <= n) && (j >= 1 && j <= n)) && i == j)
        return ptr[i-1];

    cout << "Invalid index ";
    return -1;
}

void Diagonal :: display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << ptr[i-1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

Diagonal :: ~Diagonal() {
    delete [] ptr;
}

int main() {

    Diagonal d1(5);

    d1.set(1,1,1);
    d1.set(2,2,2);
    d1.set(3,3,3);
    d1.set(4,4,4);
    d1.set(5,5,5);
    
    d1.display();

    Diagonal d2(3);

    d2.set(1,1,1);
    d2.set(2,2,2);
    d2.set(3,3,3);

    d2.display();

    return 0;
}