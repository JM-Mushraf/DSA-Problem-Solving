/*
217. Contains Duplicate
Solved
Easy
Topics
Companies
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.
*/

// Code:
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> f;
        for (int i = 0; i < nums.size(); i++)
        {
            f[nums[i]]++;
            if (f[nums[i]] > 1)
                return true;
        }
        // for(auto i:f){
        //     if(i.second>1){
        //         return true;
        //     }
        // }
        return false;
    }
};

// prob link:https://leetcode.com/problems/contains-duplicate/?envType=problem-list-v2&envId=hash-table