#include<iostream>
#include "D:\Shubha\Test Codes\DS & Algo\Stack\Implementation using Linked List\Stack_LinkedList.cpp"

using namespace std;

bool isBalanced(string str) {

    Stack st;

    for (char c : str) {

        if (c == '(')
            st.push(1);
        else if (c == ')') {
         
            if (st.isEmpty())
                return 0;

            st.pop();
        }
    }
    return st.isEmpty() ? 1 : 0;
}

int main() {

    string str = "a+b - (a-b)";

    isBalanced(str) == 1 ? cout << "Equation is balanced." << endl : cout << "Equation is not balanced." << endl;

    return 0;
}