#include<iostream>

using namespace std;

// 0 1 1 2 3 5 8 13 21
// 0 1 2 3 4 5 6 7  8

// Fibonacci function using loop
int fib1(int n) {

    if (n == 0 || n == 1)
        return n;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Fibonacci function using recursion
int fib2(int n) {
    if (n == 0 || n == 1)
        return n;

    return fib2(n-2) + fib2(n-1);
}

int main() {

    cout << fib2(7) << endl;

    return 0;
}