/*44. Wildcard Matching
Solved
Hard
Topics
Companies
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.*/

// code:-
class Solution
{
public:
    // //Recurssion
    // bool f(int i,int j,string&s1,string&s2){
    //     //base case
    //     if(i<0 && j<0)return true;
    //     if(i<0 && j>=0)return false;
    //     if(j<0 && i>=0){
    //         for(int k=0;k<=i;k++){
    //             if(s1[k]!='*')return false;
    //         }
    //         return true;
    //     }

    //     //match found it can be same char/?/*
    //     if(s1[i]==s2[j] || s1[i]=='?')return f(i-1,j-1,s1,s2);
    //     if(s1[i]=='*'){
    //         return (f(i-1,j,s1,s2) || f(i,j-1,s1,s2));
    //     }
    //     //no match
    //     return false;
    // }
    // bool isMatch(string s, string p) {
    //     // p->s1
    //     // s->s2
    //     int n=p.size();
    //     int m=s.size();
    //     return f(n-1,m-1,p,s);
    // }

    // //Memoization
    // bool f(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
    //     //base case
    //     if(i<0 && j<0)return true;
    //     if(i<0 && j>=0)return false;
    //     if(j<0 && i>=0){
    //         for(int k=0;k<=i;k++){
    //             if(s1[k]!='*')return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     //match found it can be same char/?/*
    //     if(s1[i]==s2[j] || s1[i]=='?')return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    //     if(s1[i]=='*'){
    //         return dp[i][j]=(f(i-1,j,s1,s2,dp) || f(i,j-1,s1,s2,dp));
    //     }
    //     //no match
    //     return dp[i][j]=false;
    // }
    // bool isMatch(string s, string p) {
    //     // p->s1
    //     // s->s2
    //     int n=p.size();
    //     int m=s.size();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return f(n-1,m-1,p,s,dp);
    // }

    // //Memoization str 1 based indexing
    // bool f(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
    //     //base case
    //     if(i==0 && j==0)return true;
    //     if(i==0 && j>0)return false;
    //     if(j==0 && i>0){
    //         for(int k=1;k<=i;k++){
    //             if(s1[k-1]!='*')return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     //match found it can be same char/?/*
    //     if(s1[i-1]==s2[j-1] || s1[i-1]=='?')return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    //     if(s1[i-1]=='*'){
    //         return dp[i][j]=(f(i-1,j,s1,s2,dp) || f(i,j-1,s1,s2,dp));
    //     }
    //     //no match
    //     return dp[i][j]=false;
    // }
    // bool isMatch(string s, string p) {
    //     // p->s1
    //     // s->s2
    //     int n=p.size();
    //     int m=s.size();
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //     return f(n,m,p,s,dp);
    // }

    // // Tabulation
    // bool isMatch(string s, string p) {
    //     // p->s1
    //     // s->s2
    //     int n=p.size();
    //     int m=s.size();
    //     vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));

    //     //base case
    //     dp[0][0]=true;
    //     for(int j=1;j<=m;j++)dp[0][j]=false;
    //     for(int i=1;i<=n;i++){
    //         bool flag=true;
    //         for(int k=1;k<=i;k++){
    //             if(p[k-1]!='*'){
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         dp[i][0]=flag;
    //     }

    //     //loops for changing vars
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             //match found it can be same char/?/*
    //             if(p[i-1]==s[j-1] || p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
    //             else if(p[i-1]=='*'){
    //                 dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
    //             }
    //             //no match
    //             else dp[i][j]=false;
    //         }
    //     }
    //     return dp[n][m];
    // }
    // Space Optimization
    bool isMatch(string s, string p)
    {
        // p->s1
        // s->s2
        int n = p.size();
        int m = s.size();
        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);

        // base case
        prev[0] = true;
        for (int j = 1; j <= m; j++)
            prev[j] = false;
        // for(int i=1;i<=n;i++){
        //     bool flag=true;
        //     for(int k=1;k<=i;k++){
        //         if(p[k-1]!='*'){
        //             flag=false;
        //             break;
        //         }
        //     }
        //     //for every ror oth col were assigning oth column val
        //     curr[0]=flag;
        // }

        // loops for changing vars
        for (int i = 1; i <= n; i++)
        {
            // cur is the current rows col
            // and the curs 0th rows has to be assigned everytime
            bool flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            // for every ror oth col were assigning oth column val
            curr[0] = flag;
            for (int j = 1; j <= m; j++)
            {
                // match found it can be same char/?/*
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    curr[j] = prev[j - 1];
                else if (p[i - 1] == '*')
                {
                    curr[j] = (prev[j] || curr[j - 1]);
                }
                // no match
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};

// prob link:-https://leetcode.com/problems/wildcard-matching/