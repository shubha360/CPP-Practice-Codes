#include<iostream>

using namespace std;

// A number is perfect if sum of factors == number*2

int main() {

    int input, sum = 0;

    cout<<"Enter a number : ";
    cin>>input;

    for(int i = 1; i <= input; i++) {

        if(input % i == 0) {
            cout<<i<<endl;
            sum += i;
        }
    }

    cout<<"Sum of Factor is : "<<sum<<endl;

    if(sum == input*2) {

        cout<<"This is a perfect number.";
    } 
    else {
        cout<<"This is not a perfect number.";
    }

    return 0;
}