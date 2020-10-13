#include<iostream>

int sumUp(int n) {
    if (n == 0)
        return 0;
    return sumUp(n-1) + n;
}

int main() {
    std :: cout << sumUp(5);
    return 0;
}