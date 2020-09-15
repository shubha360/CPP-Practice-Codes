#include<iostream>

using namespace std;

class Shape {

    public:

    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Rectangle : public Shape {

    private:

    int length;
    int breadth;

    public:

    Rectangle(int length, int breadth) {

        this -> length = length;
        this -> breadth = breadth;
    }

    float area() {

        return length * breadth;
    }

    float perimeter() {
        
        return 2 * (length + breadth);
    }
};

class Circle : public Shape {

    private:

    int radius;

    public:

    Circle(int radius) {

        this -> radius = radius;
    }

    float area() {

        return 3.1415 * (radius * radius);
    }

    float perimeter() {

        return 2 * 3.1415 * radius;
    }
};

int main() {

    Shape *ptr = new Rectangle(10, 20);
    cout << "Area of Rectangle : " << ptr -> area() << endl;
    cout << "Perimeter of Rectangle : " << ptr -> perimeter() << endl;

    cout << endl;

    ptr = new Circle(10);
    cout << "Area of Circle : " << ptr -> area() << endl;
    cout << "Perimeter of Circle : " << ptr -> perimeter() << endl;

    return 0;
}