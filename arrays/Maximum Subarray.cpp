/*
53. Maximum Subarray
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

// code:
class Solution {
public:
    // give TLE tc=O(n2)
    // int maxSubArray(vector<int>& nums) {
    //     int n=nums.size();
    //     int max_sum=0;
    //     for(int start=0;start<n;start++){
    //         int curr_sum=0;
    //         for(int end=start;end<n;end++){
    //             curr_sum+=nums[end];
    //             max_sum=max(max_sum,curr_sum);
    //         }
    //     }
    //     return max_sum;
    // }

    //optimized using kadanes algo
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=nums[0];
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            max_sum=max(max_sum,curr);

            if(curr<0){
                curr=0;
            }
        }
        return max_sum;
    }
};