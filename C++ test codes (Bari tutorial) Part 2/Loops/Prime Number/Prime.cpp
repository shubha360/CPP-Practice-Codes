#include<iostream>

using namespace std;

int main() {

    int number;

    cout<<"Enter a number : ";
    cin>>number;

    for(int i = 2; i < number; i++) {

        if (number % i == 0) {

            cout<<"Not a prime number.";
            return 0;
        }
    }
    cout<<"This is a prime number!";

    return 0;
}