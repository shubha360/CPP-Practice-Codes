#include<iostream>

using namespace std;

int main() {

    string str = "Hello World!";

    cout << str.length() << endl;
    cout << str.size() << endl;
    cout << str.capacity() << endl;
    str.resize(100);
    cout << str.capacity() << endl;
    cout << str.max_size() << endl;
    cout << str.find_first_of("o", 5);

}