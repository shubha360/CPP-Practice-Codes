#include<iostream>

using namespace std;

// The smaller number keeps substracting from bigger number until both numbers are even.

int main() {

    int a, b;

    cout << "Enter two numbers : ";
    cin >> a >> b;

    while(a != b) {

        if(a>b) {
            a = a-b;
        } else if (a<b) {
            b = b-a;
        }
    }

    cout<<"GCD is "<<a;

    return 0;
}