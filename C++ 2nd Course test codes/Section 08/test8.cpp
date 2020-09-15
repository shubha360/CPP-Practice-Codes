#include<iostream>

int main() {

    const int thousandValue = 1000;
    const int fiveHundredValue = 500;
    const int twoHundredValue = 200;
    const int oneHundredValue = 100;
    const int fiftyValue = 50;
    const int twentyValue = 20;
    const int tenValue = 10;
    const int fiveValue = 5;
    const int twoValue = 2;
    const int oneValue = 1;

    int userInput;

    std::cout << "Enter amount to be changed : ";
    std::cin >> userInput;

    int balance, thousand, fiveHundred, twoHundred, oneHundred, fifty, twenty, ten, five, two, one;

    balance = thousand = fiveHundred = twoHundred = oneHundred = fifty = twenty = ten = five = two = one = 0;

    thousand = userInput / thousandValue;
    balance = userInput % thousand;

    fiveHundred = balance / fiveHundredValue;
    balance %= fiveHundredValue;

    twoHundred = balance / twoHundredValue;
    balance %= twoHundredValue;
    
    oneHundred = balance / oneHundredValue;
    balance %= oneHundredValue;

    fifty = balance / fiftyValue;
    balance %= fiftyValue;

    twenty = balance / twentyValue;
    balance %= twentyValue;

    ten = balance / tenValue;
    balance %= tenValue;

    five = balance / fiveValue;
    balance %= fiveValue;

    two = balance / twoValue;
    balance %= twoValue;

    one = balance;

    std::cout << "Thousand : " << thousand << std::endl;
    std::cout << "Five Hundred : " << fiveHundred << std::endl;
    std::cout << "Two Hundred : " << twoHundred << std::endl;
    std::cout << "One Hundred : " << oneHundred << std::endl;
    std::cout << "Fifty : " << fifty << std::endl;
    std::cout << "Twenty : " << twenty << std::endl;
    std::cout << "Ten : " << ten << std::endl;
    std::cout << "Five : " << five << std::endl;
    std::cout << "Two : " << two << std::endl;
    std::cout << "One : " << one << std::endl;

    return 0;
}