#include<iostream>
#include<math.h>

using namespace std;

int main() {

    float a, b, c, rt1, rt2;

    cout<<"Enter the coefficients (a,b,c) : ";
    cin>>a>>b>>c;

    if((b*b - 4*a*c) == 0) {
        
        rt1 = (-b)/(2*a);
        rt2 = (-b)/(2*a);
        cout<<"The roots are real and equal.";
    }
    if((b*b - 4*a*c) < 0) {
        rt1 = (-b)/(2*a);
        rt2 = (-b)/(2*a);

        cout<<"The roots are imaginary.";
    }
    if((b*b - 4*a*c) > 0) {
        rt1 = (-b + sqrt( b*b - 4*a*c))/(2*a);
        rt2 = (-b - sqrt( b*b - 4*a*c))/(2*a);

        cout<<"The roots are "<<rt1<<" "<<rt2;
    }

    return 0;
}