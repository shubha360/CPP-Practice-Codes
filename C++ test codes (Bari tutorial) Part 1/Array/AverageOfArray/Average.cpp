#include<iostream>

using namespace std;

int main() {

    int array[1000], total = 0, counter;
    double average = 0;

    cout << "Enter number of elements (max 1000) : ";
    cin >> counter;
    
    for (int i = 0; i < counter; i++) {

        cout << "Enter number " << i+1 << " : ";
        cin >> array[i];

        total += array[i];
    }

    average = total / (double) counter;
    cout << "Average is "<< average;
    
    return 0;
}