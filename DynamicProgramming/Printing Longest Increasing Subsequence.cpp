/* Printing Longest Increasing Subsequence
Moderate
80/80
Contributed by
42 upvotes
Asked in companies
Problem statement
You are given an array 'arr' of length 'n'.



Find the Longest Increasing Subsequence of the array.



A subsequence is a subset of an array achieved by removing some (possibly 0) elements without changing the order of the remaining elements.



Increasing subsequence means a subsequence in which all the elements are strictly increasing.



Longest increasing subsequence is an increasing subsequence that has the largest length possible.



Please note that there may be more than one LIS (Longest Increasing Subsequence) possible. Return any one of the valid sequences.



Example:
Input: ‘arr’ = [5, 6, 3, 4, 7, 6]

Output: LIS = [5, 6, 7] OR [3, 4, 7] OR [3, 4, 6]

Explanation: All these three subsequences are valid Longest Increasing Subsequences. Returning any of them is correct.*/

// code:-
#include <bits/stdc++.h>
using namespace std;

vector<int> printingLongestIncreasingSubsequence(vector<int> nums, int n) {
    vector<int> dp(n, 1);
    vector<int> hash(n); 
    int maxi = 1;
    int lastind = 0;

    for (int i = 0; i < n; i++) {
        hash[i] = i;  // Initialize the hash to point to self
        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            lastind = i;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastind]);
    while (hash[lastind] != lastind) {
        lastind = hash[lastind];
        temp.push_back(nums[lastind]);
    }

    reverse(temp.begin(), temp.end());
    return temp;
}
// prob link:-https://www.naukri.com/code360/problems/printing-longest-increasing-subsequence_8360670?leftPanelTabValue=PROBLEM