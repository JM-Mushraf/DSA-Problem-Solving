/*
2104. Sum of Subarray Ranges
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums. 
The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
*/

// code:
class Solution {
public:
    //subarray min
    vector<int> prev_min(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> next_min(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        long long res = 0;
        int n = arr.size();
        vector<int> prevmin = prev_min(arr);
        vector<int> nextmin = next_min(arr);

        for (int i = 0; i < n; i++) {
            long long left = i - prevmin[i];
            long long right = nextmin[i] - i;
            res += left * right * (long long)arr[i];
        }
        return res;
    }

    //subarray max
    vector<int> prev_max(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> next_max(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        long long res = 0;
        int n = arr.size();
        vector<int> prevmax = prev_max(arr);
        vector<int> nextmax = next_max(arr);

        for (int i = 0; i < n; i++) {
            long long left = i - prevmax[i];
            long long right = nextmax[i] - i;
            res += left * right * (long long)arr[i];
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
// prob link:https://leetcode.com/problems/sum-of-subarray-ranges/?envType=problem-list-v2&envId=stack