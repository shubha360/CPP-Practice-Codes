#include<iostream>

using namespace std;

int main() {

    char c;
    int i;
    float f;
    double d;
    short s;
    long l;
    long int li;
    long double ld;
    bool b;

    cout<<"Size of char data type is: "<<sizeof(c)<<" byte(s)\n";
    cout<<"Range of char data type is: "<<CHAR_MIN<<" to "<<CHAR_MAX<<endl;
    cout<<"\n";

    cout<<"Size of int data type is: "<<sizeof(i)<<" byte(s)\n";
    cout<<"Range of int data type is: "<<INT_MIN<<" to "<<INT_MAX<<endl;
    cout<<"\n";

    cout<<"Size of float data type is: "<<sizeof(f)<<" byte(s)\n";

    cout<<"Size of double data type is: "<<sizeof(d)<<" byte(s)\n";

    cout<<"Size of short data type is: "<<sizeof(s)<<" byte(s)\n";

    cout<<"Size of long data type is: "<<sizeof(l)<<" byte(s)\n";

    cout<<"Size of long int data type is: "<<sizeof(li)<<" byte(s)\n";

    cout<<"Size of long double data type is: "<<sizeof(ld)<<" byte(s)\n";

    cout<<"Size of bool data type is: "<<sizeof(b)<<" byte(s)\n";

    return 0;
}