/*1043. Partition Array for Maximum Sum
Solved
Medium
Topics
Companies
Hint
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1*/

// code:-
class Solution
{
public:
    // //recurssion
    // int f(int i,int k,int n,vector<int>&a){
    //     //base case
    //     if(i==n)return 0;

    //     int maxAns=INT_MIN,len=0,maxi=INT_MIN;
    //     for(int j=i;j<min(n,i+k);j++){
    //         len++;
    //         maxi=max(maxi,a[j]);
    //         int sum=len*maxi+f(j+1,k,n,a);
    //         maxAns=max(maxAns,sum);
    //     }
    //     return maxAns;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     int n=arr.size();
    //     return f(0,k,n,arr);
    // }

    // memoization
    //  int f(int i,int k,int n,vector<int>&a,vector<int>&dp){
    //      //base case
    //      if(i==n)return 0;
    //      if(dp[i]!=-1)return dp[i];
    //      int maxAns=INT_MIN,len=0,maxi=INT_MIN;
    //      for(int j=i;j<min(n,i+k);j++){
    //          len++;
    //          maxi=max(maxi,a[j]);
    //          int sum=len*maxi+f(j+1,k,n,a,dp);
    //          maxAns=max(maxAns,sum);
    //      }
    //      return dp[i]=maxAns;
    //  }
    //  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //      int n=arr.size();
    //      vector<int>dp(n,-1);
    //      return f(0,k,n,arr,dp);
    //  }

    // Tabulation
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int maxAns = INT_MIN, len = 0, maxi = INT_MIN;
            for (int j = i; j < min(n, i + k); j++)
            {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};

// prob link:-https://leetcode.com/problems/partition-array-for-maximum-sum/