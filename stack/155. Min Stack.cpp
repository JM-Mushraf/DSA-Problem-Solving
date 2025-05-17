/*problem statment:
155. Min Stack
Solved
Medium
Topics
Companies
Hint
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


approach:
🧠 Problem Statement:
Design a stack that supports:

push(val)

pop()

top()

getMin()

All in O(1) time.

🧱 Core Idea:
Use two stacks:

st: the normal stack where you push all elements.

s2: a special stack that keeps track of the minimum element seen so far.

🔍 Why Two Stacks?
➤ st — main stack:
Stores all elements like a regular stack.

➤ s2 — min stack:
Stores only the minimums.

When you push a new value val:

If it's less than or equal to the current min (s2.top()), you push it into s2.

When popping:

If the value you're removing is the same as the current min (s2.top()), you also pop from s2.

This way, the top of s2 always holds the current minimum.

*/
// code:
class MinStack
{
public:
    stack<int> st, s2;
    MinStack()
    {
    }

    void push(int val)
    {
        if (s2.empty() || val <= s2.top())
        {
            s2.push(val);
        }
        st.push(val);
    }

    void pop()
    {
        if (st.top() == s2.top())
        {
            s2.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return s2.top();
    }
};

// prob link:https://leetcode.com/problems/min-stack/?envType=problem-list-v2&envId=stack