/*494. Target Sum
Solved
Medium
Topics
Companies
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.



Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1*/

// Code:-
class Solution
{
public:
    // Memoization
    //  const int MOD = 1e9 + 7;
    //  int f(int ind, int k, vector<int>& nums, vector<vector<int>>& dp) {
    //      if (ind == 0){
    //  		if(k==0 && nums[0]==0)return 2;
    //  		if(k==0 || k==nums[0])return 1;
    //  		return 0;
    //  	};
    //      if (ind == 0) return (nums[0] == k);
    //      if (dp[ind][k] != -1) return dp[ind][k];

    //     int notTake = f(ind - 1, k, nums, dp);
    //     int take = 0;
    //     if (nums[ind] <= k) take = f(ind - 1, k - nums[ind], nums, dp);

    //     return dp[ind][k] = (take + notTake)%MOD;
    // }

    // int findWays(vector<int>& arr, int k) {
    // 	int n=arr.size();
    // 	vector<vector<int>>dp(n,vector<int>(k+1,-1));
    //     return int(f(n-1,k,arr,dp)%MOD);
    // }

    // Tabulation
    //  const int MOD = 1e9 + 7;
    //  //method1 tabulation
    //  int findWays(vector<int>& arr, int k) {
    //      int n = arr.size();
    //      int countZeros = 0;
    //      vector<int> nonZeroArr;

    //     for (int num : arr) {
    //         if (num == 0) {
    //             countZeros++;
    //         } else {
    //             nonZeroArr.push_back(num);
    //         }
    //     }

    //     int m = nonZeroArr.size();
    //     vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

    //     for (int i = 0; i <= m; i++) {
    //         dp[i][0] = 1;
    //     }

    //     for (int i = 1; i <= m; i++) {
    //         for (int j = 0; j <= k; j++) {
    //             dp[i][j] = dp[i - 1][j]; // Not take
    //             if (nonZeroArr[i - 1] <= j) {
    //                 dp[i][j] = (dp[i][j] + dp[i - 1][j - nonZeroArr[i - 1]]) % MOD; // Take
    //             }
    //         }
    //     }

    //     // Multiply by 2^countZeros to account for all subsets including/excluding zeros
    //     long long ways = dp[m][k];
    //     for (int i = 0; i < countZeros; i++) {
    //         ways = (ways * 2) % MOD;
    //     }

    //     return (int)ways;
    // }

    // Tabulation
    // Method2
    const int MOD = 1e9 + 7;

    int findWays(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= k)
            dp[0][arr[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= k; target++)
            {
                int notTake = dp[ind - 1][target];
                int take = 0;
                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = (take + notTake);
            }
        }
        return dp[n - 1][k];
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totalsum = 0;
        for (auto &i : arr)
            totalsum += i;

        // Edge cases:
        if (totalsum - d < 0 || (totalsum - d) % 2 != 0)
            return 0;

        int target = (totalsum - d) / 2;
        return findWays(arr, target);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};

// prob link:-https://leetcode.com/problems/target-sum/