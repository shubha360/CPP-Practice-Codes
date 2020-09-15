#include<iostream>

using namespace std;

int main() {

    int basicSalary;
    double allowance, deduction, netSalary;

    cout<<"Basic salary : ";
    cin>>basicSalary;

    cout<<"Percentage of Allowance : ";
    cin>>allowance;

    cout<<"Percentage of Deduction : ";
    cin>>deduction;

    netSalary = basicSalary + basicSalary * (allowance/100) - basicSalary * (deduction/100);

    cout<<"\nNet salary is : "<<netSalary;

    return 0;
}