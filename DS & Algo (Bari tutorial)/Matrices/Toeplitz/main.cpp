//      1   2   3   4   5

// 1    2   3   4   5   6
// 2    7   2   3   4   5
// 3    8   7   2   3   4
// 4    9   8   7   2   3
// 5    10  9   8   7   2

#include<iostream>

using namespace std;

class Toeplitz {

    private:

    int n;
    int * ptr;

    public:

    Toeplitz(int n);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Toeplitz();
};

Toeplitz :: Toeplitz(int n) {
    
    this -> n = n;
    
    int size = 2*n-1;
    this -> ptr = new int[size];

    for (int i = 0; i < size; i++)
        ptr[i] = 0;
}

void Toeplitz :: set(int i, int j, int x) {

    if ((i >= 1 && i <= n) && (j >= 1 && j <= n)) {
        
        if (i <= j)
            ptr[j-i] = x;
        else
            ptr[n+i-j-1] = x;
    }
    else 
        cout << "Invalid index." << endl;
}

int Toeplitz :: get(int i, int j) {

    if ((i >= 1 && i <= n) && (j >= 1 && j <= n)) {
        
        if (i <= j)
            return ptr[j-i];
        else
            return ptr[n+i-j-1];
    }
    cout << "Invalid index ";
    return -1;
}

void Toeplitz :: display() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j)
                cout << ptr[j-i] << " ";
            else
                cout << ptr[n+i-j-1] << " ";
        }
        cout << endl;
    }
}

Toeplitz :: ~Toeplitz() {
    delete [] ptr;
}

int main() {

    Toeplitz tpl(5);

    tpl.set(1,1,1);
    tpl.set(1,2,2);
    tpl.set(1,3,3);
    tpl.set(1,4,4);
    tpl.set(1,5,5);
    tpl.set(2,1,6);
    tpl.set(3,1,7);
    tpl.set(4,1,8);
    tpl.set(5,1,9);

    tpl.display();

    return 0;
}