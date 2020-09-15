#include<iostream>

using namespace std;

// Eligible for offer if age < 16 && age > 34

int main() {

    int age;
    string output;

    cout<<"Enter your age : ";
    cin>>age;

    if (age < 0) {
        cout<<"Invalid age.";
    }
    else if(age < 16 || age > 34) {
        cout<<"You're eligible for the offer.";
    } else {
        cout<<"Sorry you're not eligible for the offer.";
    }

    return 0;
}