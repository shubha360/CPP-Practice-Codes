// IF MORE THAN ONE RECURSIVE FUNCTIONS CALL THEMSELVES CYCLICALLY THAN THIS IS CALLED INDIRECT RECURSION

#include<iostream>

void recursionA(int n);
void recursionB(int n);

void recursionA(int n) {
    if (n != 0) {
        std :: cout << "A - " <<  n << std :: endl;
        recursionB(n-1);
    }
}

void recursionB(int n) {
    if (n != 1) {
        std :: cout << "B - " << n << std :: endl;
        recursionA(n/2);
    }
}

int main() {

    recursionA(20);
    return 0;
}