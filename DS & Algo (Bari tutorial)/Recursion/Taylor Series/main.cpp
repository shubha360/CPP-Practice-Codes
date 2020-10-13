#include<iostream>

using namespace std;

// BASIC
double eX(int x, int n) {

    static double p = 1, f = 1;
    double r;
    
    if (n == 0)
        return 1;
    else {
        r = eX(x, n-1);
        p *= x;
        f *= n;
        return r + p/f; 
    }
}

// LOOP

double eXl(int x, int n) {

    double result = 1;
    
    for (int i = n; i > 0; i--) {
        result = 1 + x/i * result;
    }
    
    return result;
}

int main() {
    cout << eXl(3, 10);
    return 0;
}