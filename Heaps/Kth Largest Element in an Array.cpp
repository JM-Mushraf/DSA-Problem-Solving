/*
215. Kth Largest Element in an Array
Medium
Topics
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?



Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

// Code:-
class Solution
{
public:
    int findKthLargest(vector<int> &arr, int k)
    {
        int n = arr.size();

        priority_queue<int, vector<int>, greater<int>> pq;
        // step1:create min heap for k elements
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        // step2:compare reamining elements with heap top
        for (int i = k; i < n; i++)
        {
            if (arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // step 3:ans =heap.top();
        int ans = pq.top();
        return ans;
    }
};
// prob link:-https://leetcode.com/problems/kth-largest-element-in-an-array/