/*70. Climbing Stairs
Easy
Topics
Companies
Hint
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step*/
class Solution {
public:
    int climbStairsHelper(int n,vector<int>&dp){
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        dp[n]=climbStairsHelper(n-1,dp)+climbStairsHelper(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int res=climbStairsHelper(n,dp);
        return res;
    }
};