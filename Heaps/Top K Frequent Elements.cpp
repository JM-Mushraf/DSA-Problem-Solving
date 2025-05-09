/*
347. Top K Frequent Elements
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

// code:
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> f;
        for (auto i : nums)
        {
            f[i]++;
        }

        priority_queue<pair<int, int>> max_heap;
        for (auto &i : f)
        {
            max_heap.push({i.second, i.first});
        }
        vector<int> res;
        for (int i = 1; i <= k; i++)
        {
            auto ans = max_heap.top();
            res.push_back(ans.second);
            max_heap.pop();
        }
        return res;
    }
};

// prob link:https://leetcode.com/problems/top-k-frequent-elements/?envType=problem-list-v2&envId=heap-priority-queue