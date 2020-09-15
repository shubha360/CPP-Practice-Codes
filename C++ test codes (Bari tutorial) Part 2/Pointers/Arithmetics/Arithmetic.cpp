#include<iostream>

using namespace std;

int main() {

    int A[5] = {2,4,6,8,10};
    int *p = A;

    cout << "p : " << p << endl;
    cout << "*p : " << *p << endl;

    return 0;
}