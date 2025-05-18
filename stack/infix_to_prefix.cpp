#include<iostream>
#include<stack>
#include<algorithm> // for reverse
using namespace std;

// Function to check if a character is an operand
bool isOperand(char ch) {
    return isalnum(ch); // alphabets or digits
}

// Precedence function
int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

// Function to convert infix to prefix
string infix_to_prefix(string s) {
    // Step 1: Reverse the string
    reverse(s.begin(), s.end());

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    // Step 3: Convert to postfix
    stack<char> st;
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Operand goes directly to result
        if (isOperand(ch)) {
            res += ch;
        }
        // Opening parenthesis
        else if (ch == '(') {
            st.push(ch);
        }
        // Closing parenthesis
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        }
        // Operator
        else {
            while (!st.empty() && precedence(ch) < precedence(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    // Step 4: Reverse result to get prefix
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string infix = "(A-B/C)*(A/K-L)";
    string prefix = infix_to_prefix(infix);
    cout << "Prefix: " << prefix << endl;
    return 0;
}
