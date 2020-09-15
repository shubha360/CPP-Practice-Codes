#include<iostream>

using namespace std;

int main() {

    int array[10];

    cout << "Enter 10 integers each seperated by ap space : ";

    for(int i = 0; i < 10; i++) {

        cin >> array[i];
    }

    int sum = 0;

    for(auto x : array) {

        sum += x;
    }

    cout << "Sum is " << sum;

    return 0;
}