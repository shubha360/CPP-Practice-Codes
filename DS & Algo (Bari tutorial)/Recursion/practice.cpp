#include<iostream>

using namespace std;

// Sum of numbers from m to n using loop
int sum1(int m, int n) {

    int sum = 0;
    
    for (int i = m; i <= n; i++)
        sum += i;

    return sum;
}

// Sum of numbers from m to n using recursion
int sum2(int m, int n) {

    static int temp = 0;

    if (m <= n) {
        temp += m;
        sum2(m+1, n);
    }
    return temp;
}

// Sum of numbers from m to n using recursion 2
int sum3(int m, int n) {

    if (m == n)
        return m;
    return sum3(m+1, n) + m;
}

// Factorial using loop
int fact1(int n) {

    if (n == 0)
        return 1;
    
    int temp = 1;

    for (int i = n; i != 1; i--)
        temp *= i;
    
    return temp;
}

// Factorial using recursion
int fact2(int n) {

    if (n == 0)
        return 1;
    return n * fact2(n-1);
}

// Exponent of m to n using loop
int expo1(int m, int n) {

    if (n == 0)
        return 1;
    
    int temp = m;

    for (int i = 1; i != n; i++)
        temp *= m;

    return temp;
}

// Exponent of m to n using recursion
int expo2(int m, int n) {

    if (n == 0)
        return 1;
    return expo2(m, n-1) * m;
}

// Faster exponent of m to n using recursion
int expo3(int m, int n) {

    if (n == 0)
        return 1;
    else if (n == 1)
        return m;
    else if (n % 2 ==0)
        return expo3(m * m, n/2);
    else
        return m * expo3(m * m, (n-1)/2);
}

// 0 1 1 2 3 5 8 13 21
// 0 1 2 3 4 5 6 7  8

// Fibonacci using loop - my solution
int fib1(int n) {

    if (n == 0 || n == 1)
        return n;
    
    int a = 0, b = 1, c;

    for (int i = 0; i < n - 1; i++) {
        
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Fibonacci using recursion
int fib2(int n) {

    if (n == 0 || n == 1)
        return 1;
    return fib2(n-2) + fib2(n-1);
}

// nCr - Combination using recursion
int nCr(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    return nCr(n-1,r-1) + nCr(n-1,r);
}

int main() {

    cout << nCr(3,2) << endl;

    return 0;
}