#include<iostream>

using namespace std;

int nCr(int n, int r) {

    if(r == 0 || r == 1)
        return 1;
    return nCr(n-1, r-1) + nCr(n-1, r);
}

int main() {

    cout << nCr(4, 3);
}