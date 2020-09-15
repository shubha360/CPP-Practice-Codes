#include<iostream>

using namespace std;

class Complex {

    int real;
    int imaginary;

    public :

    Complex(int real = 0, int imaginary = 0) {

        this -> real = real;
        this -> imaginary = imaginary;
    }

    int getReal() {
        return real;
    }
    
    int getImaginary() {
        return imaginary;
    }

    friend Complex operator+(Complex x, Complex y);
};

Complex operator+(Complex x, Complex y) {

    Complex temp;

    temp.real = x.real + y.real;
    temp.imaginary = x.imaginary + y.imaginary;

    return temp;
}

int main() {

    Complex c1(10, 20);
    Complex c2(100, 200);
    Complex c3;

    c3 = c1 + c2;

    cout << "Real number is " << c3.getReal() << endl;
    cout << "Imaginary number is " << c3.getImaginary() << endl;

    return 0;
}