#include<iostream>

using namespace std;

int main() {

    string inputStr = "How Many Words and elSe";
    
    int vowelCount = 0, consCount = 0, wordCount = 0, letterCount = 0; 
    string :: iterator it;

    for (it = inputStr.begin(); it != inputStr.end(); it++) {

        if (*it == 32) {
            wordCount++;
        }
        if ((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122)) {

            letterCount++;
            if ((*it == 65 || *it == 69 || *it == 73 || *it == 79 || *it == 85) || (*it == 97 || *it == 101 || *it == 105 || *it == 111 || *it == 117)) {
                vowelCount++;
            }
        }
    }

    cout << "Total letters " << letterCount << endl;
    cout << "Total vowels " << vowelCount << endl;
    cout << "Total consonants " << letterCount - vowelCount << endl;
    cout << "Total words " << wordCount + 1 << endl;

    return 0;
}