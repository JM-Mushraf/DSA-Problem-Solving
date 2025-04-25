/*714. Best Time to Buy and Sell Stock with Transaction Fee
Solved
Medium
Topics
Companies
Hint
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.


Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
*/

// Code:-
class Solution
{
public:
    // recurssion
    // int f(int i,int buy,vector<int>& prices,int n,int fee){
    //     if(i==n)return 0;
    //     //u can buy stock
    //     if(buy){
    //        return max(-prices[i]+f(i+1,0,prices,n,fee),0+f(i+1,1,prices,n,fee));
    //     }
    //     //u can sell stock
    //     else{
    //         return max(prices[i]-fee+f(i+1,1,prices,n,fee),0+f(i+1,0,prices,n,fee));
    //     }
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n=prices.size();
    //     return f(0,1,prices,n,fee);
    // }

    // Memoization
    // int f(int i,int buy,vector<int>& prices,int n,vector<vector<int>>&dp,int fee){
    //     if(i==n)return 0;
    //     if(dp[i][buy]!=-1)return dp[i][buy];
    //     //u can buy stock
    //     if(buy){
    //        return dp[i][buy]=max(-prices[i]+f(i+1,0,prices,n,dp,fee),0+f(i+1,1,prices,n,dp,fee));
    //     }
    //     //u can sell stock
    //     else{
    //         return dp[i][buy]=max(prices[i]-fee+f(i+1,1,prices,n,dp,fee),0+f(i+1,0,prices,n,dp,fee));
    //     }
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n=prices.size();
    //     // dp[n][2]
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //     return f(0,1,prices,n,dp,fee);
    // }

    // Tabulation
    //     int maxProfit(vector<int>& prices, int fee) {
    //         int n=prices.size();
    //         // dp[n][2]
    //         vector<vector<int>>dp(n+1,vector<int>(2,0));
    //         //base case
    //         dp[n][0]=dp[n][1]=0;

    //         for(int i=n-1;i>=0;i--){
    //             //u can buy stock
    //                 dp[i][1]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
    //             //u can sell stock
    //                 dp[i][0]=max(prices[i]-fee+dp[i+1][1],0+dp[i+1][0]);
    //         }
    //     return dp[0][1];
    // }
    // space optimization
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        // dp[n][2]
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int> ahead(2, 0), curr(2, 0);
        int profit = 0;
        // base case
        ahead[0] = ahead[1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            // u can buy stock
            curr[1] = max(-prices[i] + ahead[0], 0 + ahead[1]);
            // u can sell stock
            curr[0] = max(prices[i] - fee + ahead[1], 0 + ahead[0]);
            ahead = curr;
        }
        return ahead[1];
    }
};

// prob link:-https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/