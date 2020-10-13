//      1  2  3  4  5

// 1    11 00 00 00 00
// 2    21 22 00 00 00
// 3    31 32 33 00 00
// 4    41 42 43 44 00
// 5    51 52 53 54 55


#include<iostream>

using namespace std;

class LowerTriangular {

    private:
    
    int n;
    int * ptr;

    public:

    LowerTriangular(int n);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~LowerTriangular();
};

LowerTriangular :: LowerTriangular(int n) {

    this -> n = n;

    int size = n*(n+1)/2;
    this -> ptr = new int[size];

    for (int i = 0; i < size; i++)
        ptr[i] = 0;
}

void LowerTriangular :: set(int i, int j, int x) {

    if (((i >= 1 && i <= n) && (j >= 1 && j <= n)) && i >= j) {
        // Row major
        // ptr[i*(i-1)/2 + (j-1)] = x;
        
        // Column major
        // ptr[n*(j-1) - ((j-2) * (j-1))/2 + (i-j)] = x;

        // My formula for column major
        ptr[(n*(n-1)/2) - (((n-(j-2)) * (((n-(j-2))-1)))/2) + (i-j)] = x;
    }

    else
        cout << "Invalid index." << endl;
}

int LowerTriangular :: get(int i, int j) {

    if (((i >= 1 && i <= n) && (j >= 1 && j <= n)) && i >= j) {
        // Row major
        // return ptr[i*(i-1)/2 + (j-1)];
        
        // Column major
        // return ptr[n*(j-1) - ((j-2) * (j-1))/2 + (i-j)];

        // My formula for column major
        return ptr[(n*(n-1)/2) - (((n-(j-2)) * (((n-(j-2))-1)))/2) + (i-j)];
    }

    cout << "Invalid index " << endl;
    return -1;
}

void LowerTriangular :: display() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i >= j) {
                // Row major
                // cout << ptr[i*(i-1)/2 + (j-1)] << " ";

                // Column major
                //cout << ptr[n*(j-1) - ((j-2) * (j-1))/2 + (i-j)] << " ";

                // My formula for column major
                cout << ptr[(n*(n-1)/2) - (((n-(j-2)) * (((n-(j-2))-1)))/2) + (i-j)] << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

LowerTriangular :: ~LowerTriangular() {
    delete [] ptr;
}

int main() {

    LowerTriangular lt1(10);
       
    lt1.set(1,1,1);
    lt1.set(2,1,2);
    lt1.set(2,2,2);
    lt1.set(3,1,3);
    lt1.set(3,2,3);
    lt1.set(3,3,3);
    lt1.set(4,1,4);
    lt1.set(4,2,4);
    lt1.set(4,3,4);
    lt1.set(4,4,4);
    lt1.set(5,1,5);
    lt1.set(5,2,5);
    lt1.set(5,3,5);
    lt1.set(5,4,5);
    lt1.set(5,5,5);
    lt1.set(6,1,6);
    lt1.set(6,2,6);
    lt1.set(6,3,6);
    lt1.set(6,4,6);
    lt1.set(6,5,6);
    lt1.set(6,6,6);
    lt1.set(7,1,7);
    lt1.set(7,2,7);
    lt1.set(7,3,7);
    lt1.set(7,4,7);
    lt1.set(7,5,7);
    lt1.set(7,6,7);
    lt1.set(7,7,7);
    lt1.set(8,1,8);
    lt1.set(8,2,8);
    lt1.set(8,3,8);
    lt1.set(8,4,8);
    lt1.set(8,5,8);
    lt1.set(8,6,8);
    lt1.set(8,7,8);
    lt1.set(8,8,8);
    lt1.set(9,1,9);
    lt1.set(9,2,9);
    lt1.set(9,3,9);
    lt1.set(9,4,9);
    lt1.set(9,5,9);
    lt1.set(9,6,9);
    lt1.set(9,7,9);
    lt1.set(9,8,9);
    lt1.set(9,9,9);
    lt1.set(10,1,10);
    lt1.set(10,2,10);
    lt1.set(10,3,10);
    lt1.set(10,4,10);
    lt1.set(10,5,10);
    lt1.set(10,6,10);
    lt1.set(10,7,10);
    lt1.set(10,8,10);
    lt1.set(10,9,10);
    lt1.set(10,10,10);

    lt1.display();

    return 0;
}