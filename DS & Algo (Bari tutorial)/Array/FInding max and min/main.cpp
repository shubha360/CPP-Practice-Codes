#include<iostream>

using namespace std;

// Finding max and min element from array in a single iteration
void maxMin(int arr[], int length) {

    int min, max;
    min = max = arr[0];

    for (int i = 0; i < length; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    cout << "Min : " << min << endl << "Max : " << max << endl;
}

int main() {

    int A[10] {25,59,56,65,2,3,48,23,16,15};
    maxMin(A, 10);

    return 0;
}