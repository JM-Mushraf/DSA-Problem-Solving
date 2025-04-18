/*322. Coin Change
Solved
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104*/

// code:-
class Solution
{
public:
    // Recurssion
    //  int f(int ind,int k,vector<int>& arr){
    //      if(ind==0){
    //          if(k%arr[0]==0) return k/arr[0];
    //          return 1e9;
    //      }
    //      int notTake=0+f(ind-1,k,arr);
    //      int take=INT_MAX;
    //      if(arr[ind]<=k)take=1+f(ind,k-arr[ind],arr);

    //     return min(take,notTake);
    // }

    // memoization
    //  int f(int ind,int k,vector<int>& arr,vector<vector<int>> &dp){
    //      if(ind==0){
    //          if(k%arr[0]==0) return dp[0][k]=k/arr[0];
    //          return 1e9;
    //      }
    //      if(dp[ind][k]!=-1)return dp[ind][k];
    //      int notTake=0+f(ind-1,k,arr,dp);
    //      int take=INT_MAX;
    //      if(arr[ind]<=k)take=1+f(ind,k-arr[ind],arr,dp);

    //     return dp[ind][k]=min(take,notTake);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n=coins.size();
    //     vector<vector<int>>dp(n,vector<int>(amount+1,-1));

    //     int res = f(n - 1, amount, coins,dp);
    //     return res >= 1e9 ? -1 : res;
    // }

    // Tabulation
    //  int coinChange(vector<int>& coins, int amount) {
    //      int n=coins.size();
    //      vector<vector<int>>dp(n,vector<int>(amount+1,0));

    //     //baseCase
    //     for(int i=0;i<=amount;i++){
    //         if(i%coins[0]==0)dp[0][i]=i/coins[0];
    //         else dp[0][i]=1e9;
    //     }
    //     //nested loops for changing vars
    //     for(int ind=1;ind<n;ind++){
    //         for(int t=0;t<=amount;t++){
    //             int notTake=0+dp[ind-1][t];
    //             int take=INT_MAX;
    //             if(coins[ind]<=t)take=1+dp[ind][t-coins[ind]];

    //             dp[ind][t]=min(take,notTake);
    //         }
    //     }

    //     int res = dp[n - 1][amount];
    //     return res >= 1e9 ? -1 : res;
    // }

    // space Optimization
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        // baseCase
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }
        // nested loops for changing vars
        for (int ind = 1; ind < n; ind++)
        {
            for (int t = 0; t <= amount; t++)
            {
                int notTake = 0 + prev[t];
                int take = INT_MAX;
                if (coins[ind] <= t)
                    take = 1 + curr[t - coins[ind]];

                curr[t] = min(take, notTake);
            }
            prev = curr;
        }

        int res = prev[amount];
        return res >= 1e9 ? -1 : res;
    }
};