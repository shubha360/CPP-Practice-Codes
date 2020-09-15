#include<iostream>

using namespace std;

int main() {

    int count = 1, n;

    cout<<"Enter N : ";
    cin>>n;

    // while(count <= n) {
    //     cout<<count<<endl;
    //     count++;
    // }

    do {
        cout<<count<<endl;
        count++;
    } while(count <= n);

    return 0;
}