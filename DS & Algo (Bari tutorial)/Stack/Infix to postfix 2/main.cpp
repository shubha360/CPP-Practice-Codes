
// For +,-,*,/,^,()

#include<iostream>
#include<stack>

using namespace std;

bool isOperand(char c) {

    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
        return 0;
    return 1;
}

int outPrecedence(char c) {

    if (c == '+' || c == '-')
        return 1;
    
    else if (c == '*' || c == '/')
        return 3;

    else if (c == '^')
        return 6;
    
    else if (c == '(')
        return 7;

    else if (c == ')')
        return 0;
    
    return -1;
}

int inPrecedence(char c) {

    if (c == '+' || c == '-')
        return 2;
    
    else if (c == '*' || c == '/')
        return 4;

    else if (c == '^')
        return 5;
    
    else if (c == '(')
        return 0;
    
    return -1;
}

string convert(string infix) {

    stack<char> st;

    string postfix;

    auto it = infix.begin();

    while (it != infix.end()) {

        if (isOperand(*it))
            postfix.push_back(*it++);
        
        else {

            if (st.empty() || outPrecedence(*it) > inPrecedence(st.top()))
                st.push(*it++);
            
            else if (outPrecedence(*it) == inPrecedence(st.top())) {
                
                st.pop();
                it++;
            }
            else {
                postfix.push_back(st.top());
                st.pop();
            }
        }
    }

    while (!st.empty()) {

        if (st.top() == '(' || st.top() == ')')
            st.pop();
        
        else {
            
            postfix.push_back(st.top());
            st.pop();
        }
    }
    return postfix;
}

int main() {

    string infix = "((a+b)*(c-d)/x-z)";

    string postfix = convert(infix);

    cout << postfix << endl;

    return 0;
}