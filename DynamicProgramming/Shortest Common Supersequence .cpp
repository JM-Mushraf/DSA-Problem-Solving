/*1092. Shortest Common Supersequence 
Solved
Hard
Topics
Companies
Hint
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"*/

// code:-
class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int n = str1.length();
            int m = str2.length();
    
            //LCS Code
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
    
            int i=n,j=m;
            string ans="";
            while(i>0 && j>0){
                //match found
                if(str1[i-1]==str2[j-1]){
                    ans+=str1[i-1];
                    i--;
                    j--;
                }
                //no match found
                else if(dp[i-1][j]>dp[i][j-1]){
                    ans+=str1[i-1];
                    i--;
                }
                else{
                    ans+=str2[j-1];
                    j--;
                }
            }
            //if any remaining chars in s1
            while(i>0){
                ans+=str1[i-1];
                i--;
            }
            //if any remaining chars in s2
            while(j>0){
                ans+=str2[j-1];
                j--;
            }
            //cause we started backward we need to reverse the string
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };

//prob link:-https://leetcode.com/problems/shortest-common-supersequence/