/*Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
0 <= K <= 10^3*/

// code:-

#include <bits/stdc++.h> 
//Recurssion
// bool f(int ind,int k,vector<int> &arr){
//     if(k==0)return true;
//     if(ind==0)return (k==arr[0]);

//     bool notTake=f(ind-1,k,arr);
//     bool take=false;
//     if(arr[ind]<=k)take=f(ind-1,k-arr[ind],arr);

//     return take | notTake;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
    
//     return f(n-1,k,arr);
// }

//Memoization
// bool f(int ind,int k,vector<int> &arr,vector<vector<int>>&dp){
//     if(k==0)return true;
//     if(ind==0)return (k==arr[0]);
//     if(dp[ind][k]!=-1)return dp[ind][k];
//     bool notTake=f(ind-1,k,arr,dp);
//     bool take=false;
//     if(arr[ind]<=k)take=f(ind-1,k-arr[ind],arr,dp);

//     return dp[ind][k]=take | notTake;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>>dp(n,vector<int>(k+1,-1));
//     return f(n-1,k,arr,dp);
// }

//Tabulation
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>>dp(n,vector<bool>(k+1,0));
//     for(int i=0;i<n;i++) dp[i][0]=true;
//     dp[0][arr[0]]=true;
//     for(int ind=1;ind<n;ind++){
//         for(int target=1;target<=k;target++){
//             bool notTake=dp[ind-1][target];
//             bool take=false;
//             if(arr[ind]<=target)take=dp[ind-1][target-arr[ind]];
//             dp[ind][target]=take | notTake;
//         }
//     }
//     return dp[n-1][k];
// }

//SpaceOptimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake=prev[target];
            bool take=false;
            if(arr[ind]<=target)take=prev[target-arr[ind]];
            curr[target]=take | notTake;
        }
        prev=curr;
    }
    return prev[k];
}
