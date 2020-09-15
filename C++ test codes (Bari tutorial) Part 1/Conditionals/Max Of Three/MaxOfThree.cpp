#include<iostream>

using namespace std;

int main() {

    int a, b, c;

    cout<<"Enter three numbers (each should be separated by an space) : ";
    cin>>a>>b>>c;

    if(a == b) {
        if(b == c) {
            cout<<"The numbers are equal.";
            return 0;
        }
        if (b > c) {
            cout<<"Max value is "<<b;
            return 0;
        }
    }
    if(a>b) {
        if(a>c) {
            cout<<"Max value is "<<a;
            return 0;
        }
        else {
            cout<<"Max value is "<<a;
        }
        
    }
    if (b>a) {
        if(b>c) {
            cout<<"Max value is "<<b;
            return 0;
        }
        else {
            cout<<"Max value is "<<c;
        }
    }

    return 0;
}