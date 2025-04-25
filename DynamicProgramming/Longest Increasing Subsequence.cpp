/*300. Longest Increasing Subsequence
Solved
Medium
Topics
Companies
Given an integer array nums, return the length of the longest strictly increasing subsequence.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1*/

// code:-
class Solution
{
public:
    // //Recurssion
    // int f(int ind,int prev_ind,int n,vector<int>&nums){

    //     //base case
    //     if(ind==n)return 0;

    //     //not take
    //     int notTake=0+f(ind+1,prev_ind,n,nums);
    //     int take=INT_MIN;
    //     //take
    //     if(prev_ind==-1 || nums[ind]>nums[prev_ind])take=1+f(ind+1,ind,n,nums);

    //     return max(take,notTake);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     return f(0,-1,n,nums);
    // }

    // Recurssion
    //  int f(int ind,int prev_ind,int n,vector<int>&nums,vector<vector<int>>&dp){

    //     //base case
    //     if(ind==n)return 0;

    //     if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
    //     //not take
    //     int notTake=0+f(ind+1,prev_ind,n,nums,dp);
    //     int take=INT_MIN;
    //     //take
    //     if(prev_ind==-1 || nums[ind]>nums[prev_ind])take=1+f(ind+1,ind,n,nums,dp);

    //     return dp[ind][prev_ind+1]=max(take,notTake);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     //co-ordinate change for prev_ind
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return f(0,-1,n,nums,dp);
    // }

    // //Tabulation
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     //co-ordinate change for prev_ind
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     // if(ind==n)return 0; -->ind is 0 prev_ind can be anything
    //     // for(int i=0;i<=n;i++){
    //     //     dp[0][i]=0;
    //     // }

    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prev_ind = ind - 1; prev_ind >= -1; prev_ind--){
    //             //not take
    //             int notTake=0+dp[ind+1][prev_ind+1];//to handle-1
    //             int take=INT_MIN;
    //             //take
    //             if(prev_ind==-1 || nums[ind]>nums[prev_ind])take=1+dp[ind+1][ind+1];

    //             dp[ind][prev_ind+1]=max(take,notTake);
    //         }
    //     }
    //     return dp[0][0];
    // }

    // space optimization
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // co-ordinate change for prev_ind
        vector<int> ahead(n + 1, 0);
        vector<int> curr(n + 1, 0);
        // if(ind==n)return 0; -->ind is 0 prev_ind can be anything
        // for(int i=0;i<=n;i++){
        //     dp[0][i]=0;
        // }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                // not take
                int notTake = 0 + ahead[prev_ind + 1]; // to handle-1
                int take = INT_MIN;
                // take
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                    take = 1 + ahead[ind + 1];

                curr[prev_ind + 1] = max(take, notTake);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};

// prob link:-https://leetcode.com/problems/longest-increasing-subsequence/