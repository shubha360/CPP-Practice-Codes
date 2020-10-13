#include<iostream>

using namespace std;

// Displaying string
void print(const char * str) {
    for (int i = 0; str[i] != '\0'; i++)
        cout << str[i];
    cout << endl;
}

// Finding length of string
int lengthOfString(const char * str) {

    int i = 0;
    for (; str[i] != '\0'; i++) {}
    return i;
}

// Convering string to uppercase
void toUpperCase(char * str) {

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

// Convering string to lowercase
void toLowerCase(char * str) {

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

// Toggling cases
void toggleCase(char * str) {

    for (int i = 0; str[i] != '\0'; i++) {
        
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;

        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

// Counting words
int wordCount(char * str) {

    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            count++;   
    }
    return count;
}

// Reversing string
void reverse(char * str) {

    int length = 0;
    for (; str[length] != '\0'; length++) {}

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Palindrome
bool isPalindrome(char * str) {

    int length = 0;
    for (; str[length] != '\0'; length++) {}

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        
        if (str[i] != str[j])
            return 0;
    }
    return 1;
}

// Anagram
bool isAnagram(char * a, char * b) {

    int x, y;
    for (x = 0; a[x] != '\0'; x++) {}
    for (y = 0; b[y] != '\0'; y++) {}

    if (x != y) {
        
        cout << "Length doesn't match." << endl;
        return 0;
    }

    int i, H[26] {0};

    for (i = 0; a[i] != '\0'; i++)
        H[a[i] - 97]++;

    for (i = 0; b[i] != '\0'; i++) {

        H[b[i] - 97]--;
        if (H[b[i] - 97] < 0)
            return 0;
    }
    
    return 1;
}

// Function for display a char array
void display(char * str) {

    for (int i = 0; str[i] != '\0'; i++)
        cout << str[i] << " ";
    cout << endl;
}

// Function for swapping data of two variables
void swap(char & a, char & b) {

    char temp = a;
    a = b;
    b = temp;
}

// Permutaion of string using extra array
void permutations1(char * str, int k) {

    int arr[10] {0};
    char res[10];
    int i;

    if (str[k] == '\0') {
        
        res[k] = '\0';
        display(str);
    }
    else {

        for (i = 0; str[i] != '\0'; i++) {
            if (arr[i] == 0) {
                res[k] = str[i];
                arr[i] = 1;
                permutations1(str, k+1);
                arr[i] = 0;
            }
        }
    }
}

// Permutation of string using swap
void permutations2(char * str, int low, int high) {

    if (low == high)
        display(str);

    else {

        for (int i = low; i <= high; i++) {
            swap(str[low], str[i]);
            permutations2(str,low+1,high);
            swap(str[low], str[i]);
        }
    }
}

// Skipped :
// Counting verbs and consonants
// Validating string
// Finding duplicates in a string using linear search
// Finding duplicates in a string using hashing
// Finding duplicates in a string using bits
// String anagram using linear search

int main() {

    char a[] = "ABC";

    permutations1(a, 0);
    return 0;
}