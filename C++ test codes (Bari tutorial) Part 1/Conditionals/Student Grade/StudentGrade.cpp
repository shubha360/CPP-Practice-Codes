#include<iostream>

using namespace std;

typedef int subject;

int main () {

    subject bengali, english, math;

    int average;

    cout<<"Bengali : ";
    cin>>bengali;

    cout<<"English : ";
    cin>>english;

    cout<<"Math : ";
    cin>>math;

    average = (bengali + english + math) / 3;

    if(average > 70) {
        cout<<"Grade is A."<<endl;
    } 
    else if(average > 40) {
        cout<<"Grade is B."<<endl;
    } 
    else {
        cout<<"Grade is C."<<endl;
    }

    cout<<"Average is "<<average;

    return 0;
    
}