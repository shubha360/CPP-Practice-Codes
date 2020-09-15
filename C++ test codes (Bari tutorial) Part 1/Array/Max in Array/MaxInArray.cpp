#include<iostream>

using namespace std;

int main() {
    int array[] = {74,585,22,3,54,13,74,2,353,656,52};

    int max = 0;

    for(int x : array) {

        if (x > max)
        {
            max = x;
        }
    }

    cout << "The maximum number is " << max;

    return 0;
}