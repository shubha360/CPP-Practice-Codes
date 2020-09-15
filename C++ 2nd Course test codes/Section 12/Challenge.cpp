#include<iostream>

// Function prototypes
void printArray(const int *array, size_t size);
int *applyArray(int *array1, size_t size1, int *array2, size_t size2);

// 1. Function for printing array
void printArray(const int *array, size_t size) {

    for(size_t i = 0; i < size; i++)
        std :: cout << array[i] << " ";

    std :: cout << std :: endl;
}

// 2. Function for multiplying two arrays
int *applyArray(int *array1, size_t size1, int *array2, size_t size2) {

    int *newArray = new int[size1 * size2];

    int index = 0;

    for(size_t i = 0; i < size1; i++) {
        for(size_t j = 0; j < size2; j++) {
            newArray[index] = array1[i] * array2[j];
            index++;
        }
    }
    return newArray;
}

// Main function
int main() {

    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};

    printArray(array1, 5);
    printArray(array2, 3);

    int *arrayPtr = applyArray(array1, 5, array2, 3);

    printArray(arrayPtr, 15);

    delete [] arrayPtr;
    return 0;
}