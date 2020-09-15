#include<iostream>

using namespace std ;

int main() {

    int number, reversed = 0;

    cout<<"Enter a number : ";
    cin>>number;

    while(number != 0) {

        int digit = number % 10;

        number /= 10;

        reversed = reversed * 10 + digit;
    }

    while (reversed != 0)
    {
        int digit = reversed % 10;

        switch (digit) {

            case 1 : cout<<"One ";
            break;

            case 2 : cout<<"Two ";
            break;

            case 3 : cout<<"Three ";
            break;

            case 4 : cout<<"Four ";
            break;

            case 5 : cout<<"Five ";
            break;

            case 6 : cout<<"Six ";
            break;

            case 7 : cout<<"Seven ";
            break;

            case 8 : cout<<"Eight ";
            break;

            case 9 : cout<<"Nine ";
            break;
        }
        reversed /= 10;
    }
    return 0;
}