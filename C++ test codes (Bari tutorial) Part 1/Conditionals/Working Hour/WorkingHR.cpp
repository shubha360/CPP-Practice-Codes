#include<iostream>

using namespace std;

// In 0-23, working hour is 9-18

int main() {

    int input;

    cout<<"Enter an hour between 0 to 23 : ";
    cin>>input;

    if(input > 23 || input < 0) {
        cout<<"Invalid hour!";
        return 0;
    }
    if (input >= 9 && input <= 18){
        cout<<"Working hour! Take an appointment.";
    } 
    else {
        cout<<"Try again! It's the leisure time.";
    }

    return 0;
}