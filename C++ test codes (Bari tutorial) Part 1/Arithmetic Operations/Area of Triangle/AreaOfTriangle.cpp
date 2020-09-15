#include<iostream>

using namespace std;

int main() {

    int base, height;
    double area;

    cout<<"Enter integer value of base: ";
    cin>>base;
    cout<<"\n";

    cout<<"Enter integer value of height: ";
    cin>>height;
    cout<<"\n";
    
    area = (double) (base*height)/2;

    cout<<"Area is: "<<area;

    return 0;
}