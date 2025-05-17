/*
prob stmt:
232. Implement Queue using Stacks
Solved
Easy
Topics
Companies
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


approach:
🧠 Problem Statement:
You need to implement a queue (FIFO — First In First Out) using two stacks (which are LIFO — Last In First Out).

Your queue should support:

push(x) → add to the back

pop() → remove from the front

peek() → get the front element

empty() → check if queue is empty

All operations should be O(1) amortized time.

📦 Core Idea: Using Two Stacks
➤ in stack:
Used when you push(x). Always push into in.

➤ out stack:
Used when you want to pop() or peek().

💡 Trick:
Only move elements from in to out when out is empty. This reverses the order and gives you the front of the queue at the top of out.


*/

// code:
class MyQueue
{
public:
    stack<int> in, out;
    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        int val = peek();
        out.pop();
        return val;
    }

    int peek()
    {
        if (out.empty())
        {
            while (in.empty() == false)
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty()
    {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


//  prob link:https://leetcode.com/problems/implement-queue-using-stacks/?envType=problem-list-v2&envId=stack