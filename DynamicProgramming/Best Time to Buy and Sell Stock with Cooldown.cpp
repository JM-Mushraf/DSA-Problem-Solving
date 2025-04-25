/*309. Best Time to Buy and Sell Stock with Cooldown
Solved
Medium
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).*/

// Code:-
class Solution
{
public:
    // recurssion
    //  int f(int ind,int buy,vector<int>&prices,int n){
    //      if(ind>=n)return 0;

    //     //u can buy
    //     if(buy)return max(-prices[ind]+f(ind+1,0,prices,n),0+f(ind+1,1,prices,n));

    //     //u can selll
    //     else return max(prices[ind]+f(ind+2,1,prices,n),0+f(ind+1,0,prices,n));
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     return f(0,1,prices,n);
    // }
    // Memoization
    //  int f(int i,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
    //      if(i>=n)return 0;
    //      if(dp[i][buy]!=-1)return dp[i][buy];
    //      //u can buy stock
    //      if(buy){
    //         return dp[i][buy]=max( -prices[i]+f(i+1,0,prices,n,dp),0+f(i+1,1,prices,n,dp));
    //      }
    //      //u can sell stock
    //      else{
    //          return dp[i][buy]=max(prices[i]+f(i+2,1,prices,n,dp),0+f(i+1,0,prices,n,dp));
    //      }
    //  }
    //  int maxProfit(vector<int>& prices) {
    //      int n=prices.size();
    //      vector<vector<int>>dp(n,vector<int>(2,-1));
    //      return f(0,1,prices,n,dp);
    //  }

    // Tabulation
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n+2,vector<int>(2,0));
    //     int profit=0;
    //     //base case
    //     dp[n][0]=dp[n][1]=0;

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<2;j++){ //j->buy
    //             //u can buy stock
    //             if(j){
    //                 dp[i][j]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
    //             }
    //             //u can sell stock
    //             else{
    //                 dp[i][j]=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
    //             }
    //         }
    //     }
    //     return dp[0][1];
    // }

    // Tabulation
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n+2,vector<int>(2,0));
    //     int profit=0;
    //     //base case
    //     dp[n][0]=dp[n][1]=0;

    //     for(int i=n-1;i>=0;i--){
    //         dp[i][1]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);

    //         dp[i][0]=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
    //     }
    //     return dp[0][1];
    // }

    // space optimization
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> curr(2, 0);
        int profit = 0;
        // base case
        //  dp[n][0]=dp[n][1]=0;

        for (int i = n - 1; i >= 0; i--)
        {
            curr[1] = max(-prices[i] + front1[0], 0 + front1[1]);

            curr[0] = max(prices[i] + front2[1], 0 + front1[0]);

            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};

// prob link:"https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/"