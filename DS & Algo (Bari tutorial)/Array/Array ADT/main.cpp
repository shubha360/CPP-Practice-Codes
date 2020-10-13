#include<iostream>
#include "Array.cpp"

using namespace std;

int main() {

    Array<int> array1(10);
    array1.add(4);
    array1.add(1);
    array1.add(9);
    array1.add(3);
    array1.display();

    Array<int> array2(10);
    array2.add(4);
    array2.add(5);
    array2.add(2);
    array2.add(7);
    array2.display();

    array1.sort();
    array2.sort();

    auto array3 = array1.merge(array2);
    array3.display();

    return 0;
}