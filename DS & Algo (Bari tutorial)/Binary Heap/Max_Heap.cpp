#include<iostream>
#include<vector>

using namespace std;

class Max_Heap {

    private:

    vector<int> heap;

    // Heapify
    vector<int> heapify(int *keyArr, int size);
    vector<int> heapify(vector<int> &keyVec);

    // Delete
    int deleteRoot();

    public:

    // Constructors
    Max_Heap(int key);
    Max_Heap(int *keyArr, int size);
    Max_Heap(vector<int> &keyVec);

    // Insert
    void insert(int key);
    
    // HeapSort
    vector<int> heapSort();

    // Other function
    void swap(int &a, int &b) {

        int temp = a;
        a = b;
        b = temp;
    }

    void display();
};

// Constructor - takes a single integer
Max_Heap :: Max_Heap(int key) {

    this -> heap.push_back(key);
}

// Constructor - takes an array and its size
Max_Heap :: Max_Heap(int *keyArr, int size) {

    this -> heap = this -> heapify(keyArr, size);
}

// Constructor - takes a vector
Max_Heap :: Max_Heap(vector<int> &keyVec) {

    this -> heap = this -> heapify(keyVec);
}

// Insertion function
void Max_Heap :: insert(int key) {

    heap.push_back(key);

    if (heap.size() == 1)
        return;

    int i = heap.size() - 1;

    while (i > 0) {

        int temp = ((i%2) == 0) ? ((i/2) - 1) : (i/2);

        if (heap[i] > heap[temp])
            swap(heap[i], heap[temp]);

        i = temp;
    }
}

// HeapSort Function
vector<int> Max_Heap :: heapSort() {

    vector<int> sortedVec;

    int n = heap.size();

    for (int i = 0; i < n; i++) {
        
        int temp = this -> deleteRoot();
        sortedVec.push_back(temp);
    }

    return sortedVec;
}

// Heapify from array
vector<int> Max_Heap :: heapify(int *keyArr, int size) {

    vector<int> keyVec;

    for (int a = 0; a < size; a++)
        keyVec.push_back(keyArr[a]);

    int n = (keyVec.size() - 1 % 2) == 0 ? ((keyVec.size() - 1) / 2) - 1 : (keyVec.size() - 1) / 2;
    int i = n;

    while (i >= 0) {

        int j = (i + 1) * 2;
        int k = j - 1;

        if (keyVec[j] < keyVec[k])
            j = k;
        
        if (keyVec[i] < keyVec[j]) {

            swap(keyVec[i], keyVec[j]);

            (j <= n) ? i = j : i--;
        }
        else
            i--;
    }
    return keyVec;
    
}

// Heapify from vector
vector<int> Max_Heap :: heapify(vector<int> &keyVec) {

    int n = (keyVec.size() - 1 % 2) == 0 ? ((keyVec.size() - 1) / 2) - 1 : (keyVec.size() - 1) / 2;
    int i = n;

    while (i >= 0) {

        int j = (i + 1) * 2;
        int k = j - 1;

        if (keyVec[j] < keyVec[k])
            j = k;
        
        if (keyVec[i] < keyVec[j]) {

            swap(keyVec[i], keyVec[j]);

            (j <= n) ? i = j : i--;
        }
        else
            i--;
    }
    return keyVec;
}

// Deleting function
int Max_Heap :: deleteRoot() {

    if (heap.empty()) {
     
        cout << "Max_Heap is empty ";
        return -1;
    }

    int res = heap[0];

    swap(heap[0], heap[heap.size() - 1]);

    heap.pop_back();

    int i, j, k;

    i = j = k = 0;

    while(j < heap.size() || k < heap.size()) {

        j = (i+1) * 2;
        k = j-1;

        if (k < heap.size() && j < heap.size()) {

            if (heap[k] > heap[j]) {

                if (heap[k] > heap[i]) {
                    
                    swap(heap[k], heap[i]);
                    i = k;
                }
                else
                    break;
            }
            else {

                if (heap[j] > heap[i]) {

                    swap(heap[j], heap[i]);
                    i = j;
                }    
                else 
                    break;
            }
        }

        else if (k < heap.size() && j >= heap.size()) {

            if (heap[k] > heap[i]) {
                    
                    swap(heap[k], heap[i]);
                    i = k;
                }
                else
                    break;
        }

        else if (k >= heap.size() && j < heap.size()) {

            if (heap[j] > heap[i]) {
                    
                    swap(heap[j], heap[i]);
                    i = k;
                }
                else
                    break;
        }
    }
    return res;
}

// Display function
void Max_Heap :: display() {

    if (heap.size() == 0)
        cout << "Max_Heap is empty." << endl;

    else {

        cout << "[";
        
        for (int t : heap)
            cout << " " << t << " ";
        
        cout << "]";
    }
    cout << endl;
}

// Displaying a vector
void displayVec(vector<int> vec) {

    for (int i : vec)
        cout << i << " ";

    cout << endl;
}

int main() {

    int arr[9] = {40,60,70,10,25,45,65,5,30};

    Max_Heap h1(arr, 9);

    vector<int> vec, vec2;

    for (int i = 0; i < 9; i++)
        vec.push_back(arr[i]);

    Max_Heap h2(vec);

    h1.display();
    h2.display();

    return 0;
}