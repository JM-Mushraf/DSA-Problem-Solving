/*122. Best Time to Buy and Sell Stock II
Solved
Medium
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.*/

// code:-
class Solution
{
public:
    // recurssion
    // int f(int i,int buy,vector<int>& prices,int n){
    //     int profit=0;
    //     if(i==n)return 0;
    //     //u can buy stock
    //     if(buy){
    //         profit=max(
    //             //buy stock(take)
    //             -prices[i]+f(i+1,0,prices,n),
    //             //dont buy stock(not take)
    //             0+f(i+1,1,prices,n)
    //         );
    //     }
    //     //u can sell stock
    //     else{
    //         profit=max(
    //             //sell stock(take)
    //             prices[i]+f(i+1,1,prices,n),
    //             //dont sell stock(not take)
    //             0+f(i+1,0,prices,n)
    //         );
    //     }
    //     return profit;
    // }

    // Memoization
    //  int f(int i,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
    //      int profit=0;
    //      if(i==n)return 0;
    //      if(dp[i][buy]!=-1)return dp[i][buy];
    //      //u can buy stock
    //      if(buy){
    //          profit=max(
    //              //buy stock(take)
    //              -prices[i]+f(i+1,0,prices,n,dp),
    //              //dont buy stock(not take)
    //              0+f(i+1,1,prices,n,dp)
    //          );
    //      }
    //      //u can sell stock
    //      else{
    //          profit=max(
    //              //sell stock(take)
    //              prices[i]+f(i+1,1,prices,n,dp),
    //              //dont sell stock(not take)
    //              0+f(i+1,0,prices,n,dp)
    //          );
    //      }
    //      return dp[i][buy]=profit;
    //  }
    //  int maxProfit(vector<int>& prices) {
    //      int n=prices.size();
    //      // dp[n][2]
    //      vector<vector<int>>dp(n,vector<int>(2,-1));
    //      return f(0,1,prices,n,dp);
    //  }

    // Tabulation
    //  int maxProfit(vector<int>& prices) {
    //      int n=prices.size();
    //      // dp[n][2]
    //      vector<vector<int>>dp(n+1,vector<int>(2,0));
    //      int profit=0;
    //      //base case
    //      dp[n][0]=dp[n][1]=0;

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<2;j++){ //j->buy
    //             //u can buy stock
    //             if(j){
    //                 profit=max(
    //                     //buy stock(take)
    //                     -prices[i]+dp[i+1][0],
    //                     //dont buy stock(not take)
    //                     0+dp[i+1][1]
    //                 );
    //             }
    //             //u can sell stock
    //             else{
    //                 profit=max(
    //                     //sell stock(take)
    //                     prices[i]+dp[i+1][1],
    //                     //dont sell stock(not take)
    //                     0+dp[i+1][0]
    //                 );
    //             }
    //             dp[i][j]=profit;
    //         }
    //     }
    //     return dp[0][1];
    // }
    // //space optimization
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     // dp[n][2]
    //     // vector<vector<int>>dp(n+1,vector<int>(2,0));
    //     vector<int>ahead(2,0),curr(2,0);
    //     int profit=0;
    //     //base case
    //     ahead[0]=ahead[1]=0;

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<2;j++){ //j->buy
    //             //u can buy stock
    //             if(j){
    //                 profit=max(
    //                     //buy stock(take)
    //                     -prices[i]+ahead[0],
    //                     //dont buy stock(not take)
    //                     0+ahead[1]
    //                 );
    //             }
    //             //u can sell stock
    //             else{
    //                 profit=max(
    //                     //sell stock(take)
    //                     prices[i]+ahead[1],
    //                     //dont sell stock(not take)
    //                     0+ahead[0]
    //                 );
    //             }
    //             curr[j]=profit;
    //         }
    //         ahead=curr;
    //     }
    //     return ahead[1];
    // }

    // using 4 vars instead arrays
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int aheadbuy, aheadnotbuy, currbuy, currnotbuy;
        aheadnotbuy = aheadbuy = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            // u can buy stock
            currbuy = max(
                // buy stock(take)
                -prices[i] + aheadnotbuy,
                // dont buy stock(not take)
                0 + aheadbuy);
            // u can sell stock
            currnotbuy = max(
                // sell stock(take)
                prices[i] + aheadbuy,
                // dont sell stock(not take)
                0 + aheadnotbuy);
            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return aheadbuy;
    }
};

// prob link:-https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/