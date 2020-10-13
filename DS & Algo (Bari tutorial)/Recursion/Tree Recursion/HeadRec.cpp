// IF A RECURSIVE FUNCTION CONTAINS MORE THAN ONE RECURSIVE CALL THEN THIS IS TREE RECURSION.

#include<iostream>

int x = 0, y = 0;

void recursion(int n) {
    x++;
    if (n != 0) {
        y++;
        std :: cout << n << " ";
        recursion(n-1);
        std :: cout << n << " ";
        recursion(n-1);
        std :: cout << n << " ";
    }
}

int main() {
    recursion(5);
    std :: cout << std :: endl << x;
       std :: cout << std :: endl << y;
    return 0;
}