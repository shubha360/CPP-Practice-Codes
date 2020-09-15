#include<iostream>

using namespace std;

int linearSearch(int array[], int key, int n) {

    for(int i = 0; i < n; i++) {

        if(array[i] == key) return i;
    }
    return -1;
}

void printArray(int array[], int n) {

    for(int i = 0; i < n; i++) {
    cout << array[i] << endl;
    }
}

int main() {

    int array[] = {8,7,6,5,4,3,2,1};
    int key, n = 8;

    cout << "Enter key : ";
    cin >> key;

    int index = linearSearch(array, key, n);

    index == -1 ? cout << "Key was not found." << endl : cout << "Key was found at index " << index << endl;

    cout << "Whole array : " << endl;
    printArray(array, n);
    return 0;
}