/*
123. Best Time to Buy and Sell Stock III
Solved
Hard
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
*/

// Code:-
class Solution {
    public:
        // Recurssion
        // int f(int i,int buy,int cap,vector<int>& prices,int n){
        //     //base case
        //     if(cap==0)return 0;
        //     if(i==n)return 0;
    
        //     //you can buy
        //     if(buy){
        //         return max(-prices[i]+f(i+1,0,cap,prices,n),0+f(i+1,1,cap,prices,n));
        //     }
        //     //u can sell
        //     else{
        //         return max(prices[i]+f(i+1,1,cap-1,prices,n),0+f(i+1,0,cap,prices,n));
        //     }
        // }
        // int maxProfit(vector<int>& prices) {
        //     int n=prices.size();
        //     return f(0,1,2,prices,n);
        // }
    
        //Memoization
        // int f(int i,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>&dp){
        //     //base case
        //     if(cap==0)return 0;
        //     if(i==n)return 0;
        //     if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        //     //you can buy
        //     if(buy){
        //         return dp[i][buy][cap]=max(-prices[i]+f(i+1,0,cap,prices,n,dp),0+f(i+1,1,cap,prices,n,dp));
        //     }
        //     //u can sell
        //     else{
        //         return dp[i][buy][cap]=max(prices[i]+f(i+1,1,cap-1,prices,n,dp),0+f(i+1,0,cap,prices,n,dp));
        //     }
        // }
        // int maxProfit(vector<int>& prices) {
        //     int n=prices.size();
        //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        //     return f(0,1,2,prices,n,dp);
        // }
    
        // Tabulation
        // int maxProfit(vector<int>& prices) {
        //     int n=prices.size();
        //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    
        //     //base cases
        //     // for if(cap==0)return 0; in this case ind and buy can be anything
        //     for(int i=0;i<n;i++){
        //         for(int buy=0;buy<2;buy++){
        //             dp[i][buy][0]=0;
        //         }
        //     }
        //     // for if(i==0)return 0; in this case buy and cap can be anything
        //     for(int buy=0;buy<2;buy++){
        //         for(int cap=0;cap<3;cap++){
        //             dp[0][buy][cap]=0;
        //         }
        //     }
    
        //     //loops for changing vars
        //     for(int i=n-1;i>=0;i--){
        //         for(int buy=0;buy<2;buy++){
        //             for(int cap=1;cap<3;cap++){
        //                 if(buy){
        //                     dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],0+dp[i+1][1][cap]);
        //                 } 
        //                 else{
        //                     dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
        //                 }   
        //             }
        //         }
        //     }
        //     return dp[0][1][2];
        // }
    
        //space optimization
        // int maxProfit(vector<int>& prices) {
        //     int n=prices.size();
        //     // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        //     vector<vector<int>>ahead(2,vector<int>(3,0));
        //     vector<vector<int>>curr(2,vector<int>(3,0));
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
        //             for(int cap=1;cap<3;cap++){
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
        //     return ahead[1][2];
        // }
    
        // using n*4->tc
        // Recurssion
        // int f(int i,int transaction,vector<int>& prices,int n){
        //     //base case
        //     if(i==n || transaction==4)return 0;
    
        //     //you can buy
        //     if(transaction%2==0){
        //         return max(-prices[i]+f(i+1,transaction+1,prices,n),0+f(i+1,transaction,prices,n));
        //     }
        //     //u can sell
        //     else{
        //         return max(prices[i]+f(i+1,transaction+1,prices,n),0+f(i+1,transaction,prices,n));
        //     }
        // }
        // int maxProfit(vector<int>& prices) {
        //     int n=prices.size();
        //     return f(0,0,prices,n);
        // }
    
        // //memoization
        // int f(int i,int transaction,vector<int>& prices,int n,vector<vector<int>>&dp){
        //     //base case
        //     if(i==n || transaction==4)return 0;
        //     if(dp[i][transaction]!=-1)return dp[i][transaction];
        //     //you can buy
        //     if(transaction%2==0){
        //         return dp[i][transaction]=max(-prices[i]+f(i+1,transaction+1,prices,n,dp),0+f(i+1,transaction,prices,n,dp));
        //     }
        //     //u can sell
        //     else{
        //         return dp[i][transaction]=max(prices[i]+f(i+1,transaction+1,prices,n,dp),0+f(i+1,transaction,prices,n,dp));
        //     }
        // }
        // int maxProfit(vector<int>& prices) {
        //     int n=prices.size();
        //     vector<vector<int>>dp(n,vector<int>(4,-1));
        //     return f(0,0,prices,n,dp);
        // }
    
        //tabulation
        // int maxProfit(vector<int>& prices) {
        //     int n=prices.size();
        //     vector<vector<int>>dp(n+1,vector<int>(5,0));
    
        //     // base case
        //     // for(int t=0;t<4;t++)dp[0][t]=0;
        //     // for(int i=0;i<n;i++)dp[i][4]=0;
        //     //nested loops for changing vars
        //     for(int i=n-1;i>=0;i--){
        //         for(int t=0;t<4;t++){
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
    
        //space optimizatiom
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<int>ahead(5,0);
            vector<int>curr(5,0);
            // base case
            // for(int t=0;t<4;t++)dp[0][t]=0;
            // for(int i=0;i<n;i++)dp[i][4]=0;
            //nested loops for changing vars
            for(int i=n-1;i>=0;i--){
                for(int t=0;t<4;t++){
                    //you can buy
                    if(t%2==0){
                        curr[t]=max(-prices[i]+ahead[t+1],0+ahead[t]);
                    }
                    //u can sell
                    else{
                        curr[t]=max(prices[i]+ahead[t+1],0+ahead[t]);
                    }       
                }
                ahead=curr;
            }
            return ahead[0];
        }
    };

    // prob link:-https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/