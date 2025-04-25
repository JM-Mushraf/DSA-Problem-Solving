/*188. Best Time to Buy and Sell Stock IV
Solved
Hard
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.*/

// code:-
class Solution
{
public:
    // recurssion
    //  int f(int ind,int buy,int cap,vector<int>&prices,int n){
    //      if(ind==n || cap==0)return 0;

    //     //u can buy
    //     if(buy)return max(-prices[ind]+f(ind+1,0,cap,prices,n),0+f(ind+1,1,cap,prices,n));

    //     //u can sell
    //     else return max(prices[ind]+f(ind+1,1,cap-1,prices,n),0+f(ind+1,0,cap,prices,n));
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n=prices.size();
    //     return f(0,1,k,prices,n);
    // }

    // memoization
    //  int f(int i,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>&dp){
    //      //base case
    //      if(cap==0)return 0;
    //      if(i==n)return 0;
    //      if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
    //      //you can buy
    //      if(buy){
    //          return dp[i][buy][cap]=max(-prices[i]+f(i+1,0,cap,prices,n,dp),0+f(i+1,1,cap,prices,n,dp));
    //      }
    //      //u can sell
    //      else{
    //          return dp[i][buy][cap]=max(prices[i]+f(i+1,1,cap-1,prices,n,dp),0+f(i+1,0,cap,prices,n,dp));
    //      }
    //  }

    // int maxProfit(int k, vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    //     return f(0,1,k,prices,n,dp);
    // }

    // tabulation
    //  int maxProfit(int k, vector<int>& prices) {
    //      int n=prices.size();
    //      vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    //     //base cases
    //     // for if(cap==0)return 0; in this case ind and buy can be anything
    //     // for(int i=0;i<n;i++){
    //     //     for(int buy=0;buy<2;buy++){
    //     //         dp[i][buy][0]=0;
    //     //     }
    //     // }
    //     // // for if(i==0)return 0; in this case buy and cap can be anything
    //     // for(int buy=0;buy<2;buy++){
    //     //     for(int cap=0;cap<3;cap++){
    //     //         dp[0][buy][cap]=0;
    //     //     }
    //     // }

    //     //loops for changing vars
    //     for(int i=n-1;i>=0;i--){
    //         for(int buy=0;buy<2;buy++){
    //             for(int cap=1;cap<=k;cap++){
    //                 if(buy){
    //                     dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],0+dp[i+1][1][cap]);
    //                 }
    //                 else{
    //                     dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0][1][k];
    // }
    // space optimization
    // int maxProfit(int k, vector<int>& prices) {
    //     int n=prices.size();
    //     // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    //     vector<vector<int>>ahead(2,vector<int>(k+1,0));
    //     vector<vector<int>>curr(2,vector<int>(k+1,0));
    //     //base cases
    //     // for if(cap==0)return 0; in this case ind and buy can be anything
    //     // for(int i=0;i<n;i++){
    //     //     for(int buy=0;buy<2;buy++){
    //     //         ahead[buy][0]=0;
    //     //     }
    //     // }
    //     // // for if(i==0)return 0; in this case buy and cap can be anything
    //     // for(int buy=0;buy<2;buy++){
    //     //     for(int cap=0;cap<3;cap++){
    //     //         ahead[buy][cap]=0;
    //     //     }
    //     // }

    //     //loops for changing vars
    //     for(int i=n-1;i>=0;i--){
    //         for(int buy=0;buy<2;buy++){
    //             for(int cap=1;cap<=k;cap++){
    //                 if(buy){
    //                     curr[buy][cap]=max(-prices[i]+ahead[0][cap],0+ahead[1][cap]);
    //                 }
    //                 else{
    //                     curr[buy][cap]=max(prices[i]+ahead[1][cap-1],0+ahead[0][cap]);
    //                 }
    //             }
    //         }
    //         ahead=curr;
    //     }
    //     return ahead[1][k];
    // }

    // using n*4->tc
    // Recurssion
    // int f(int ind,int t,vector<int>&prices,int n,int k){
    //     if(ind==n || t==k)return 0;

    //     //u can buy
    //     if(t%2==0){
    //         return max(-prices[ind]+f(ind+1,t+1,prices,n,k),0+f(ind+1,t,prices,n,k));
    //     }
    //     //u can sell
    //     else{
    //         return max(prices[ind]+f(ind+1,t+1,prices,n,k),0+f(ind+1,t,prices,n,k));
    //     }
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n=prices.size();
    //     return f(0,0,prices,n,2*k);
    // }
    // memoization
    // int f(int i,int transaction,vector<int>& prices,int n,int k,vector<vector<int>>&dp){
    //     //base case
    //     if(i==n || transaction==k)return 0;
    //     if(dp[i][transaction]!=-1)return dp[i][transaction];
    //     //you can buy
    //     if(transaction%2==0){
    //         return dp[i][transaction]=max(-prices[i]+f(i+1,transaction+1,prices,n,k,dp),0+f(i+1,transaction,prices,n,k,dp));
    //     }
    //     //u can sell
    //     else{
    //         return dp[i][transaction]=max(prices[i]+f(i+1,transaction+1,prices,n,k,dp),0+f(i+1,transaction,prices,n,k,dp));
    //     }
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n,vector<int>(2*k,-1));
    //     return f(0,0,prices,n,2*k,dp);
    // }
    // tabulation
    // int maxProfit(int k, vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

    //     // base case
    //     // for(int t=0;t<4;t++)dp[0][t]=0;
    //     // for(int i=0;i<n;i++)dp[i][4]=0;
    //     //nested loops for changing vars
    //     for(int i=n-1;i>=0;i--){
    //         for(int t=0;t<2*k;t++){
    //             //you can buy
    //             if(t%2==0){
    //                 dp[i][t]=max(-prices[i]+dp[i+1][t+1],0+dp[i+1][t]);
    //             }
    //             //u can sell
    //             else{
    //                 dp[i][t]=max(prices[i]+dp[i+1][t+1],0+dp[i+1][t]);
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }

    // space optimizatiom
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ahead(2 * k + 1, 0);
        vector<int> curr(2 * k + 1, 0);
        // base case
        // for(int t=0;t<4;t++)dp[0][t]=0;
        // for(int i=0;i<n;i++)dp[i][4]=0;
        // nested loops for changing vars
        for (int i = n - 1; i >= 0; i--)
        {
            for (int t = 0; t < 2 * k; t++)
            {
                // you can buy
                if (t % 2 == 0)
                {
                    curr[t] = max(-prices[i] + ahead[t + 1], 0 + ahead[t]);
                }
                // u can sell
                else
                {
                    curr[t] = max(prices[i] + ahead[t + 1], 0 + ahead[t]);
                }
            }
            ahead = curr;
        }
        return ahead[0];
    }
};

// prob link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/