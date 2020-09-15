#include<iostream>

using namespace std;

int main() {

    int x, y;

    cout<<"Enter X and Y : ";
    cin>>x>>y;

    if(x == y) {
        cout<<"They are equal.";
    }
    if(x>y) {
        cout<<"X is greater.";
    } if(y>x) {
        cout<<"Y is greater.";
    }

    return 0;
}