#include<iostream>

using std :: cout;
using std :: endl;

int main() {

    cout << "Size of int - " << sizeof(int) << endl;
    cout << "Size of char - " << sizeof(char) << endl;
    cout << "Size of boolean - " << sizeof(bool) << endl;
    cout << "Size of double - " << sizeof(double) << endl;
    cout << "Size of float - " << sizeof(float) << endl;

    cout << "Minimum of char - " << CHAR_MIN << endl;
    cout << "Minimum of int - " << INT_MIN << endl;

    return 0;
}