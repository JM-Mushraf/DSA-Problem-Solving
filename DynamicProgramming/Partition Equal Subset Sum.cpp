/*416. Partition Equal Subset Sum
Solved
Medium
Topics
Companies
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.*/
//Code:-

class Solution {
    public:
        //Recurssion
    // bool f(int ind,int k,vector<int> &arr){
    //     if(k==0)return true;
    //     if(ind==0)return (k==arr[0]);
    
    //     bool notTake=f(ind-1,k,arr);
    //     bool take=false;
    //     if(arr[ind]<=k)take=f(ind-1,k-arr[ind],arr);
    
    //     return take | notTake;
    // }
    // bool subsetSumToK(int n, int k, vector<int> &arr) {
        
    //     return f(n-1,k,arr);
    // }
    
    //Memoization
    // bool f(int ind,int k,vector<int> &arr,vector<vector<int>>&dp){
    //     if(k==0)return true;
    //     if(ind==0)return (k==arr[0]);
    //     if(dp[ind][k]!=-1)return dp[ind][k];
    //     bool notTake=f(ind-1,k,arr,dp);
    //     bool take=false;
    //     if(arr[ind]<=k)take=f(ind-1,k-arr[ind],arr,dp);
    
    //     return dp[ind][k]=take | notTake;
    // }
    // bool subsetSumToK(int n, int k, vector<int> &arr) {
    //     vector<vector<int>>dp(n,vector<int>(k+1,-1));
    //     return f(n-1,k,arr,dp);
    // }
    
    // Tabulation
    // bool subsetSumToK(int n, int k, vector<int> &arr) {
    //     vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    //     for(int i=0;i<n;i++)  dp[i][0]=true;
    //     if(arr[0]<=k) dp[0][arr[0]]=true;
    //     for(int ind=1;ind<n;ind++){
    //         for(int target=1;target<=k;target++){
    //             bool notTake=dp[ind-1][target];
    //             bool take=false;
    //             if(arr[ind]<=target)take=dp[ind-1][target-arr[ind]];
    //             dp[ind][target]=take | notTake;
    //         }
    //     }
    //     return dp[n-1][k];
    // }
    
    //SpaceOptimization
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        if(arr[0]<=k)prev[arr[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool notTake=prev[target];
                bool take=false;
                if(arr[ind]<=target)take=prev[target-arr[ind]];
                curr[target]=take | notTake;
            }
            prev=curr;
        }
        return prev[k];
        }
    
        //above function written by own 
        bool canPartition(vector<int>& nums) {
            int n= nums.size();
            
            int totsum=0;
            for(int i=0;i<n;i++)totsum+=nums[i];
    
            if(totsum%2) return false;
            int target=totsum/2;
            return subsetSumToK(n, target, nums);
        }
    };