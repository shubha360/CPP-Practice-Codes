#include<iostream>

using namespace std;

// If sum of each digit^3 == initial number then it's a armstrong number.

int main() {
    
    int initNumber, number, sum = 0;

    cout << "Enter a number : ";
    cin >> initNumber;

    number = initNumber;

    while(initNumber != 0) {

        int digit = initNumber % 10;

        sum = sum + digit * digit * digit;

        initNumber /= 10;
    }

    if(sum == number) {
        cout << "This is an armstrong number";
    } else {
        cout << "This is not an armstrong number"<<endl;
        cout<<"Sum is "<<sum;
    }

    return 0;
}
