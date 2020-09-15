#include<iostream>

using namespace std;

int main() {

    int A[2][3] = {{1,2,3},{4,5,6}};
    int B[2][3] = {{6,5,4},{3,2,1}};

    int addedC[2][3];
    int substractedC[2][3];
    int multipliedC[2][3];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {

            // addedC[i][j] = A[i][j] + B[i][j];
            // cout << addedC[i][j]<<endl;

            substractedC[i][j] = A[i][j] - B[i][j];
            cout << substractedC[i][j]<<" ";
            
            // multipliedC[i][j] = A[i][j] * B[i][j];
            // cout << multipliedC[i][j]<<endl;
        }
        cout << endl;
    }
    return 0;
}