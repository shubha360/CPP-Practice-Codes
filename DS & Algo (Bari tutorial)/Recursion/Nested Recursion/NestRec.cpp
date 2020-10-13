// IF A RECURSIVE FUNCTION USES RECURSIVE CALL AS PARAMETER THAN THIS IS NESTED RECURSION;

#include<iostream>

int recursion(int n) {
    if (n >  100)
        return n - 10;
    
    return recursion(recursion(n+11));
}

int main() {
    std :: cout << recursion(1);
    return 0;
}