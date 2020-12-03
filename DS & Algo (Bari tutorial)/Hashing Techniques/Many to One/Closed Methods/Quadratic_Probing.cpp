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

void insertHash(vector<int> &hashTable, vector<int> vec) {

    for (int temp : vec) {

        if (hashTable[temp%10] == INT32_MIN)
            hashTable[temp%10] = temp;
        
        else {
            
            int i = 1, j = 1;
            
            while (hashTable[((temp%10) + j) % 10] != INT32_MIN) {
                
                i++;
                j = (int) pow(i,i);
            }
            
            hashTable[((temp%10) + j) % 10] = temp;
        }
    }
}

bool hash_search(vector<int> vec, int key) {

    vector<int> hashTable(10, INT32_MIN);

    insertHash(hashTable, vec);

    int i = 0, j = 0;

    while (hashTable[((key%10) + j) % 10] != INT32_MIN && i < 20) {

        if (hashTable[((key%10) + j) % 10] == key)
            return 1;
        
        i++;
        j = (int) pow(i,i);
    }
    return 0;
}

int main() {

    int arr[4] = {23,43,13,27};

    vector<int> vec = initVec(arr,4);

    hash_search(vec,47) == 1 ? cout << "Element is found." << endl : cout << "Element is not found." << endl;

    return 0;
}