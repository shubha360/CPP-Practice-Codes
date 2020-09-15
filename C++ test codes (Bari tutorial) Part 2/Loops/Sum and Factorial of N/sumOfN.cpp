#include<iostream>

using namespace std;

int main() {

    int input, sum = 0, factorial = 1;

    cout<<"Enter a number : ";
    cin>>input;

    for(int i = 1; i<=input; i++) {

        sum+=i;

        factorial*=i;
    }

    cout<<"Sum is "<<sum<<endl;
    cout<<"Factorial is "<<factorial;

    return 0;
}