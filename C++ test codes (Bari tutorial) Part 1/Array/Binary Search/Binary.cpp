#include<iostream>

using namespace std;

int main() {

    int array[10] = {6,8,13,17,20,22,25,28,30,35};

    int key, low = 0, high = 9, mid;

    cout << "Enter a key to search : ";
    cin >> key;

    while(low <= high) {

            mid = (low + high) / 2;

            if (key == array[mid]) {
                cout << "Key is found at " << mid;
                return 0;
            } else if (key < array[mid]) {
                high = mid - 1;
            } else if (key > array[mid]) {
                low = mid + 1;
            }
    }
    cout << "Key doesn't exist in the array.";

    return 0;
}