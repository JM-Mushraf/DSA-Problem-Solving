/*
42. Trapping Rain Water
Solved
Hard
Topics
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

*/

// code:
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int lmax = 0;
        int rmax = 0;
        int total = 0;
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            if (height[l] <= height[r])
            {
                if (lmax > height[l])
                {
                    total += lmax - height[l];
                }
                else
                {
                    lmax = height[l];
                }
                l++;
            }
            else
            {
                if (rmax > height[r])
                {
                    total += rmax - height[r];
                }
                else
                {
                    rmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};

// prob link:https://leetcode.com/problems/trapping-rain-water/description/?envType=problem-list-v2&envId=stack