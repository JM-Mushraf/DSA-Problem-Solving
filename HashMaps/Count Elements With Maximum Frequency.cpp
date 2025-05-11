/*
3005. Count Elements With Maximum Frequency
Solved
Easy
Topics
Companies
Hint
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.



Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
*/

// code:
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> f;
        int max_freq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            f[nums[i]]++;
            max_freq = max(max_freq, f[nums[i]]);
        }
        int count = 0;
        for (auto i : f)
        {
            if (max_freq == i.second)
                count++;
        }
        int ans = max_freq * count;
        return ans;
    }
};

// prob link:https://leetcode.com/problems/count-elements-with-maximum-frequency/