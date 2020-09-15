#include<iostream>

using namespace std;

class Static {

    public:
    static int count;

    Static() {
        count++;
    }

    static int getCount() {

        return count;
    }
};

int Static :: count = 0;

int main() {

    cout << Static :: getCount() << endl;
    cout << Static :: count << endl;

    Static st1;
    cout << st1.getCount() << endl;

    Static st2;
    cout << st2.getCount() << endl;

    st1.count = 200;
    cout << st2.count << endl;

    return 0;
}