/*
238. Product of Array Except Self
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

// code:
class Solution {
public:
    //TC:O(n2)->TLE
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int>ans;

    //     int n=nums.size();

    //     for(int i=0;i<n;i++){
    //         int prod=1;
    //         for(int j=0;j<n;j++){
    //             if(i!=j){
    //                 prod*=nums[j];
    //             }
    //         }
    //         ans.push_back(prod);
    //     }
    //     return ans;
    // }

    //Exceeds Space complexity
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);

        //calc prefix
        for(int i=1;i<n;i++){
            prefix[i]=nums[i-1]*prefix[i-1];
        }
        //calc suffix
        for(int i=n-2;i>=0;i--){
            suffix[i]=nums[i+1]*suffix[i+1];
        }
        //calc ans
        for(int i=0;i<n;i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }

    //space optimized
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);

        //calc prefix
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        //calc suffix and ans
        int suffix=1;
        // ans[n-1]=ans[n-2]*suffix;
        for(int i=n-2;i>=0;i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;
        }
        return ans;
    }
};