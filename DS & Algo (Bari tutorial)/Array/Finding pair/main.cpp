#include<iostream>

using namespace std;

// Finding pair which sums up to k
void pair1(int *arr, int length, int k) {

    for (int i = 0; i < length - 1; i++) {

        if (arr[i] < k) {
            for (int j = i + 1; j < length; j++) {
                if (arr[i] + arr[j] == k)
                    cout << arr[i] << " + " << arr[j] << " = " << k << endl;
            }
        }
    }
}

// Finding pair which sums up to k using hashing
void pair2(int *arr, int length, int k) {

    int hashArray[k] {0};

    for (int i = 0; i < length; i++) {
        if (arr[i] < k)
            hashArray[arr[i]]++;
    }

    for (int i = 0; i < length; i++) {
        if (arr[i] < k) {
            if (hashArray[k-arr[i]] == 1) {
                cout << arr[i] << " + " << k-arr[i] << " = " << k << endl;
                hashArray[arr[i]]++;
            }
        }
    }
}

// Finding pair which sums up to k in a sorted array
void pair3(int *arr, int length, int k) {

    int i = 0, j = length - 1;
    
    while (i < j) {

        if(arr[i] + arr[j] == k) {

            cout << arr[i] << " + " << arr[j] << " = " << k << endl;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] < k)
            i++;
        else
            j--;
    }
}

int main() {

    int A[7] {2,3,7,8,9,17,18};

    pair2(A, 7, 10);

    return 0;
}