#include<iostream>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}


int min(int x, int y) {
    return x < y ? x : y;
}

int main() {

    int a, b;
    cout << "Enter two numbers : ";
    cin >> a >> b;

    int (*fptr)(int, int);

    fptr = min;

    cout << "Min is : " << (*fptr)(a,b) << endl;

    fptr = max;

    cout << "Max is : " << (*fptr)(a,b) << endl;

    return 0;
}