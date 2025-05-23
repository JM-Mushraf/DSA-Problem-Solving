/*
150. Evaluate Reverse Polish Notation
Solved
Medium
Topics
Companies
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/

// code:
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (const string &token : tokens)
        {
            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
            {
                // Token is a number
                st.push(stoi(token));
            }
            else
            {
                // Token is an operator
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                int res = 0;

                if (token == "+")
                    res = op1 + op2;
                else if (token == "-")
                    res = op1 - op2;
                else if (token == "*")
                    res = op1 * op2;
                else if (token == "/")
                    res = op1 / op2;

                st.push(res);
            }
        }

        return st.top();
    }
};
// prob link:https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=problem-list-v2&envId=stack