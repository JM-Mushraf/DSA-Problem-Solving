/*
Problem statement
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.

For example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first line of each test case contains two space-separated integers, ‘N’ and ‘D,’ denoting the number of elements in the array and the desired difference.

The following line contains N integers denoting the space-separated integers ‘ARR’.
Output Format :
For each test case, find the number of partitions satisfying the above conditions modulo 10^9 + 7.
Output for each test case will be printed on a separate line.
*/

// code:-

#include <bits/stdc++.h> 
//Memoization
// const int MOD = 1e9 + 7;
// int f(int ind, int k, vector<int>& nums, vector<vector<int>>& dp) {
//     if (ind == 0){
// 		if(k==0 && nums[0]==0)return 2;
// 		if(k==0 || k==nums[0])return 1;
// 		return 0;
// 	};
//     if (ind == 0) return (nums[0] == k);
//     if (dp[ind][k] != -1) return dp[ind][k];
    
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

//Tabulation
// const int MOD = 1e9 + 7;
// //method1 tabulation
// int findWays(vector<int>& arr, int k) {
//     int n = arr.size();
//     int countZeros = 0;
//     vector<int> nonZeroArr;
    
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

//Tabulation
//Method2
const int MOD = 1e9 + 7;

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));

    if(arr[0]==0)dp[0][0]=2;
    else dp[0][0]=1;

    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]]=1;

    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=k;target++){
            int notTake=dp[ind-1][target];
            int take=0;
            if(arr[ind]<=target)take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=(take + notTake)%MOD;
        }
    }
    return dp[n-1][k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum = 0;
    for (auto &i : arr) totalsum += i;
    
    // Edge cases:
    if (totalsum - d < 0 || (totalsum - d) % 2 != 0) return 0;
    
    int target = (totalsum - d) / 2;
    return findWays(arr, target);
}