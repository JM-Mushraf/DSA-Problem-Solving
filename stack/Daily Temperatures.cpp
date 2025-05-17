/*
739. Daily Temperatures
Solved
Medium
Topics
Companies
Hint
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.



Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

approach:
🔥 Problem: Daily Temperatures
You’re given an array temperatures[] where temperatures[i] is the temperature on day i.

❓ You need to find:
For each day i, how many days you have to wait until you get a warmer temperature.

If no such day exists in the future, return 0 for that day.

📘 Examples
Example 1:
makefile
Copy
Edit
Input:  [73,74,75,71,69,72,76,73]
Output: [1, 1, 4, 2, 1, 1, 0, 0]
Explanation:

Day 0 → 73 → next warmer is 74 (at day 1) → wait 1

Day 1 → 74 → next warmer is 75 (at day 2) → wait 1

Day 2 → 75 → next warmer is 76 (at day 6) → wait 4

Day 3 → 71 → next warmer is 72 (at day 5) → wait 2

Day 4 → 69 → next warmer is 72 (at day 5) → wait 1

Day 5 → 72 → next warmer is 76 (at day 6) → wait 1

Day 6 → 76 → no warmer → 0

Day 7 → 73 → no warmer → 0

🧠 Brute Force (Naive)
Check every i with every future day j > i, until you find a warmer day.

Time complexity: O(n²)
Not good for large inputs.

⚡ Optimized Solution — Using a Stack
Core Idea:
Use a monotonic decreasing stack that stores indices of the temperatures.

We’ll traverse the array from left to right, and for each temperature:

While the stack is not empty and current temp > temp[stack.top()],

Pop the index from stack → calculate the wait time for that popped index

Push the current index onto the stack

📦 Step-by-Step Example
Input: [73,74,75,71,69,72,76,73]
Let’s initialize:

cpp
Copy
Edit
stack<int> st;         // to hold indices
vector<int> ans(n, 0); // default 0
i = 0, temp = 73
Stack is empty → push 0

Stack: [0]

i = 1, temp = 74
74 > 73 → pop 0, and ans[0] = 1 - 0 = 1

push 1

Stack: [1]
ans: [1,,,,,,,_]

i = 2, temp = 75
75 > 74 → pop 1, ans[1] = 2 - 1 = 1

push 2

Stack: [2]
ans: [1,1,,,,,,]

i = 3, temp = 71
71 < 75 → just push 3

Stack: [2,3]

i = 4, temp = 69
69 < 71 → push 4

Stack: [2,3,4]

i = 5, temp = 72
72 > 69 → pop 4 → ans[4] = 5 - 4 = 1

72 > 71 → pop 3 → ans[3] = 5 - 3 = 2

push 5

Stack: [2,5]
ans: [1,1,,2,1,,,]

i = 6, temp = 76
76 > 72 → pop 5 → ans[5] = 6 - 5 = 1

76 > 75 → pop 2 → ans[2] = 6 - 2 = 4

push 6

Stack: [6]

i = 7, temp = 73
73 < 76 → push 7

Stack: [6,7]

At end, remaining stack elements (6,7) → no warmer days → their answer remains 0
*/

// code:
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && (temperatures[i] > temperatures[st.top()]))
            {
                int ind = st.top();
                st.pop();
                ans[ind] = i - ind;
            }
            st.push(i);
        }
        return ans;
    }
};

// prob link:https://leetcode.com/problems/daily-temperatures/?envType=problem-list-v2&envId=stack