#include<iostream>

using namespace std;

int main() {

    int initNumber, number, reversed = 0;

    cout<<"Enter a initNumber : ";
    cin>>initNumber;

    number = initNumber;

    while(initNumber != 0) {

        int digit = initNumber%10;
        initNumber /= 10;

        reversed = reversed * 10 + digit;
    }

    cout<<"Reversed : "<< reversed<<endl;

    if(reversed == number) {
        cout<<"It's a palindrome number.";
    } else {
        cout<<"It's not a palindrome number.";
    }
    

    return 0;
}