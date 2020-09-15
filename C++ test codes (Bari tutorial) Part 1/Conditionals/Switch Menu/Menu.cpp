#include<iostream>

using namespace std;

int main() {

    int firstInput, secondInput, option;
    double result;

    cout<<"Enter two numbers (separated by a space) : ";
    cin>>firstInput>>secondInput;

    cout<<"Choose an option :\nAddition - 1 \nSubstraction - 2 \nMultiplication - 3 \nDivision - 4 \nYou choice : ";
    cin>>option;

    switch (option)
    {
    case 1 : result = (double) firstInput + secondInput;
        break;

    case 2 : result = (double) firstInput - secondInput;
        break;

    case 3 : result = (double) firstInput * secondInput;
        break;

    case 4 : result = (double) firstInput / secondInput;
        break;
    
    default: cout<<"Invalid option chosen.";
        return 0;
    }

    cout<<"Result is "<<result;

    return 0;
}