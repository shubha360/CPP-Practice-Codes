#include<iostream>

using namespace std;

int main() {

    int array[15] = {75,45,82,58,55,85,62,6247,84,2254,215,632,2,226,42};

    int key;

    cout << "Enter search key : ";
    cin>>key;

    for(int i = 0; i < 15; i++) {

        if(key == array[i]) {
            cout << "Found at position " << i;
            return 0;
        }
    }

    cout << "Key doesn't exist in the array";

    return 0;
}