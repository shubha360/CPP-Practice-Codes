#include<iostream>

using namespace std;

int main() {

    int billAmount;
    int discountPercentage;
    double discountAmount;
    double subTotal;

    cout<<"Enter bill amount: ";
    cin>>billAmount;

    if(billAmount >= 500) {

        discountPercentage = 20;
        discountAmount = billAmount * (discountPercentage/100.00);
        subTotal = billAmount - discountAmount;
    }
    else if(billAmount >= 100 && billAmount < 500) {

        discountPercentage = 10;
        discountAmount = billAmount * (discountPercentage/100.00);
        subTotal = billAmount - discountAmount;
    }
    else {

        cout<<"Sorry you didn't get any discount. Total amount to be paid is "<<billAmount;
        return 0;
    }

    cout<<"You got "<<discountPercentage<<"% discount!"<<endl;
    cout<<"Total discount amount is "<<discountAmount<<endl;
    cout<<"Total amount to be paid is "<<subTotal<<endl;
    
    return 0;
}