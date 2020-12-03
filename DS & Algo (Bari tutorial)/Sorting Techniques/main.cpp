#include<iostream>
#include<cmath>

using namespace std;

// Class for Node data type

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {

        this -> data = data;
        this -> next = nullptr;
    }
};

// Other necessary functions

void displayArray(int arr[], int n) {

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

int findMax(int arr[], int n) {

    int max = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void initZero(int *arr, int n) {

    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

void initNull(Node** bin, int n) {

    for (int i = 0; i < n; i++)
        bin[i] = nullptr;
}

void insertNode(Node** bin, int i, int data) {

    Node* t = new Node(data);

    if (!bin[i])
        bin[i] = t;
    
    else {

        Node *p = bin[i];

        while (p -> next)
            p = p -> next;
        
        p -> next = t;
    }
}

int deleteNode(Node** bin, int i) {

    Node* p = bin[i];
    
    int value = p -> data;

    bin[i] = p -> next;
    delete p;
    return value;
}

// Bubble Sort
void Bubble_Sort(int *arr, int n) {

    for (int i = 0; i < n; i++) {

        int flag = 0;

        for (int j = 0; j < (n-1-i); j++) {
            
            if (arr[j] > arr[j+1]) {
                
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

// Insertion Sort
void Insertion_Sort(int *arr, int n) {

    for (int i = 1; i < n; i++) {

        int j = i;

        while (j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

// Selection Sort
void Selection_Sort(int *arr, int n) {

    for (int i = 0; i < n-1; i++) {

        int j = i + 1, k = i;

        while (j < n) {
            if (arr[j] < arr[k])
                k = j;
            j++;
        }
        if (k != i)
            swap(arr[i], arr[k]);
    }
}

// Quick Sort

int pertition (int *arr, int startIndex, int endindex) {

    int p = startIndex;

    int i = startIndex + 1, j = endindex;

    do {
        
        do {i++;} while (arr[i] <= arr[p]);

        do {j--;} while (arr[j] > arr[p]);

        if (j > i)
            swap(arr[j], arr[i]);

    } while (j > i);

    swap(arr[p], arr[j]);
    return j;
}

void Quick_Sort(int *arr, int startIndex, int endIndex) {

    if (startIndex < endIndex) {

        int j = pertition(arr, startIndex, endIndex);
        Quick_Sort(arr, startIndex, j);
        Quick_Sort(arr, j+1, endIndex);
    }
}

// Merger Sort

void merge(int *arr, int low, int mid, int high) {

    int *secondary = new int[high + 1];

    int i = low, j = mid + 1, k = low;
    
    while (i <= mid && j <= high) {

        if (arr[i] < arr [j])
            secondary[k++] = arr[i++];
        else 
            secondary[k++] = arr[j++];
    }

    for (; i <= mid; i++)
        secondary[k++] = arr[i];
    
    for (; j <= high; j++)
        secondary[k++] = arr[j];

    for (int i = low; i < high + 1; i++)
        arr[i] = secondary[i];
}

void rec_Merge_Sort(int *arr, int low, int high) {

    if (low < high) {

        int mid =(low+high) / 2;

        rec_Merge_Sort(arr, low, mid);
        rec_Merge_Sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void it_Merge_Sort(int *arr, int n) {

    int p = 2;

    for (; p < n; p *= 2) {

        for (int i = 0; i + p - 1 < n; i += p) {

            int l = i;
            int h = i + p - 1;
            int m = (l+h) / 2;
            merge(arr, l, m, h);
        }
    }
    if (p / 2 < n)
        merge(arr, 0, p/2-1,n-1);
}

// Count Sort

void Count_Sort(int *arr, int n) {

    int max = findMax(arr, n);

    int* count = new int[max+1];

    initZero(count, max+1);

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int i = 0, j = 0;

    while (i <= max) {

        if (count[i] == 0)
            i++;
        
        else {
            arr[j++] = i;
            count[i]--;
        }
    }
}

// Bin Sort

void Bin_Sort(int *arr, int n) {

    int max = findMax(arr, n);

    Node** bins = new Node*[max+1];

    initNull(bins, max+1);

    for (int i = 0; i < n; i++)
        insertNode(bins, arr[i], arr[i]);

    int i = 0, j = 0;

    while (i <= max) {

        if (!bins[i])
            i++;
        
        else
            arr[j++] = deleteNode(bins, i);
    }

    delete[] bins;
}

// Radix Sort

int countDigit(int n) {
    
    int count = 0;

    while (n > 0) {
        
        n /= 10;
        count++;
    }
    return count;
}

void Radix_Sort(int* arr, int n) {

    int max = findMax(arr, n);
    int nPass = countDigit(max);

    Node** bins = new Node*[10];

    initNull(bins, 10);

    for (int pass = 0; pass < nPass; pass++) {

        for (int i = 0; i < n; i++) {

            int t = (arr[i] / ((int) pow(10,pass))) % 10;
            insertNode(bins, t, arr[i]);
        }

        int i = 0, j = 0;

        while (i < 10) {

            if (!bins[i])
                i++;

            else
                arr[j++] = deleteNode(bins, i);
        }
        initNull(bins, 10);
    }
    delete[] bins;
}

// Shell Sort

void Shell_Sort(int* arr, int n) {

    int gap = n/2;

    while (gap > 0) {

        for (int i = 0; i < n-gap; i++) {

            int j = i + gap;

            while (j - gap >= 0 && arr[j] < arr[j-gap])
                swap(arr[j], arr[j-gap]);
        }
        gap /= 2;
    }
}

int main() {

    int a1[6] = {6,2,7,1,9,4};
    int a2[5] = {20,45,50,72,89};
    int a3[8] = {95,87,72,66,59,48,26,11};

    // int m1[12] = {10,20,30,40,5,15,25,35,45,50,55,60};

    // int qs_a1[7] = {6,2,7,1,9,4, INT32_MAX};
    // int qs_a2[6] = {20,45,50,72,89, INT32_MAX};
    // int qs_a3[9] = {95,87,72,66,59,48,26,11, INT32_MAX};

    // Bubble_Sort(a1,6);
    // Bubble_Sort(a2,5);
    // Bubble_Sort(a3,8);

    // Insertion_Sort(a1,6);
    // Insertion_Sort(a2,5);
    // Insertion_Sort(a3,8);

    // Selection_Sort(a1,6);
    // Selection_Sort(a2,5);
    // Selection_Sort(a3,8);

    // Quick_Sort(a1,0,6);
    // Quick_Sort(a2,0,5);
    // Quick_Sort(a3,0,8);

    // rec_Merge_Sort(a1,0,5);
    // rec_Merge_Sort(a2,0,4);
    // rec_Merge_Sort(a3,0,7);

    // it_Merge_Sort(a1,6);
    // it_Merge_Sort(a2,5);
    // it_Merge_Sort(a3,8);

    // Count_Sort(a1,6);
    // Count_Sort(a2,5);
    // Count_Sort(a3,8);

    // Bin_Sort(a1,6);
    // Bin_Sort(a2,5);
    // Bin_Sort(a3,8);

    // Radix_Sort(a1,6);
    // Radix_Sort(a2,5);
    // Radix_Sort(a3,8);

    Shell_Sort(a1,6);
    Shell_Sort(a2,5);
    Shell_Sort(a3,8);

    displayArray(a1, 6);
    displayArray(a2, 5);
    displayArray(a3, 8);

    // merge(m1,0,3,11);
    
    // displayArray(m1, 12);

    return 0;
}