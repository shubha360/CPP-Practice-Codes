#include<iostream>

using namespace std;

// Finding single missing element from array of first N natural numbers
int missing1(int *arr, int length) {

    int n = arr[length - 1];
    int sum = n * (n+1) / 2;
    int total = 0;

    for (int i = 0; i < length; i++)
        total += arr[i];

    return sum - total;
}

// Finding single missing element from any sorted array
int missing2(int *arr, int length) {

    int missing = 0;
    for (int i = 0; i < length - 1; i++) {
        if ((arr[i] + 1) != arr[i+1])
            missing = (arr[i] + 1);
    }
    return missing;
}

//Finding multiple missing element from an sorted array
void missing3(int *arr, int length) {

    int dif = arr[0];
    for (int i = 0; i < length; i++) {
        if (arr[i] - i != dif) {
            int newDif = arr[i] - i;
            while (dif < newDif)
            {
                cout << dif + i << endl;
                dif++;
            }            
        }
    }
}

//Finding single or multiple missing elements from an unsorted array using hashing
void missing4(int *arr, int length, int max, int min) {

    int newLength = (max - min) + 1;

    int newArr[newLength] {0};

    int dif = min;
    for(int i = 0; i < length; i++) {
        int temp = arr[i];
        newArr[temp - dif] = 1;
    }

    for (int i = 0; i < newLength; i++) {

        if (newArr[i] == 0)
            cout << i + dif << endl;
    }
}

int main() {

    int arr[6] {4,15,7,10,6,12};

    missing4(arr, 6, 15, 4);

    return 0;
}