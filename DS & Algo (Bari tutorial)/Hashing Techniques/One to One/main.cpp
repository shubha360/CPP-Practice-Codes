#include<iostream>
#include<vector>

using namespace std;

int findMax(vector<int> vec) {

    int max = vec[0];

    for (int &i : vec) {

        if (i > max)
            max = i;
    }
    return max;
}

bool hash_search(vector<int> vec, int key) {

    int max = findMax(vec);
    
    cout << max << endl;

    if (key > max || key < 0)
        return 0;

    vector<int> hashTable(max+1,0);

    for (int i : vec)
        hashTable[i]++;

    if (hashTable[key] > 0)
        return 1;

    return 0;
}

void initZero(vector<int> &vec) {

    for (int &i : vec)
        i = 0;
}

void initVec(vector<int> &vec, int *arr, int n) {

    for (int i = 0; i < n; i++)
        vec.push_back(arr[i]);
}

int main() {

    int arr[7] = {3,14,2,8,11,17,5};

    vector<int> vec;

    initVec(vec, arr, 7);

    hash_search(vec, 8) == 1 ? cout << "Element is found." << endl : cout << "Element is not found." << endl;

    return 0;
}