/*1143. Longest Common Subsequence
Solved
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.*/
// code:-
class Solution
{
public:
    // recurssion
    //  int f(int ind1,int ind2,string s1, string s2){
    //      if(ind1<0 || ind2<0)return 0;

    //     //match
    //     if(s1[ind1]==s2[ind2]){
    //         return 1+f(ind1-1,ind2-1,s1,s2);
    //     }
    //     //no match
    //     return 0+max(f(ind1-1,ind2,s1,s2),f(ind1,ind2-1,s1,s2));
    // }
    // Memoization
    // int f(int ind1,int ind2,string s1, string s2,vector<vector<int>>&dp){
    //     if(ind1<0 || ind2<0)return 0;

    //     if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    //     //match
    //     if(s1[ind1]==s2[ind2]){
    //         return dp[ind1][ind2]=1+f(ind1-1,ind2-1,s1,s2,dp);
    //     }
    //     //no match
    //     return dp[ind1][ind2]=0+max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int ind1=text1.size();
    //     int ind2=text2.size();
    //     vector<vector<int>>dp(ind1,vector<int>(ind2,-1));
    //     return f(ind1-1,ind2-1,text1,text2,dp);
    // }

    // Tabulation
    //  int longestCommonSubsequence(string text1, string text2) {
    //      int n=text1.size();
    //      int m=text2.size();
    //      vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    //     //baseCase
    //     for(int ind2=0;ind2<=m-1;ind2++)dp[0][ind2]=0;//ind goes to -ve
    //     for(int ind1=0;ind1<=n-1;ind1++)dp[ind1][0]=0;//ind goes to -ve

    //     for(int ind1=1;ind1<=n;ind1++){
    //         for(int ind2=1;ind2<=m;ind2++){
    //             //match
    //             if(text1[ind1-1]==text2[ind2-1]){
    //                 dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
    //             }
    //             else{
    //                 //no match
    //                 dp[ind1][ind2]=0+max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    // space optimization
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        // baseCase
        for (int ind2 = 0; ind2 <= m - 1; ind2++)
            prev[ind2] = 0;

        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                // match
                if (text1[ind1 - 1] == text2[ind2 - 1])
                {
                    curr[ind2] = 1 + prev[ind2 - 1];
                }
                else
                {
                    // no match
                    curr[ind2] = 0 + max(prev[ind2], curr[ind2 - 1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

// prob link:-https://leetcode.com/problems/longest-common-subsequence/