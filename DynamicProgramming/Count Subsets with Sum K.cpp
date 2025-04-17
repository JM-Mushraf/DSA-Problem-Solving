/*Problem statement
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.



Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.



Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.



Example:
Input: 'arr' = [1, 1, 4, 5]

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.*/

// code:-
//Recurssion
// int f(int ind,int k,vector<int>& nums){
//     if (ind == 0) {
//         if (k == 0 && nums[0] == 0) return 2;
//         return (nums[0] == k) ? 1 : 0;
//     }
//     if(ind==0) return (nums[0]==k);

//     int notTake=f(ind-1,k,nums);
//     int take=0;
//     if(nums[ind]<=k)take=f(ind-1,k-nums[ind],nums);
//     return notTake+take;
// }

//Memoization
const int MOD = 1e9 + 7;
int f(int ind, int k, vector<int>& nums, vector<vector<int>>& dp) {
    if (ind == 0){
		if(k==0 && nums[0]==0)return 2;
		if(k==0 || k==nums[0])return 1;
		return 0;
	};
    if (ind == 0) return (nums[0] == k);
    if (dp[ind][k] != -1) return dp[ind][k];
    
    int notTake = f(ind - 1, k, nums, dp);
    int take = 0;
    if (nums[ind] <= k) take = f(ind - 1, k - nums[ind], nums, dp);
    
    return dp[ind][k] = (take + notTake)%MOD;
}

int findWays(vector<int>& arr, int k) {
	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return int(f(n-1,k,arr,dp)%MOD);
}

//Tabulation
// const int MOD = 1e9 + 7;

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
