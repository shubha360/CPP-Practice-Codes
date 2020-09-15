#include<iostream>
#include<cstring>

int main() {

    char fullName[50] {};

    std :: cout << "Enter your fullname : ";
    std :: cin.getline(fullName, 50);

    std :: cout << "Your name has " << std :: strlen(fullName) << " characters.";

    return 0;
}