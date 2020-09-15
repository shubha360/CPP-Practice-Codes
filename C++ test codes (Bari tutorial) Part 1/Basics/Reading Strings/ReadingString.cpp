#include<iostream>

using namespace std;

int main() {

    string firstName;

    cout<<"May I know your first name? ";

    getline(cin, firstName); // cin>>"..." doesn't read multiple words. Using getline() is better practice. It reads input untill the enter button is pressed.

    cout<<"Welcome "<<firstName<<"!";

    return 0;
}