/*518. Coin Change II
Solved
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.



Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.*/

// code
class Solution
{
public:
    // recurssion
    //  int f(int ind,int k,vector<int>&arr){
    //      if(ind==0){
    //          return (k % arr[0] == 0) ? 1 : 0;
    //      }
    //      int notTake=f(ind-1,k,arr);
    //      int take=0;
    //      if(arr[ind]<=k)take=f(ind,k-arr[ind],arr);
    //      return take+notTake;
    //  }
    //  int change(int amount, vector<int>& coins) {
    //      int n=coins.size();
    //      int res=f(n-1,amount,coins);
    //      return res;
    //  }

    // memoization
    //  int f(int ind,int k,vector<int>&arr,vector<vector<int>>&dp){
    //      if(ind==0){
    //          return (k % arr[0] == 0) ? 1 : 0;
    //      }
    //      if(dp[ind][k]!=-1)return dp[ind][k];
    //      int notTake=f(ind-1,k,arr,dp);
    //      int take=0;
    //      if(arr[ind]<=k)take=f(ind,k-arr[ind],arr,dp);
    //      return dp[ind][k]=take+notTake;
    //  }
    //  int change(int amount, vector<int>& coins) {
    //      int n=coins.size();
    //      vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    //      return f(n-1,amount,coins,dp);
    //  }

    // Tabulation
    //  int change(int amount, vector<int>& coins) {
    //      int n=coins.size();
    //      vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));

    //     //base case
    //     for(int i=0;i<=amount;i++){
    //         dp[0][i]=(i%coins[0]==0);
    //     }

    //     //nested for loops for changing vars
    //     for(int ind=1;ind<n;ind++){
    //         for(int k=0;k<=amount;k++){
    //             unsigned long long notTake=dp[ind-1][k];
    //             unsigned long long take=0;
    //             if(coins[ind]<=k)take=dp[ind][k-coins[ind]];
    //             dp[ind][k]=take+notTake;
    //         }
    //     }
    //     return dp[n-1][amount];
    // }

    // space optimization
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<unsigned long long> prev(amount + 1, 0);
        vector<unsigned long long> curr(amount + 1, 0);

        // base case
        for (int i = 0; i <= amount; i++)
        {
            prev[i] = (i % coins[0] == 0);
        }

        // nested for loops for changing vars
        for (int ind = 1; ind < n; ind++)
        {
            for (int k = 0; k <= amount; k++)
            {
                unsigned long long notTake = prev[k];
                unsigned long long take = 0;
                if (coins[ind] <= k)
                    take = curr[k - coins[ind]];
                curr[k] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};

//prob link:-https://leetcode.com/problems/coin-change-ii/