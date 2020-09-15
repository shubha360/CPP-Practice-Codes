#include<iostream>

using namespace std;

int main() {

    int x = 12, y = 7, andZ, orZ, xorZ, notX, leftX, rightX;

    // And

    andZ = x & y;
    cout<<"X and Y is : "<<andZ<<"\n";

    // Or

    orZ = x | y;
    cout<<"X or Y is : "<<orZ<<"\n";


    // Xor

    xorZ = x ^ y;
    cout<<"X xor Y is : "<<xorZ<<"\n";

    // Not

    notX = ~x;
    cout<<"X not is : "<<notX<<"\n";

    // Left Shift

    leftX = x<<1;
    cout<<"X left shifted by 1 is : "<<leftX<<"\n";

    // Right Shift

    rightX = x>>1;
    cout<<"X right shifted by 1 is : "<<rightX<<"\n";

    return 0;
}