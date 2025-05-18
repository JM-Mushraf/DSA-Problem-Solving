#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char ch) {
    return isalnum(ch); // a-z, A-Z, 0-9
}

string prefix_to_postfix(string s) {
    stack<string> st;
    int n=s.size();
    // Step 1: Loop through each character in the postfix string
    for (int i = n-1; i >=0; i--) {
        char ch = s[i];

        // Step 2: If it's an operand, push it as a string
        if (isOperand(ch)) {
            st.push(string(1, ch)); 
        }
        // Step 3: If it's an operator, pop two elements, combine, and push back
        else {
            string op1 = st.top(); st.pop(); 
            string op2 = st.top(); st.pop(); 
            string expr =op1 + op2 + ch;
            st.push(expr);
        }
    }
    return st.top();
}

int main() {

    string postfix = "/-AB*+DEF";
    cout << prefix_to_postfix(postfix) << endl; 
    return 0;
}
