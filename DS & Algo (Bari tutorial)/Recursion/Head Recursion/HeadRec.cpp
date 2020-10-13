// IF THE FIRST STATEMENT OF A RECURSIVE FUNCTION IS THE RECURSIVE CALL THEN THIS IS HEAD RECURSION.

#include<iostream>

void recursion(int n) {
    if (n != 0) {
        recursion(n-1);
        std :: cout << n << std :: endl;
    }
}

int main() {
    recursion(5);
    return 0;
}