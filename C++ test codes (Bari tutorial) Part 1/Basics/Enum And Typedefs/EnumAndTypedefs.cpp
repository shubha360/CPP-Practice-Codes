#include<iostream>

using namespace std;

enum menu {chicken = 3, beef = 9, mutton, fish = 500, vegiterian};

typedef int rollNo;

int main() {

    menu f = fish, b = beef;

    rollNo r1 = 10, r2, r3 = 500, r100;

    cout<<"This is enum : "<<b<<endl;

    cout<<"This is typedef : "<<r3<<endl;

    return 0;
}