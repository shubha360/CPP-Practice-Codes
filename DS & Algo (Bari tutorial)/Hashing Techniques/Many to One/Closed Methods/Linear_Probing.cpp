#include<iostream>
#include<vector>

using namespace std;

vector<int> initVec(int *arr, int n) {

    vector<int> vec;

    for (int i = 0; i < n; i++)
        vec.push_back(arr[i]);

    return vec;
}

void insertHash(vector<int> &hashTable, vector<int> vec) {

    for (int temp : vec) {

        if (hashTable[temp%10] == INT32_MIN)
            hashTable[temp%10] = temp;
        
        else {
            
            int i = 1;
            
            while (hashTable[((temp%10) + i) % 10] != INT32_MIN)
                i++;
            
            hashTable[((temp%10) + i) % 10] = temp;
        }
    }
}

bool hash_search(vector<int> vec, int key) {

    vector<int> hashTable(10, INT32_MIN);

    insertHash(hashTable, vec);

    int i = 0;

    while (hashTable[((key%10) + i) % 10] != INT32_MIN) {

        if (hashTable[((key%10) + i) % 10] == key)
            return 1;
        
        i++;
    }
    return 0;
}

int main() {

    int arr[5] = {76,57,6,18,127};

    vector<int> vec = initVec(arr,5);

    hash_search(vec,6) == 1 ? cout << "Element is found." << endl : cout << "Element is not found." << endl;

    return 0;
}