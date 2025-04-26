/*368. Largest Divisible Subset
Solved
Medium
Topics
Companies
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]*/

// Code:-

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();

        // sort array
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 1;
        int lastind = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastind = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastind]);
        while (hash[lastind] != lastind)
        {
            lastind = hash[lastind];
            temp.push_back(nums[lastind]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};

// prob link:-https://leetcode.com/problems/largest-divisible-subset/