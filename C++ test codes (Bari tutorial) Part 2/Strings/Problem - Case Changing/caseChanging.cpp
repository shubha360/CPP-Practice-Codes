#include<iostream>
#include<string>

using namespace std;

int main() {

    string inputStr = "Coding is good practice";

    cout << "Enter you anything want : ";
    getline(cin, inputStr);

    string :: iterator it;

    for (it = inputStr.begin(); it != inputStr.end(); it++) {

        if (*it >= 97 && *it <= 122) {
            *it -= 32;
        } else {
            *it +=0;
        }
    }

    // for (int i = 0; i < inputStr.length(); i++) {

    //     if (inputStr[i] >= 97 && inputStr[i] <= 122) {
    //         inputStr[i] -= 32;
    //     } else {
    //         inputStr[i] +=0;
    //     }
    // }

    cout << inputStr;

    return 0;
}