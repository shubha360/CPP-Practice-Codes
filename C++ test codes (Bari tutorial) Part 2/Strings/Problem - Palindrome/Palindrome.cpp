#include<iostream>

using namespace std;

int main() {

    string inputStr = "Malayalam";
    string revStr = "";

    int length = (int) inputStr.length();

    revStr.resize(length);

    string :: iterator it;

    for (it = inputStr.begin(); it != inputStr.end(); it++) {

        if (*it >= 97 && *it <= 122) {
            
            *it -= 32;
        }
    }

    for (int i = 0, j = length - 1; i<length; i++, j--) {

        revStr[i] = inputStr[j];
    }

    revStr[length] = '\0';

    cout << revStr << endl;

    if(inputStr.compare(revStr) == 0) {
        cout << "This is a palindrome.";
    } else {
        cout << "This is not a palindrome.";
    }
    return 0;
}