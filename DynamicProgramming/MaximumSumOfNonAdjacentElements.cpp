/*
Problem statement
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 500
1 <= N <= 1000
0 <= ARR[i] <= 10^5

Where 'ARR[i]' denotes the 'i-th' element in the array/list.

Time Limit: 1 sec.
*/
// Code
#include <bits/stdc++.h> 
int f(int ind, vector<int> &nums, vector<int> &dp) {
    if (ind == 0) return nums[0];
    if (ind < 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int notpick = f(ind - 1, nums, dp);

    return dp[ind] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    // vector<int> dp(n+1, -1);
    // return f(n, nums, dp);

    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1)take+=prev2;
        int nontake=0+prev;
        int curr=max(take,nontake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}