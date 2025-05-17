/*
496. Next Greater Element I
Solved
Easy
Topics
Companies
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

approach:
🔍 Problem Summary:
You're given two arrays:

nums1: a subset of nums2.

nums2: a list of distinct integers.

🎯 Goal:
For each element in nums1, find its next greater element in nums2 (i.e., the first element greater than it to its right in nums2).

If no such greater element exists, return -1.

✏️ Examples
Example 1:
vbnet
Copy
Edit
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Explanation:
- For 4 → no greater number to its right → -1
- For 1 → next greater is 3 → 3
- For 2 → no greater number to its right → -1
Example 2:
vbnet
Copy
Edit
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]

Explanation:
- For 2 → next greater is 3
- For 4 → no greater → -1
❌ Brute Force (Not optimal)
Loop through each element of nums1, find it in nums2, then look to the right to find the next greater element.

Time: O(n1 * n2) → Not good when nums2 is large.
✅ Optimal Stack-based Approach
We use a Monotonic Stack and a Hash Map.

🎯 Core Idea:
We will:

Use a stack to find the next greater element for each number in nums2.

Store these results in a hash map nextGreater[num] = next greater value.

Loop through nums1 and retrieve answers from the map.

💡 Why a Stack?
We need to efficiently find, for each element in nums2, the next greater element to its right.

We traverse nums2 from left to right and maintain a stack:

The stack keeps elements for which we haven’t yet found a next greater.

Whenever we find a new number greater than stack.top(), that number is the next greater for stack.top().

🧠 Step-by-step Example
Let’s dry-run with:

ini
Copy
Edit
nums1 = [4,1,2]
nums2 = [1,3,4,2]
We process nums2 from left to right:

Initialize:
cpp
Copy
Edit
stack<int> st;
unordered_map<int, int> nextGreater;
i = 0 → num = 1
Stack is empty → push 1

Stack: [1]

i = 1 → num = 3
3 > stack.top() → 1 → pop 1, and say nextGreater[1] = 3

Stack is now empty → push 3

➡️ nextGreater = {1: 3}
➡️ Stack: [3]

i = 2 → num = 4
4 > 3 → pop 3 → nextGreater[3] = 4

Stack is empty → push 4

➡️ nextGreater = {1: 3, 3: 4}
➡️ Stack: [4]

i = 3 → num = 2
2 < 4 → just push 2

➡️ Stack: [4, 2]
➡️ nextGreater unchanged

At the end, remaining elements in the stack don’t have any next greater element, so nothing more is added.

💾 Now Answer nums1
cpp
Copy
Edit
nums1 = [4, 1, 2]
nextGreater = {
  1: 3,
  3: 4
}
4 → not in map → -1

1 → map[1] = 3

2 → not in map → -1

✅ Final output: [-1, 3, -1]
*/

// code:
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1, -1);
        stack<int> st;
        unordered_map<int, int> nextGreater;

        // step1:loop through nums2
        for (int i = 0; i < n2; i++)
        {
            while (!st.empty() && (nums2[i] > st.top()))
            {
                int ele = st.top();
                st.pop();
                nextGreater[ele] = nums2[i];
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < n1; i++)
        {
            if (nextGreater.count(nums1[i]))
            {
                ans[i] = nextGreater[nums1[i]];
            }
        }
        return ans;
    }
};

// prob link:https://leetcode.com/problems/next-greater-element-i/?envType=problem-list-v2&envId=stack