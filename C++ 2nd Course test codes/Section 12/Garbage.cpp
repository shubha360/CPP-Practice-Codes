#include<iostream>
#include<vector>

using namespace std;

int main() {

    // int a{700};

    // int *ptr = nullptr;

    // cout << ptr << endl;

    // ptr = &a;

    // cout << &a << endl;
    // cout << ptr << endl;
    // cout << a << endl;
    // cout << *ptr << endl;
    // cout << &ptr << endl;

    // int *int_ptr = nullptr;
    // double *double_ptr = nullptr;
    // char *char_ptr = nullptr;
    // string *string_ptr = nullptr;

    // cout << sizeof int_ptr << endl;
    // cout << sizeof double_ptr << endl;
    // cout << sizeof char_ptr << endl;
    // cout << sizeof string_ptr << endl;

    vector<int> list {58, 26, 15};

    for (auto &str : list)
        str = 10;

    for (size_t i = 0; i < list.size(); i++)
        cout << list.at(i) << endl;

    return 0;
}