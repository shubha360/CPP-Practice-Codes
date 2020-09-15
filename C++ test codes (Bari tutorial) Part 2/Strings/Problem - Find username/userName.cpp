#include<iostream>

using namespace std;

int main() {

    string email = "shubha360@outlook.com";

    int atIndex = email.find('@');

    int dotIndex = email.rfind(".");

    string username = email.substr(0,atIndex);

    string domain = email.substr((atIndex + 1), (dotIndex - (atIndex + 1)));

    cout << "Username : " << username << endl;

    cout << "Domain : " << domain;

    return 0;
}