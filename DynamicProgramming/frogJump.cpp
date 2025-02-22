/*Problem statement
There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:*/
#include <bits/stdc++.h>

// below one is using memoization
int maxJumpHelper(int n, vector<int> &stones, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = maxJumpHelper(n - 1, stones, dp) + abs(stones[n] - stones[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = maxJumpHelper(n - 2, stones, dp) + abs(stones[n] - stones[n - 2]);
    dp[n] = min(left, right);
    return dp[n];
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);

    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
}

// to reduce tghe space used (stack space)
int frogJump(int n, vector<int>& heights) {
    int prev=0;
    int prev2=0;
    for (int i = 1; i < n; i++) {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1) ss = prev2 + abs(heights[i] - heights[i - 2]);
        int curr= min(fs, ss);
        prev2=prev;
        prev=curr;
    }
    return prev;
}