#include<iostream>

using namespace std;

// Finding single duplicate in a sorted array
int duplicate1(int *arr, int length) {

    int duplicate = 0;
    for (int i = 0; i < length - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            duplicate = arr[i];
            break;
        }
    }
    return duplicate;
}

// Finding mutiple duplicate and count in a sorted array using hashing
void duplicate2(int *arr, int length, int max, int min) {

    int newLength = (max - min) + 1;

    int newArr[newLength] {0};

    int dif = min;

    for(int i = 0; i < length; i++)
        newArr[arr[i] - dif]++;

    for (int i = 0; i < newLength; i++) {

        if (newArr[i] > 1)
            cout << i + dif << endl;
    }
}

// Finding multiple duplicate in an unsorted array
void duplicate3(int *arr, int length) {

    for (int i = 0; i < length - 1; i++) {

        int count = 1;
        if (arr[i] != -1) {
            for (int j = i + 1; j < length; j++) {
                if (arr[j] == arr[i]) {
                    count++;
                    arr[j] = -1;
                }
            }
        }
        if (count > 1)
            cout << arr[i] << endl;
    }
}

int main() {

    int arr[10] {2,3,5,5,7,3,8,1,8,9};

    duplicate3(arr, 10);
    return 0;
}