
// only supports +,-,*,/

#include<iostream>
#include<stack>

using namespace std;

bool isOperand(char c) {

    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 0;
    return 1;
}

int precedence(char c) {

    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

string convert (string infix) {

    stack<char> st;

    string postfix;

    auto it = infix.begin();

    while (it != infix.end()) {

        if (isOperand(*it))
            postfix.push_back(*it++);
        
        else {
            
            if (st.empty() || precedence(*it) > precedence(st.top()))
                st.push(*it++);
            
            else {
                
                postfix.push_back(st.top());
                st.pop();
            }
        }
    }

    while (!st.empty()) {
        
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}

int main() {

    string infix = "a+b*c/d+e-f";

    string postfix = convert(infix);

    cout << postfix << endl;

    return 0;
}