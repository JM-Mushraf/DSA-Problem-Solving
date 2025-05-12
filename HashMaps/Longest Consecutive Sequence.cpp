/*
128. Longest Consecutive Sequence
Solved
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
*/

// code:
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end()); // Remove duplicates and store elements
        int maxLen = 0;

        for (int num : s)
        { // iterate only unique elements
            if (!s.count(num - 1))
            { // check only sequence starting points
                int curr = num;
                int len = 1;

                while (s.count(curr + 1))
                {
                    curr++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};

// prob link:https://leetcode.com/problems/longest-consecutive-sequence/?envType=problem-list-v2&envId=hash-table