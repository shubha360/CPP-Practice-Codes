//      1   2   3   4   5

// 1    11  12  13  14  15
// 2    00  22  23  24  25
// 3    00  00  33  34  35
// 4    00  00  00  44  45
// 5    00  00  00  00  55

#include<iostream>

using namespace std;

class UpperTriangular{
    
    private:

    int n;
    int * ptr;

    public:

    UpperTriangular(int n);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~UpperTriangular();
};

UpperTriangular :: UpperTriangular(int n) {
    
    this -> n = n;
   
    int size = n*(n+1)/2;
    this -> ptr = new int[size];

    for (int i = 0; i < size; i++)
        ptr[i] = 0;
}

void UpperTriangular :: set(int i, int j, int x) {
    
    if (((i >= 1 && i <= n) && (j >= 1 && j <= n)) && i <= j) {
        
        // Column major
        ptr[j*(j-1)/2 + (i-1)] = x;

        // My formula for row major
        ptr[(n*(n-1)/2) - (((n-(i-2)) * (((n-(i-2))-1)))/2) + (j-i)] = x;
    }

    else
        cout << "Invalid index." << endl;
}

int UpperTriangular :: get(int i, int j) {

    // Column major
    // return ptr[j*(j-1)/2 + (i-1)];

    // My formula for row major
    return ptr[(n*(n-1)/2) - (((n-(i-2)) * (((n-(i-2))-1)))/2) + (j-i)];
}

void UpperTriangular :: display() {

    for (int i = 1; i <= n; i++) {
        for (int j= 1; j <= n; j++) {
                       
            if (i <= j)

                // Column major
                // cout << ptr[j*(j-1)/2 + (i-1)] << " ";
            
                // My formula for row major
                cout << ptr[(n*(n-1)/2) - (((n-(i-2)) * (((n-(i-2))-1)))/2) + (j-i)] << " ";

            else 
                cout << "0 ";
        }
        cout << endl;
    }
}

UpperTriangular :: ~UpperTriangular() {
    delete [] ptr;
}

int main() {
    
    UpperTriangular up1(5);

    up1.set(1,1,1);
    up1.set(1,2,1);
    up1.set(1,3,1);
    up1.set(1,4,1);
    up1.set(1,5,1);
    up1.set(2,2,2);
    up1.set(2,3,2);
    up1.set(2,4,2);
    up1.set(2,5,2);
    up1.set(3,3,3);
    up1.set(3,3,3);
    up1.set(3,4,3);
    up1.set(3,5,3);
    up1.set(4,4,4);
    up1.set(4,5,4);
    up1.set(5,5,5);

    up1.display();
    
    return 0;
}