
// For +,-,*,/ only

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

int evaluatePostfix(string postfix) {

    stack<int> st;

    int res,x,y;

    auto it = postfix.begin();

    while (it != postfix.end()) {

        if (isOperand(*it)) {
        
            st.push(*it - '0');
            it++;
        }
        
        else {

            x = st.top();
            st.pop();
            y = st.top();
            st.pop();

            switch (*it) {

                case '+' :
                    res = y + x;
                    st.push(res);
                    it++;
                    break;
                
                case '-' :
                    res = y - x;
                    st.push(res);
                    it++;
                    break;
                
                case '*' :
                    res = y * x;
                    st.push(res);
                    it++;
                    break;

                case '/' :
                    res = y / x;
                    st.push(res);
                    it++;
                    break;
            }
        }
    }
    return st.top();
}

int main() {

    string infix = "9+9+9/3-2*5+2";

    string postfix = convert(infix);

    cout << postfix << endl;

    int res = evaluatePostfix(postfix);

    cout << res << endl;

    return 0;
}