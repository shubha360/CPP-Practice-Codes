#include<iostream>

int main() {

    int smallRoomNumber = 0, largeRoomNumber = 0;
    const int smallRoomCost = 25;
    const int largeRoomCost = 35;
    const float taxRate = 0.06f;

    float total = 0, tax = 0;

    std::cout << "Hello, Welcome to Frank's Carpet Cleaning Service!" << std::endl;
    std::cout << std::endl;

    std::cout << "How many small rooms?" << std::endl;
    std::cin >> smallRoomNumber;
    std::cout << "How many large rooms?" << std::endl;
    std::cin >> largeRoomNumber;
    std::cout << std::endl;

    total = (smallRoomNumber * smallRoomCost) + (largeRoomNumber * largeRoomCost);
    tax = total * taxRate;

    std::cout << "Estimate for carpet cleaning service : " << std::endl;
    std::cout << "Number of small room(s) : " << smallRoomNumber << std::endl;
    std::cout << "Number of large room(s) : " << largeRoomNumber << std::endl;
    std::cout << "Price per small room : $" << smallRoomCost << std::endl;
    std::cout << "Price per large room : $" << largeRoomCost << std::endl;
    std::cout << "Cost : $" << total << std::endl;
    std::cout << "Tax : $" << tax << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Total estimate : " <<  total + tax << std::endl;
    std::cout << "This estimate is valid for 30 days." << std::endl;

    return 0;
}