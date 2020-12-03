#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> initVec(int *arr, int n) {

    vector<int> vec;

    for (int i = 0; i < n; i++)
        vec.push_back(arr[i]);

    return vec;
}

int doubleHash(int n, int i) {
    return ((n%10) + i * (7 - (n%7))) % 10;
}

void insertHash(vector<int> &hashTable, vector<int> vec) {

    for (int temp : vec) {

        if (hashTable[temp%10] == INT32_MIN)
            hashTable[temp%10] = temp;
        
        else {
            
            int i = 1;
            
            while (hashTable[doubleHash(temp, i)] != INT32_MIN) {
                
                i++;
            }
            
            hashTable[doubleHash(temp, i)] = temp;
        }
    }

    for (int a : hashTable)
        cout << a << " ";
    
    cout << endl;
}

bool hash_search(vector<int> vec, int key) {

    vector<int> hashTable(10, INT32_MIN);

    insertHash(hashTable, vec);

    int i = 0;

    while (hashTable[doubleHash(key, i)] != INT32_MIN) {

        if (hashTable[doubleHash(key, i)] == key)
            return 1;
        
        i++;
    }
    return 0;
}

int main() {

    int arr[5] = {5,25,15,35,95};

    vector<int> vec = initVec(arr,5);

    hash_search(vec,95) == 1 ? cout << "Element is found." << endl : cout << "Element is not found." << endl;

    return 0;
}