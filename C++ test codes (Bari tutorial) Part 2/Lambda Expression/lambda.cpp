#include<iostream>

// template<typename T>

// void fun(T f) {

//         f();
//     }

int main() {

    []() {std :: cout << "Hello" << std :: endl;}();

    auto fun = []() {std :: cout << "Hello too" << std :: endl;};

    fun();

    [](int x, int y) {std :: cout << x+y << std :: endl;}(3,2);

    int multiply = [](int x, int y){return x*y;}(5,7);
    std :: cout << multiply << std :: endl;

    []() -> void {std :: cout << "This is void." << std :: endl;}();
    
    int sum = [](int x, int y) -> int {return x + y;}(90, 100);
    std :: cout << sum << std :: endl;

    int a = 40, b = 30;

    [a,b](){std :: cout << "Sum is " << a+b << std :: endl;}();

    [&a, &b]() {std :: cout << "a + 100 : " << a + 100 << std :: endl << "b + 100 : " << b + 100 << std :: endl;}();

    [&]() {std :: cout << "a * 10 : " << a * 10 << std :: endl << "b * 10 : " << b * 10 << std :: endl;}();

    // auto f = []() {std :: cout << "This is function" << std :: endl;};

    // fun(f);

    return 0;
}