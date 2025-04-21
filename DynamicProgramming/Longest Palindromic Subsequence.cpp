/*
516. Longest Palindromic Subsequence
Solved
Medium
Topics
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/

// code:-
class Solution {
    public:
        // Tabulation Longest Common Subsequence
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
        // space optimization Longest Common Subsequence
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
        int longestPalindromeSubseq(string s) {
            string t=s;
            reverse(t.begin(),t.end());
            return longestCommonSubsequence(s,t);
        }
    };