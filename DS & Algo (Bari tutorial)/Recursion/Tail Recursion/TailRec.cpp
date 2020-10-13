// WHEN THE RECURSIVE CALL IS THE LAST STATEMENT OF THE RECURSIVE FUNCTION, THEN IT IS CALLED TAIL RECURSION.

#include<iostream>

void recursion(int n) {
    if (n != 0) {
        std :: cout << n << std :: endl;
        recursion(n-1);
    }
}

int main() {
    
    recursion(5);
    return 0;
}