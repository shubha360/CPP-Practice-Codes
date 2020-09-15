#include<iostream>

using namespace std;

int main() {

    int input;

    cout<<"Enter a number : ";
    cin>>input;
    
    for (int i = 1; i<=10; i++) {

        cout<<input<<" X "<<i<<" : "<<input*i<<endl;
    }

    return 0;
}