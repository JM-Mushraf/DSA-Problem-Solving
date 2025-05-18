#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char ch) {
    return isalnum(ch); // a-z, A-Z, 0-9
}

string postfix_to_prefix(string s) {
    stack<string> st;
    int n=s.size();
    // Step 1: Loop through each character in the postfix string
    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // Step 2: If it's an operand, push it as a string
        if (isOperand(ch)) {
            st.push(string(1, ch)); 
        }
        // Step 3: If it's an operator, pop two elements, combine, and push back
        else {
            string op1 = st.top(); st.pop(); 
            string op2 = st.top(); st.pop(); 
            string expr = ch + op2 + op1 ;
            st.push(expr);
        }
    }
    return st.top();
}

int main() {

    string postfix = "AB-DE+F*/";
    cout << postfix_to_prefix(postfix) << endl; 
    return 0;
}
