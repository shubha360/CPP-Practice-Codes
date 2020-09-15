#include<iostream>

class Base {

    public:

    void fun1();
    void fun2();
};

class Derived : public Base {

    public:

    void fun3();
    void fun4();
};

int main() {

    Base *p;
    p = new Base();

    p -> fun2();

    return 0;
}