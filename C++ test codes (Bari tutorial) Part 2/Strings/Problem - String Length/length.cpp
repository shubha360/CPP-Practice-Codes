#include<iostream>

using namespace std;

int main() {

    string inputStr = "poons";
    int charCount = 0;

    cout << "Enter anything you want : ";
    getline(cin, inputStr);


    string :: iterator it;

    for (it = inputStr.begin(); it != inputStr.end(); it++) {
        
        charCount ++;
    }

    cout << "Length is " << charCount;

    return 0;
}