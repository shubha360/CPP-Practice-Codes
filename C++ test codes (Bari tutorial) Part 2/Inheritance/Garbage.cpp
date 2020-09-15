#include<iostream>

using namespace std;

class Base {

    public:

    int x;

    void show() {

        cout << x << endl;
    }
};

class Derrived : public Base {

    public:

    int y;

    void display() {

        cout << x << " " << y;
    }
};

int main() {

    Base b;
    b.x = 100;
    b.show();

    Derrived d;
    d.x = 150;
    d.y = 200;
    d.show();
    d.display();

    return 0;
}